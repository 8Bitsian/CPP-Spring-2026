/* 
  Imani Hollie 02/16/2026
  Programming Exercise: Display Functions
  Design a program that calls the following functions:
  - void displayChar(string make, stringmodel, int year, double price);
  - int calculateCarAge(int currentYear, int carYear);
*/

#include <iostream>
#include <string>

using namespace std;

// Function Prototypes
void displayChar(string make, string model, int year, double price);
int calculateCarAge(int currentYear, int carYear);

// main()
int main() {
  // Declare variables
  string make, model;
  int year;
  double price;

  // Get user input
  cout << "Enter the car make: ";
  cin >> make;
  cout << "Enter the car model: ";
  cin >> model;
  cout << "Enter the car year: ";
  cin >> year;
  cout << "Enter the car price: ";
  cin >> price;
  
  // Call functions
  displayChar(make, model, year, price)
  int age = calculateCarAge(2026, year) // example current year
  cout << "Car age: " << age << " years\n";

  return 0;
}

// displayChar()
void displayChar(string make, stringmodel, int year, double price) {
  // Display the make, model, year, and price of the car
  cout << "\nCar Information:\n";
  cout << "Make: " << make << endl;
  cout << "Model: " << model << endl;
  cout << "Year: " << year << endl;
  cout << "Price: $" << price << endl;
}

// calculateCarAge()
int calculateCarAge(int currentYear, int carYear) {
  int time = currentYear - carYear
  return time;
}
