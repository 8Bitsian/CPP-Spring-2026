/* Imani Hollie 01/16/2026
   Lesson 2 Lab: Write a program that can be used as a tutor.
   The program should display two random numbers to be added
   - Display two randomly generated numbers less than or equal to 100
   - Pause and calculate the total of those two numbers
   - Prompt the student to press enter to see the solution
   - Display the solution to the problem
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
   int num1 = rand() % 100 + 1;   // Yeilds values from 1 to 100 (inclusive)
   int num2 = rand() % 100 + 1;

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
