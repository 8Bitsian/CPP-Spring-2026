/*
  Imani Hollie 04/13/2026
  Menu-Drivn Progam to Display ASII Values
  Directions: Create a menu-driven program that allows the user to select between displaying uppercase letters, lowercase letters, or xiting the program
  The program must be able to:
  - Display the vfollowing menu:
    - 1. Uppercase Letter (Call DisplayUppercaseASCII() to display uppercase letters (A-Z) with ASCII values
    - 2. Lowercase Letter (Call DisplayLowercaseASCII() to display lowercase letters (a-z) with ASCII values
    - 3. EXIT PROGRAM (Terminate the program)
  - The user must select an option from the menu
  - The program must continue until the user slects the EXIT option
  - Each function must display one letter and its ASCII value per line

  Sample Output:
  A = 65
  B = 66
  ...
  Z = 90
*/

#include <iostream>
using namespace std;

void DisplayUppercaseASCII();
void DisplayLowercaseASCII();

// 1. Program execution starts here
int main() {
  // 1.1 Declare and initialize choice
  int choice = 0;

  // 1.2 Loop until user chooses EXIT
  while (choice != 3) {
    // 1.3 Display menu
    cout << "\n===== ASCII MENU =====\n";
    cout << "1. Uppercase Letters (A-Z)\n";
    cout << "2. Lowercase Letters (a-z)\n";
    cout << "3. Exit Program\n";

    // 1.4 Get user input
    cout << "\nEnter Choice: ";
    cin >> choice;

    switch (choice) {
      case 1: DisplayUppercaseASCII(); break;
      case 2: DisplayLowercaseASCII(); break;
      case 3: cout << "Exiting program...\n"; break;
      default: cout << "ERROR: Invalid Input - Enter a digit (1-3)...\n";
    }
  }

  return 0;
}

// 2. Display uppercase letters (A-Z) with ASCII values
void DisplayUppercaseASCII() {
  for (char c = 'A'; c <= 'Z'; c++) {
    cout << c << " = " << int(c) << endl;
  }
}

// 3. Display lowercase letters (a-z) with ASCII values
void DisplayLowercaseASCII() {
  for (char c = 'a'; c <= 'z'; c++) {
    cout << c << " = " << int(c) << endl;
  }
}
