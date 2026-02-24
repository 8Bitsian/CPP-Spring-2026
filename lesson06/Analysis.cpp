/* Imani Hollie 01/16/2026
   Lesson 7 Lab: Write a program that manages a fixed-size numeric array of size N = 10,
   supports creating/loading a data file, loads up to N values into the array, and provides
   analysis operations (min, max, total, average) on the loaded data.
   
   Write a program that has the following:
   1. Global Program Constraints
   2. Student File Format
   3. Functional Requirements
      - Menu System
      - Create File Option
      - Load from File Option
      - Analysis Operations
      - Output Requirements
   4. Modularity Requirements
*/

// Import classes from utility library
#include <iostream>  // Allows use of input/output streams (cout, cin)
#include <iomanip>   // Allows use of formatting tools (fixed, setprecision)
#include <string>    // Allows use of string
#include <limits>    // Allows use of properties and bounds (numeric_limits)
#include <algorithm> // Allows use of swap() for reording numbers

using namespace std; // Allows use of standard library without std:: prefix

// Function Prototypes (Modularization)
int mainMenu(); // Create/Write to data file, Load values from file, Operate on values from file, Delete values from file, exit program
int continueMenu(); // find lowest value, find highest value, compute total value, computer total average, exit to main menu, exit program
void createFile(); // Prompt for a file name to create/overwrite
void loadFile(); // Prompt for a file name to load
void deleteFile(); // Prompt for a file name to delete
void analysisOps(); // Lowest Value, Highest Value, Total Values, Average of Values

int main() {  // Program execution starts here
  // Declare variables
  int option;

  cout << "Choose to  (-1 to Exit).\n" << endl;

  while (true) {
    // Call getNumAccidents() function for each division
    north = getNumAccidents("North");
    south = getNumAccidents("South");
    east = getNumAccidents("East");
    west = getNumAccidents("West");
    central = getNumAccidents("Central");
    
    // Call findLowest() function to calculate and output the lowest accident-prone region
    findLowest(north, south, east, west, central);

    cout << "\n\n=== REPORT COMPLETE. STARTING NEW REPORT ===\n\n";
  }

  return 0;  // Ends the program
}

/* Function mainMenu() prints main menu options:
   - Create a data file
   - Load values from a file
   - Operate on values from a file
   - Delete values from file
   - Exit program
*/
void mainMenu() {
  
} 
void continueMenu(); // find lowest value, find highest value, compute total value, computer total average, exit to main menu, exit program
void createFile(); // Prompt for a file name to create/overwrite
void loadFile(); // Prompt for a file name to load
void deleteFile(); // Prompt for a file name to delete
void analysisOps(); // Lowest Value, Highest Value, Total Values, Average of Values
