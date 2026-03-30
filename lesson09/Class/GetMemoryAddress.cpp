#include <iostream>
using namespace std;

const int SIZE = 10;

struct Node {
  int x = SIZE;
  int *y = &x;
};

int main() {
  Node node;
  cout << node.x << endl;   // Decimal (10)
  cout << &node.x << endl;  // Hexadecimal Value
  cout << node.y << endl;   // Hexadecimal Value
  cout << *node.y << endl;  // Decimal (10)
  return 0;
}
