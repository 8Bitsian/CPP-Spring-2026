/* Imani Hollie 01/16/2026
   Lesson 1 Lab: Analyze and explain the code line by line to determine its purpose.
   
   Sample Program:
   // This program is ***
   #include <iostream>
   #include <iomanip>
   using namespace std;
   int main() {
     double aaa;
     cout << "Enter ***:";
     cin >> aaa;
     double bbb = (5.0 / 9) * (aaa - 32);
     cout << "aaa" << aaa << " is " << bbb << " in bbb " << endl;
     return 0;
   }
*/

// This program is converting Fahrenheit to Celcius

#include <iostream>   // Allows use of input/output objects like cout and cin
#include <iomanip>    // Allows use of formatting tools (not used in this program)
using namespace std;  // Allows use of standard library without std:: prefix

int main() {          // Program execution starts here
  
  // Declare variable
  double fahrenheit;  // Variable to store Fahrenheit

  // Get temperature
  cout << "Enter temperature: ";  // Prompt asking for the temperature
  cin >> fahrenheit;  // Read user input

  // Declare variable and calculate conversion
  double celsius = (5.0 / 9) * (fahrenheit - 32);  // Variable to store Celsius
  
  // Output temperature conversion
  cout << fahrenheit << " Fahrenheit is " << celsius << " in Celsius " << endl;
  
  return 0; // Ends the program
}
