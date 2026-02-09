/* Imani Hollie 02/08/2026
   Lesson 4 Lab: Write a program that acts as a calculator.
   The program should use a menu that the user can choose an operation:
   - Sum (+), Subtract (-), Product (*), Division (/), Modulus (%), Exit
   The program must create two random numbers and challenge the user to
   enter the correct answer after selecting an option from the menu.
   - Implement multiplication where one of the factors is one digit and the other is up to two digits
   - Implement subtraction where the user;s answer is only positive. Use up to two digits
   - Implement modulus operation, numbers must be up to two digits
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Function Prototypes (Modularization)
void menu();
void continueMenu(bool &repeatOperation, bool &exitProgram);
void addition();
void subtraction();
void multiplication();
void division();
void modulusOp();

int main() { // 1. Program execution starts here
   srand(static_cast<unsigned>(time(nullptr)));
   menu();   // Call menu()
   return 0; // End program
}

void menu() { // 2. Program execution is called here and exits to main()
   // Declare and initialize variables
   int option = 0;
   
   // Get user input while option is not 6
   do {
      cout << "\n=== Calculator ===\n";
      cout << "1. (+) Addition\n";
      cout << "2. (-) Subtraction\n";
      cout << "3. (*) Multiplication\n";
      cout << "4. (/) Division\n";
      cout << "5. (%) Modulus\n";
      cout << "6. EXIT\n";
      cout << "\nChoose an option: ";
      cin >> option;

      switch (option) {
         case 1: addition(); break;
         case 2: subtraction(); break;
         case 3: multiplication(); break;
         case 4: division(); break;
         case 5: modulusOp(); break;
         case 6: cout << "Exiting Program...\n"; break;
         default: cout << "ERROR: Invalid Input\n";
      }
   } while (option != 6);
}

// 3. Program execution is called here after operation and exits to main()
void continueMenu(bool &repeatOperation, bool &exitProgram) { 
   // Declare and initialize variables
   int choice = 0;
   
   cout << "\n=== Menu ===\n";
   cout << "1. Try Again\n";
   cout << "2. Return to Main Menu\n";
   cout << "3. EXIT\n";
   cout << "\nChoose an option: ";
   cin >> choice;

   switch (choice) {
      case 1: repeatOperation = true; break;
      case 2: repeatOperation = false; break;
      case 3: exitProgram = true; break;
      default:
         cout << "ERROR: Invalid Input. Returning to Main Menu.\n";
         repeatOperation = false;
   }
}

void addition() {
   bool repeat = false;
   bool exitProgram = false;

   do {
      // Generate two random numbers
      int num1 = rand() % 100 + 1; // Yeilds values from 1 to 100 (inclusive)
      int num2 = rand() % 100 + 1;
      int answer;

      // Format output by switching places
      if (num1 < num2) { swap (num1, num2); }
   
      // Calculate sum
      int sum = num1 + num2;

      // Format output so numbers are right aligned w/width of numbers
      int width = max({
         (int)to_string(num1).size(),
         (int)to_string(num2).size(),
         (int)to_string(sum).size()
      });
   
      // Get user input
      cout << "\n=== Addition ===\n";
      cout << "  " << setw(width) << num1 << endl;
      cout << "+ " << setw(width) << num2 << endl;
      cout << string(width + 2, '-') << endl;
      cin >> answer;

      // Display output
      if (answer == sum)
         cout << "Correct!\n";
      else
         cout << "Incorrect.\nThe answer is " << sum << endl;

      // Call continueMenu()
      continueMenu(repeat, exitProgram);
      if (exitProgram)
         exit(0);
      
   } while (repeat);
}

void subtraction() {
   bool repeat = false;
   bool exitProgram = false;

   do {
      // Generate two random numbers
      int num1 = rand() % 100 + 1; // Yeilds values from 1 to 100 (inclusive)
      int num2 = rand() % 100 + 1;
      int answer;
   
      // Format output by switching places
      if (num1 < num2) { swap (num1, num2); }

      // Calculate product
      int sum = num1 - num2;

      // Format output so numbers are right aligned w/width of numbers
         int width = max({
         (int)to_string(num1).size(),
         (int)to_string(num2).size(),
         (int)to_string(sum).size()
      });
   
      // Get user input
      cout << "\n=== Subtraction ===\n";
      cout << "  " << setw(width) << num1 << endl;
      cout << "- " << setw(width) << num2 << endl;
      cout << string(width + 2, '-') << endl;
      cin >> answer;

      // Display output
      if (answer == sum)
         cout << "Correct!\n";
      else
         cout << "Incorrect.\nThe answer is " << sum << endl;
      
      // Call continueMenu()
      continueMenu(repeat, exitProgram);
      if (exitProgram)
         exit(0);
      
   } while (repeat);
}

void multiplication() {
   bool repeat = false;
   bool exitProgram = false;

   do {
      // Generate two random numbers
      int num1 = rand() % 9 + 1;   // Yeilds values from 1 to 9 (inclusive)
      int num2 = rand() % 90 + 10; // Yeilds values from 10 to 99 (inclusive)
      int answer;

      // Calculate product
      int sum = num1 * num2;

      // Format output so numbers are right aligned w/width of numbers
      int width = max({
         (int)to_string(num1).size(),
         (int)to_string(num2).size(),
         (int)to_string(sum).size()
      });
   
      // Get user input
      cout << "\n=== Multiplication ===\n";
      cout << "  " << setw(width) << num2 << endl;
      cout << "x " << setw(width) << num1 << endl;
      cout << string(width + 2, '-') << endl;
      cin >> answer;

      // Display output
      if (answer == sum)
         cout << "Correct!\n";
      else
         cout << "Incorrect.\nThe answer is " << sum << endl;

      // Call continueMenu()
      continueMenu(repeat, exitProgram);
      if (exitProgram)
         exit(0);
      
   } while (repeat);
}

void division() {
   bool repeat = false;
   bool exitProgram = false;

   do {
      // Generate two random numbers
      int num1 = rand() % 9 + 1;           // Yeilds values from 1 to 9 (inclusive) (avoids zero division)
      int num2 = num1 * (rand() % 12 + 1); // Yeilds ensures clean division
      int answer;

      // Calculate dividend
      int sum = num2 / num1;

      // Format output so numbers are right aligned w/width of numbers
      int width = max({
         (int)to_string(num2).size(),
         (int)to_string(num1).size(),
         (int)to_string(sum).size()
      });
   
      // Get user input
      cout << "\n=== Division ===\n";
      cout << "  " << setw(width) << num2 << endl;
      cout << "÷ " << setw(width) << num1 << endl;
      cout << string(width + 2, '-') << endl;
      cin >> answer;

      // Display output
      if (answer == sum)
         cout << "Correct!\n";
      else
         cout << "Incorrect.\nThe answer is " << sum << endl;
      
      // Call continueMenu()
      continueMenu(repeat, exitProgram);
      if (exitProgram)
         exit(0);
      
   } while (repeat);
}

void modulusOp() {
   bool repeat = false;
   bool exitProgram = false;

   do {
      // Generate two random numbers
      int num1 = rand() % 100 + 1;
      int num2 = rand() % 99 + 1; // Avoids zero
      int answer;
   
      // Calculate product
      int sum = num1 % num2;
   
      // Format output so numbers are right aligned w/width of numbers
      int width = max({
         (int)to_string(num1).size(),
         (int)to_string(num2).size(),
         (int)to_string(sum).size()
      });
      
      // Get user input
      cout << "\n=== Modulus ===\n";
      cout << "  " << setw(width) << num1 << endl;
      cout << "% " << setw(width) << num2 << endl;
      cout << string(width + 2, '-') << endl;
      cin >> answer;

      // Display output
      if (answer == sum)
         cout << "Correct!\n";
      else
         cout << "Incorrect.\nThe answer is " << sum << endl;

      // Call continueMenu()
      continueMenu(repeat, exitProgram);
      if (exitProgram)
         exit(0);
      
   } while (repeat);
}
