#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <sstream>

namespace minitest {
	namespace detail {
		inline std::string green(const std::string& msg) {
			return "\033[32m" + msg + "\033[0m";
		}

		inline std::string red(const std::string& msg) {
			return "\033[31m" + msg + "\033[0m"; 
		}
	} // namespace detail

	class TestRunner {
		int total_ = 0;
		int passed_ = 0;

	public:
		void run(const std::string& name, const std::function<void()>& test) {
			++total_;
			try {
				test();
				++passed_;
				std::cout << "[ OK ]" << detail::green(name) << "\n";
			} catch (const std::exception& e) {
				std::cout << "[ FAIL ] " << detail::red(name) << " - " << e.what() << "\n";
			} catch (...) {
				std::cout << "[ FAIL ] " << detail::red(name) << " - unknown exception\n";
			}
		}

		void summary() const {
			std::cout << "\n=== Test Summary ===\n";
			std::cout << "Passed: " << passed_ << "/" << total_; 
			if (passed_ == total_) {
				std::cout << "All tests passed!\n";
			}
			else {
				std::cout << "X Some tests failed\n";
			}
		}
	};

	template <typename T, typename U>
	void assert_equal(const T& expected, const U& actual, const std::string& msg = "") {
		if (!(expected == actual)) {
			std::ostringstream oss;
			oss << "Assertion failed. " << msg << "\nExpected: " << expected << "\nActual: " << actual;
			throw std::runtime_error(oss.str());
		}
	}

	void assert_true(bool condition, const std::string& msg = "Expected true") {
		if (!condition) {
			throw std::runtime_error("Assertion failed. " + msg);
		}		
	}

	void assert_false(bool condition, const std::string& msg = "Expected false") {
		if (condition) {
			throw std::runtime_error("Assertion failed. " + msg);
		}
	}
} // namespace minitest
