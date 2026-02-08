/* Imani Hollie 02/08/2026
   Lesson 4 Lab: Write a program that acts as a calculator.
   The program should use a menu that the user can choose an operation:
   - Sum (+), Subtract (-), Product (*), Division (/), Modulus (%), Exit
   The program must create two random numbers and challenge the user to
   enter the correct answer after selecting an option from the menu.
*/

#include <iostream>   // Allows use of input/output streams (cout, cin)
#include <cstdlib>    // Allows use of random generators (rand, srand)
#include <ctime>      // Allows use of seeding rand (time)
#include <iomanip>    // Allows use of (max)
#include <string>     // Allows use of string (getline, string)

using namespace std;  // Allows use of standard library w/out std:: prefix

int main() {          // Define Method 'main'
   // Seed random number generator once per run
   srand(static_cast<unsigned>(time(nullptr)));   // Makes numbers different
   
   // Generate two random numbers
   int num1 = rand() % 1000 + 1;   // Yeilds values from 1 to 1000 (inclusive)
   int num2 = rand() % 1000 + 1;

   // Calculate sum
   int sum = num1 + num2;
      
   // Format output by switching places
   if (num1 < num2) {
      swap (num1, num2);
   }

   // Format output so numbers are right aligned w/width of numbers
   int width = max({
      (int)to_string(num1).size(),
      (int)to_string(num2).size(),
      (int)to_string(sum).size()
   });
   
   // Get user input
   cout << "  " << setw(width) << num1 << endl;
   cout << "+ " << setw(width) << num2 << endl;
   cout << string(width + 2, '-');
   string pause;
   getline(cin, pause);   // Wait for Enter w/out newline

   // Display output
   cout << " " << setw(width) << sum << endl;
   
   return 0; // End program
}
