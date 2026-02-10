/* Imani Hollie 02/08/2026
   In-Class Assignment: Create a program that will recieve a number between 2-100.
   The program will tell me if the number is prime or not.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function Prototypes (Modularization)
int generateNumber();
bool isPrime(int n);
void getInput(int num, bool prime);

int main() {  // 1. Program execution starts here
   srand(static_cast<unsigned>(time(nullptr)));
  
   // Call functions (generateNumbers() and isPrime();
   int num = generateNumber();
   bool prime = isPrime(num);
   getInput(num, prime);
  
   return 0;  // End program
}

int generateNumber() { // 2. Program continues here to generate random number
  return rand() % 99 + 2; // Yeilds values from 2 to 100 (inclusive)
}

bool isPrime(int n) { // 3. Program continues here to determine if rand numbers is prime
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

void getInput(int num, bool prime) { // 4. Program continues here to get user input
  // Get user input
  cout << "Is " << num << " a prime number?\n";
  cout << "(1 = Yes; 2 = No): ";

  int answer;
  cin >> answer;

  if (answer != 1 && answer != 2) {
    cout << "ERROR. Invalid Input\n";
    return;
  }

  bool userSaysPrime = (answer == 1);

  if (userSaysPrime == prime)
    cout << "Correct!";
  else
    cout << "Incorrect.";
}
