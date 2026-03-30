#include <iostream>
using namespace std;

const int SIZE = 10;

struct Node {
  int *x;
};

int main() {
  Node node;
  
  cout << node.x << endl;   // Hexidecimnal address
  cout << *node.x << endl;  // Decimal value
  
  return 0;
}
