#include <iostream>
using namespace std;

const int SIZE = 10;

struct Node {
  char n[SIZE];
};

int main() {
  Node node;

  cout << "node.n contains: ";
  for (int i = 0; i < SIZE; i++) {
    node.n[i] = 'A' + i;
    cout << node.n[i] << " ";
  }

  return 0;
}
