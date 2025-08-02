from linked_list import LinkedList

ll = LinkedList()

with open("../test_cases.txt") as f:
    for line in f:
        if line.startswith('#') or not line.strip():
            continue

        command, expected = line.strip().split("->")
        command = command.strip()
        expected = expected.strip()

        if command == "init":
            ll = LinkedList()
            result = ll.to_list()
        elif command.startswith("append"):
            _, val = command.split()
            ll.append(int(val))
            result = ll.to_list()
        elif command.startswith("delete"):
            _, val = command.split()
            ll.delete(int(val))
            result = ll.to_list()
        elif command.startswith("search"):
            _, val = command.split()
            result = str(ll.search(int(val))).lower()
        else:
            print(f"Unknown command: {command}")
            continue

        if str(result) == expected:
            print(f"[PASS] {command} -> {result}")
        else:
            print(f"[FAIL] {command} -> {result} (expected {expected})")
