// Swap vectors
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<char> ONE = {'a', 'b', 'c'}; // 3 chars
  vector<char> TWO = {'d', 'e', 'f', 'g', 'h'}; // 5 chars

  ONE.swap(TWO);

  cout << "ONE contains:";
  for (unsigned i = 0; i <ONE.size(); i++)
    cout << ' ' << ONE[i];
  cout << "\n";

  cout << "TWO contains:";
  for (unsigned i = 0; i <TWO.size(); i++)
    cout << ' ' << TWO[i];

  return 0;
}
