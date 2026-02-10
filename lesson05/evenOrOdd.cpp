/* Imani Hollie 02/08/2026
   In-Class Assignment: Create a program that will generate a number between 1-100.
   The program will tell me if the number is odd or even.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function Prototypes (Modularization)
int generateNumber();
bool isOdd(int n);
void getInput(int num, bool isOddFlag);

int main() {  // 1. Program execution starts here
   srand(static_cast<unsigned>(time(nullptr)));
  
   // Call functions (generateNumber() and isOdd();
   int num = generateNumber();
   bool flag = isOdd(num);

   // Get user input
   getInput(num, flag);
  
   return 0;  // End program
}

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
