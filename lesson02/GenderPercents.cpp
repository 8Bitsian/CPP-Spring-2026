/* Imani Hollie 01/30/2026
   Lesson 2 Exmaple: Wtrite a program that asks for the number of males and females registered in a class
   The program should display the percentage of males and females in the class
*/

#include <iostream>   // Allows use of input/output streams (cout, cin)
#include <iomanip>    // Allows use of (fixed, setprecision)
using namespace std;  // Allows use of standard library w/out std:: prefix

int main() {          // Define Method 'main'
   // Declare variables
   int female = 0, male = 0;

   // Utilize while loop to get user input
   while (true) {
     // Get user input
     cout << "How many girls are in your class? ";
     cin >> female;
     cout << "How many boys are in your class?  ";
     cin >> male;

     // Validate input is nonnegative
     if (female > 0 && male > 0) {
       break;
     }
     cout << "ERROR: Invalid Input.\n" << endl;
   }

   // Calcualte total students
   int students = female + male;

   // Validate total is not 0
   if (students == 0) {
     cout << "There are 0 students..." << endl;
     return 0; // End program
   }

   // Calculate percentages
   double fpercent = static_cast<double>(female) / students * 100;
   double mpercent = static_cast<double>(male) / students * 100;
   
   // Output total and percnetages
   cout << "\nOut of " << students << " students:." << endl;
   cout << fixed << setprecision(2);
   cout << "Female: " << fpercent << "%" << endl;
   cout << "Male:   " << mpercent << "%";
   
   return 0; // End program
}
