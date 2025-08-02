#include <iostream>
#include "../../node.h"

using namespace std;

int main() {

  Node<int>* newNode = Node(10);

  cout << newNode->getData() << endl;

  delete newNode;

  return 0;
}
