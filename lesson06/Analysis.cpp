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
int mainMenu(); // Create/Write to data file, Load values from file, Delete values from file, Create Array, Operate Array, Exit program (-1)
int operationMenu(); // // Lowest Value, Highest Value, Total Values, Average of Values within Arrays, Exit to main menu, exit program
int continueMenu(); // Try again, exit to main meny, exit program (-1)

void createFile(); // Prompt for a file name to create/overwrite
void loadFile(); // Prompt for a file name to load
void deleteFile(); // Prompt for a file name to delete

// Method createFile() propmts user to create a dynamic array within a file
void createArray() {}
// Method createFile() propmts user to load a dynamic array within a file
void loadArray() {}
// Method createFile() propmts user to delete dynamic array within a file
void deleteArray() {}

// Lowest Value, Highest Value, Total Values, Average of Values within Arrays
void analysisOps();

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

/* Method mainMenu() prints main menu options:
   - Create a data file
   - Load values from a file
   - Operate on values from a file
   - Delete values from file
   - Exit program
*/
void mainMenu() {
  
}

/* Method continueMenu() prints continue menu options:
   - Try again
   - Exit to main menu
   - Exit program
*/
void continueMenu() {
   
}

// Method createFile() propmts user for a file name to create/overwrite
void createFile() {
   
}

// Method loadFile() propmts user for a file name to load
void loadFile() {
   
}

// Method deleteFile() propmts user for a file name to delete
void deleteFile() {
   
}

// Method createFile() propmts user to create a dynamic array within a file
void createArray() {
   
}
// Method createFile() propmts user to load a dynamic array within a file
void loadArray() {
   
}
// Method createFile() propmts user to delete dynamic array within a file
void deleteArray() {
   
}

// Method analysisOps() propmts user to choose 
void analysisOps(); // Lowest Value, Highest Value, Total Values, Average of Values
