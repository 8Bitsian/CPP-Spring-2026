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
#include <algorithm> // Allows use of swap() for reording numbers
using namespace std; // Allows use of standard library without std:: prefix

// Function Prototypes (Modularization)
void getRunnerData(string &name, double &time, int count);
void sortAndDisplay(string name1, double time1, string name2, double time2, string name3, double time3);

int main() {  // Program execution starts here
  // Declare variables
  string name1, name2, name3;
  double time1, time2, time3;

  // Get user input and call getRunnerData()
  getRunnerData(name1, time1, 1);
  getRunnerData(name2, time2, 2);
  getRunnerData(name3, time3, 3);

  // Process and output and call sortAndDisplay()
  sortAndDisplay(name1, time1, name2, time2, name3, time3);

  return 0;  // Ends the program
}

// Function to handle input and validation
void getRunnerData(string &name, double &time, int count) {
  // Get user input for name
  cout << "Runner " << count << " Details:" << endl;
  cout << "Enter Runner Name: ";
  getline(cin>> ws, name); // ws skips leftover newlines so names with spaces work

  // Get user input and validate if time is numeric and positive
  while (true) { // While loop repeats until we break
     cout << "Enter Finish Time: ";                       // Get user input
     if (cin >> time && time >= 0.0) break;               // If loop to validate if input is numeric AND positive
     
     cout << "ERROR: Invalid Input" << endl;              // ERROR Message for invalid input
     cin.clear();                                         // Clear the fail state flag
     cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the rest of the line (the bad input)
  }
}

// Function to determine placement and display results
void sortAndDisplay(string n1, double t1, string n2, double t2, string n3, double t3) {
  // Sort by comparing pairs and swapping if out of order
  if (t1 > t2) { swap(t1, t2); swap(n1, n2); } // Compare 1st and 2nd runners
  if (t2 > t3) { swap(t2, t3); swap(n2, n3); } // Compare 2nd and 3rd runners
  if (t1 > t2) { swap(t1, t2); swap(n1, n2); } // Compare 1st and 2nd runners to catch shifts
  
  // Output (formatted name to the left and to 15 char and time to 2 decimal places)
  cout << fixed << setprecision(2);
  cout << "\n***PODIUM***\n";
  cout << "First  : " << left << setw(15) << n1 << " Time  : " << t1 <<endl;
  cout << "Second : " << left << setw(15) << n2 << " Time  : " << t2 <<endl;
  cout << "Third  : " << left << setw(15) << n3 << " Time  : " << t3 <<endl;
}
