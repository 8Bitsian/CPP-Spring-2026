/* Imani Hollie 01/16/2026
   Lesson 1 Lab: Write a code to produce a similar output to the sample output.
   Use the following variable names:
   myName: User's name
   myAge: User's age
   pi = 3.141592

   Sample Output:
   A. ===========================
   Name : ***
   Age : 20
   Pi : 3.141592

   B. ===========================
   My name is *** and I am 20 years old.
   Pi : 3.141592
   Pi :  3.14159
   Pi :   3.1415
   Pi :    3.141
   Pi :     3.14
   Pi :      3.1
*/

#include <iostream>  // Allows use of input/output objects like cout and cin
#include <string>    // Allows use of the string data type
#include <iomanip>   // Allows use of formatting tools (not used in this program)
#include <cstdio>    // Allows C-style printing functions like printf
using namespace std; // Allows use of standard library without std:: prefix

int main() {  // Program execution starts here
  
  // Declare variables
  string myName;
  short myAge;
  const double PI = 3.141592;  // Variable is a constant

  // Get user input
  cout << "Name: ";
  cin.ignore();
  getline(cin, myName);

  cout << "Age : ";
  cin >> myAge;

  // Validate age is 3 digits
  while (myAge < 0 || myAge > 151) {                 // While loop that ensures the number is between 0 and 151
    cout << "ERROR: Invalid Input\nAge : " << endl;  // Error message for invalid input and prompt user to try again
    cin >> myAge;                                    // Reads new input
  }
  
  // Output
  cout << "My name is " << myName
       << " and I am " << myAge << " years old." << endl;

  short precision = 6 // Start with 6 digits after the decimal
  short spaces = 0;   // Start with no indentation
  while (precision >= 1) {
    printf("Pi : %*.*f\n", spaces + 1, precision, PI); // Dynamic formatting specifier
    precision--;  // Reduce precision each loop
    spaces++;     // Increase indentation each loop
  }
  
  return 0;  // Ends the program
}
