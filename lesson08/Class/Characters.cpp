#include <iostream>
#include <string>
using namespace std;

int main() {
  char ch = 'A' + 1; // ASCII value 'A' is 65, so 65 + 1 is 66
  cout << ch;        // Prints 66

  char letter = 'A';                  // Start at ASCII value 65 ('A')
  for (int i = 0; i < 26; i++)        // Loop 26 times (26 letters in the alphabet)
    cout << char(letter + i) << " ";  // Cast char onto (letter + i)
  
  return 0;  // Signal end of program
}
