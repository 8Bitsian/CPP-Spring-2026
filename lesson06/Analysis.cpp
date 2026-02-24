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
int mainMenu();       // Create/Write to data file, Load values from file, Delete values from file, Create Array, Operate Array, Exit program (-1)
int operationMenu();  // Lowest Value, Highest Value, Total Values, Average of Values within Arrays, Exit to main menu, exit program
int continueMenu();   // Try again, exit to main meny, exit program (-1)

void fileManipulation();
void createFile();    // Method createFile() propmts user to create/overwrite a file
void loadFile();      // Method loadFile() propmts user to load a file
void deleteFile();    // Method deleteFile() propmts user to delete a file

void arrayManipulation();
void createArray();   // Method createArray() propmts user to create a fixed array within a file
void loadArray();     // Method loadArray() propmts user to load a fixed array within a file
void deleteArray();   // Method deleteArray() propmts user to delete fixed array within a file

void analysisOps();   // Method analysisOps() gets the lowest value, highest value, total value or avergae vaule within the arrays
void lowValue();
void highValue();
void totalValue();
void averageValue();

int main() { // Program execution starts here
   // Declare variables
   int option = 0;

   cout << "Choose an option (-1 to Exit).\n" << endl;

   while (option != -1) {
      option = mainMenu();

      switch (option) {
         case 1: fileManipulation(); break;
         case 2: arrayManipulation(); break;
         case 3: analysisOps(); break;
         
         case -1:
            cout << "Exiting program...\n";
            break;
         
         default:
            cout << "ERROR: Invalid Input\n";
      }

      if (option != -1)
         cout << "\n=== REPORT COMPLETE. STARTING NEW REPORT ===\n\n";
   }

   return 0; // Ends the program
}

int mainMenu() {
   int choice;

   cout << "=== MAIN MENU ===\n";
   cout << "1. File Manipulation\n";
   cout << "2. Array Manipulation\n";
   cout << "3. Analysis Operations\n";
   cout << "-1. EXIT PROGRAM\n";

   cout << "Enter Option: \n";
   cin >> choice;

   // Do input validation
   
   return choice;
}

int continueMenu() {
   int choice;

   cout << "=== CONTINUE MENU ===\n";
   cout << "1. Try Again\n";
   cout << "2. Main Menu\n";
   cout << "-1. EXIT PROGRAM\n";

   cout << "Enter Option: \n";
   cin >> choice;

   // Do input validation
   
   return choice;
}
