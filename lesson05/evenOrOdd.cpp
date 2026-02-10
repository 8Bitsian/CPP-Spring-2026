/* Imani Hollie 02/08/2026
   In-Class Assignment: Create a program that will generate a number between 1-100.
   The program will tell me if the number is odd or even.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function Prototypes (Modularization)
void menu();
void continueMenu(bool &repeatOperation, bool &exitProgram);
int generateNumber();
bool isOdd(int n);
void getInput(int num, bool isOddFlag);

int main() {  // 1. Program execution starts here
   srand(static_cast<unsigned>(time(nullptr)));
   menu(); // Call menu() function
   return 0;  // End program
}

void menu() {
   bool exitProgram = false;
   
   while (!exitProgram) {
      cout << "\n=== Even or Odd Game ===\n";
      cout << "1. Play Game\n";
      cout << "2. EXIT\n";
      cout << "Choose an option: ";
      int choice;
      cin >> choice; 
      
      switch (choice) {
         case 1: {
            bool repeatOperation = true;
            while (repeatOperation && !exitProgram) {
               int num = generateNumber();
               bool flag = isOdd(num);
               getInput(num, flag);
               continueMenu(repeatOperation, exitProgram);
            }
            break;
         }
         case 2:
            exitProgram = true;
            break;
         default:
            cout << "Invalid choice. Try again.\n";
      }
   } cout << "\nExiting program...\n";
}

void continueMenu(bool &repeatOperation, bool &exitProgram) { int choice = 0; cout << "\n\n=== Menu ===\n"; cout << "1. Try Again\n"; cout << "2. Return to Main Menu\n"; cout << "3. EXIT\n"; cout << "Choose an option: "; cin >> choice; switch (choice) { case 1: repeatOperation = true; break; case 2: repeatOperation = false; break; case 3: exitProgram = true; break; default: cout << "ERROR: Invalid Input. Returning to Main Menu.\n"; repeatOperation = false; } }

int generateNumber() { // 2. Generate random number
  return rand() % 100 + 1; // Yeilds values from 1 to 100 (inclusive)
}

bool isOdd(int n) { // 3. Determine if rand number is odd or even
  return (n % 2 != 0);
}

void getInput(int num, bool isOddFlag) { // 4. Get user input
  // Get user input
  cout << "Is " << num << " odd or even?\n";
  cout << "(1 = Odd; 2 = Even): ";

  int answer;
  if (!(cin >> answer)) {
    cout << "ERROR. Invalid Input.\n";
    return;
  }

  if (answer != 1 && answer != 2) {
    cout << "ERROR. Invalid Input\n";
    return;
  }

  bool userSaysSign = (answer == 1);

  if (userSaysSign == isOddFlag)
    cout << "Correct!";
  else
    cout << "Incorrect.";
}
