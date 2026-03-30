#include <iostream>
using namespace std;

const int SIZE = 11;

struct Node {
  char n[SIZE];
};

int main() {
  Node node;
  
  for (int i = 0; i < SIZE; i++)
    node.n[i] = 'A' + i;
  
  cout << "node.n contains: " << node.n << endl;

  return 0;
}
