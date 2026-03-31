#include <iostream>
using namespace std;

const int SIZE = 10;

struct Node {
  char n[SIZE];
};

int main() {
  Node node;
  Node *pntToNode = &node;
  pntToNode -> n[0] = 'A';
  
  cout << pntToNode -> n[0];
  
  return 0;
}
