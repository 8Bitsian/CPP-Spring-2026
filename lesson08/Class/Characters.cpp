#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
  char ch1 = 'A' + 1; // ASCII value 'A' is 65, so 65 + 1 is 66
  cout << ch1;        // Prints 66

  // Print alphabet A-Z
  char ch2 = 'A';                  // Start at ASCII value 65 ('A')
  for (int i = 0; i < 26; i++)     // Loop 26 times (26 letters in the alphabet)
    cout << char(ch2 + i) << " ";  // Cast char onto (letter + i)
  cout << endl;                    // Print newline
  
  // Print alphabet Z-A
  char ch3 = 'Z';                  // Start at ASCII value 90 ('Z')
  for (int i = 0; i < 26; i++)
    cout << char(ch3 + i) << " ";
  cout << endl;

  // Print alphabet z-a
  char ch4 = 'z';                  // Start at ASCII value 122 ('z')
  for (int i = 0; i < 26; i++)
    cout << char(ch4 + i) << " ";
  cout << endl;

  // Print alphabet a-z
  char ch5 = 'a';                  // Start at ASCII value 97 ('a')
  for (int i = 0; i < 26; i++)
    cout << char(ch5 + i) << " ";
  cout << endl;

  char ch6;
  string str("lm*#pqr@AB");
  for (int i = 0; i < str.length(); i++)
    cout << str.ispunct(i) << " ";
  cout << endl;

  int count = 0;
  string str("lm*#pqr@AB");
  for (int i = 0; i < str.length(); i++)
      if (ispunct(str.at(i))) {
          count += 1;
  cout << count;
  
  return 0;  // Signal end of program
}
