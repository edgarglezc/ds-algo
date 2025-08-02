#pragma once

template <class T>
class Node {
private:
  Node* next_;
  T data_;

public:
  Node(cons T& data) : next_(nullptr), data_(data) { }
  Node(const T& data, Node* next) : next_(next), data_(data) { }
};
