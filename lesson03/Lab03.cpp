/* Imani Hollie 01/16/2026
   Lesson 3 Lab: Write a program that can be used as a tutor.
   The program should display two random numbers to be added
   - Display two randomly generated numbers less than or equal to 1000
   - Pause and calculate the total of those two numbers
   - Prompt the student to press enter to see the solution
   - Display the solution to the problem
*/

#include <iostream>
#include <cstdlib>   // For rand(), srand()
#include <ctime>     // For time()
#include <limits>    // For numeric_limits

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate two random numbers (0–1000)
    int num1 = rand() % 1001;
    int num2 = rand() % 1001;

    // Display the problem
    cout << "Add the following numbers:\n";
    cout << "  " << num1 << endl;
    cout << "+ " << num2 << endl;
    cout << "-----" << endl;

    // Pause for Enter
    cout << "Press ENTER to see the answer...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    cin.get(); // Wait for Enter

    // Display the solution
    int total = num1 + num2;
    cout << "\nThe answer is: " << total << endl;

    return 0;
}
