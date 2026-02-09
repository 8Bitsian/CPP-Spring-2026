/* Imani Hollie 01/16/2026
   Lesson 3 Lab: Write a program that asks for the names of three runners
   and the time it took each to finish a race. The program should display
   who came first, second, and third place.
   - Input Validation: Only accept positive numbers for the times
   - Modularize the program
*/

#include <iostream>  // Allows use of input/output streams (cout, cin)
#include <iomanip>   // Allows use of formatting tools (fixed, setprecision)
#include <string>    // Allows use of string
#include <limits>    // Allows use of properties and bounds (numeric_limits)
#include <algorithm> // Allows use of _ (swap)
using namespace std; // Allows use of standard library without std:: prefix

// Function Prototypes (Modularization)
void getRunnerData(string &name, double &time);
void sortAndDisplay(string name1, double time1, string name2, double time2, string name3, double time3);

int main() {  // Program execution starts here
  // Declare variables
  string name1, name2, name3;
  double time1, time2, time3;

  // Get user input and call getRunnerData()
  cout << "Runner 1 Details:" << endl;
  getRunnerData(name1, time1);
  cout << "Runner 2 Details:" << endl;
  getRunnerData(name2, time2);
  cout << "Runner 3 Details:" << endl;
  getRunnerData(name3, time3);

  // Process and output and call sortAndDisplay()
  sortAndDisplay(name1, time1, name2, time2, name3, time3);

  return 0;  // Ends the program
}

// Function to handle input and validation
void getRunnerData(string &name, double &time) {
  // Get user input for name
  cout << "Enter Runner Name: ";
  getline(cin, name);

  // Get user input and validate if time is numeric and positive
  while (true) { // While loop repeats until we break
     cout << "Enter Finish Time: ";                       // Get user input
     if (cin >> time && time >= 0.0) break;           // If loop to validate if input is numeric AND positive
     
     cout << "ERROR: Invalid Input" << endl;              // ERROR Message for invalid input
     cin.clear();                                         // Clear the fail state flag
     cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the rest of the line (the bad input)
  }
}

// Function to determine placement and display results
void sortAndDisplay(string name1, double time1, string name2, double time2, string name3, double time3) {
  // Compare 1st and 2nd runners
  if (time1 > time2) {
    swap(time1, time2);
    swap(name1, name2);
  }
  // Compare 2nd and 3rd runners
  if (time2 > time3) {
    swap(time2, time3);
    swap(name2, name3);
  }
  // Compare 1st and 2nd runners to catch shifts
  if (time1 > time2) {
    swap(time1, time2);
    swap(name1, name2);
  }
  
  // Output (formatted to 2 decimal places)
  cout << fixed << setprecision(2);
  cout << "\n***PODIUM***\n";
  cout << "First  : " << name1 << " Time  : " << time1 <<endl;
  cout << "Second : " << name2 << " Time  : " << time2 <<endl;
  cout << "Third  : " << name3 << " Time  : " << time3 <<endl;
}
