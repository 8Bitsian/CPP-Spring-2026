#include <iostream>
using namespace std;

const int SIZE = 10;

struct Node {
  int *x;
};

int main() {
  Node node;
  
  int y = 20;
  node.x = &y;

  cout << node.x << endl;
  cout << *node.x << endl;
  
  return 0;
}
