// Swap vectors
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> ONE (3,100); // 3 ints with a value of 100
  vector<int> TWO (5,200); // 5 ints with a value of 200 

  ONE.swap(TWO);

  cout << "ONE contains:";
  for (unsigned i = 0; i <ONE.size(); i++)
    cout << ' ' << ONE[i];

  cout << "TWO contains:";
  for (unsigned i = 0; i <TWO.size(); i++)
    cout << ' ' << TWO[i];

  return 0;
}
