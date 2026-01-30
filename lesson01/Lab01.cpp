/* Imani Hollie 01/16/2026
   Lesson 2 Lab: Write a code to produce a restaurant bill.
   - Prompt the user to enter the meal charge
   - Calculate the tax (6.75% of the meal cost)
   - Add the tax and charge to get the subtotal
   - Calculate the tip (20% of the subtotal)
   - Calculate the total bill by adding the tip
   Display the meal cost, tax amount, tip amount, and total bill.
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
  cout << "\n***Bill************\n";
  cout << "Charge   : $" << charge   << endl;
  cout << "Tax      : $" << tax      << endl;
  cout << "Subtotal : $" << subtotal << endl;
  cout << "Tip      : $" << tip      << endl;
  cout << "Total    : $" << total    << endl;
  
  return 0;  // Ends the program
}
