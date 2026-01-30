/* Imani Hollie 01/16/2026
   Lesson 2 Lab: Write a program that can be used as a tutor.
   The program should display two random numbers to be added
   - Display two randomly generated numbers less than or equal to 100
   - Pause and calculate the total of those two numbers
   - Prompt the student to press enter to see the solution
   - Display the solution to the problem
*/

#include <iostream>  // Allows use of input/output streams (cout, cin)
#include <iomanip>   // Allows use of formatting tools (fixed, setprecision)
#include <limits>    // Allows use of properties and bounds (numeric_limits)
using namespace std; // Allows use of standard library without std:: prefix

int main() {  // Program execution starts here
  // Declare constants
  const double TAX_RATE = 0.0675; // 6.75%
  const double TIP_RATE = 0.20; // 20%
   
  // Declare and initialize variables
  double charge = 0.0, tax = 0.0, subtotal = 0.0, tip = 0.0, total = 0.0;
  
  // Get user input and validate if charge is numeric and positive
  while (true) { // While loop repeats until we break
     cout << "Enter Price of Meal: $";                    // Get user input
     if (cin >> charge && charge >= 0.0) break;           // If loop to validate if input is numeric AND positive
     
     cout << "ERROR: Invalid Input" << endl;              // ERROR Message for invalid input
     cin.clear();                                         // Clear the fail state flag
     cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the rest of the line (the bad input)
  }

  // Calculate prices
  tax = charge * TAX_RATE; // (6.75% of charge)
  subtotal = tax + charge;
  tip = subtotal * TIP_RATE; // (20% of subtotal)
  total = subtotal + tip;

  // Output (formatted to 2 decimal places)
  cout << fixed << setprecision(2);
  cout << "  " << num1 << endl;
  cout << "+ " << num2 << endl;
  cout << "-----" << endl;
  cout << "  " << total << endl;
  
  return 0;  // Ends the program
}
