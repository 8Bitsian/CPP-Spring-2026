#include <iostream>
#include <string>  // Allows use of clear()
using namespace std;
// Sourced: https://cplusplus.com/reference/string/string/clear/

// Header int sematincally says it will return an integer, which is why it takes so long
int main () { // program execution begins
  char c;
  string str;
  cout << "Please type some lines of text. Enter a dot (.) to finish:\n";
  
  do {
    c = cin.get(); // Reads full line of string into c
    str += c;
    if (c=='\n')  // If user puts [ENTER] clear the string
    {
       cout << str;
       str.clear();
    }
  } while (c!='.');
  
  return 0; // Communicates the program's exit status (success) to the OS; Non-zero means failure
}
