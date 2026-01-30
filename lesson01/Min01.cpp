/* Imani Hollie 01/16/2026
   5-Minute Challenge: Write a program that takes user input for a name
   and the last 4 digits of a phone number from the keyboard,
   then prints them to the console.
   
   Sample Output:
   Name? Imani Hollie
   Last 4-digit phone number? ****
   Your name: Imani Hollie
   Last 4-digit phone number: ****
*/

#include <iostream>     // Allows use of input/output streams (cout, cin)
#include <string>       // Allows use of string data type and related functions (size() and find_first_not_of())
using namespace std;    // Allows use of standard library w/out std:: prefix

int main() {            // Program execution entry point
  
  // Declare variables
  string name, phone;   // Variable to store user's name and phone number

  // Get user's name
  cout << "Name? ";     // Prompt asking for user's name (w/out a newline)
  getline(cin, name);   // Reads full line (allows spaces in the name)

  // Get user's last 4-digits of phone number
  do {                                        // Do-While loop validates the number is 4-digits
    cout << "Last 4-digit phone number? ";    // Prompt asking for the user's phone (w/out a newline)
    cin >> phone;                             // Reads the keyboard input (doesn't allow spaces)
  } while (                                   // Repeat while input is invalid:
    phone.size() != 4 ||                      // - Wrong length (not 4 char)
		phone.find_first_not_of("0123456789") // - Contains non-digits using the find_first_not_of()...
    != string::npos);                         //   ... returns npos (no position) if nothing is found
  
  // Output user's name and last 4-digit phone number
  cout << "Your name: " << name << endl;                  // Prints user's name to the console
  cout << "Last 4-digit phone number: " << phone << endl; // Print's user's phone to the console

  return 0; // Ends the program if successful
}
