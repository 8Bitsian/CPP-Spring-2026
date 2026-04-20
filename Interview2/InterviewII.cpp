#include <iostream>
#include <limits>
using namespace std;

const int NUM_VALUES = 10;

/*
  Question 5: Define a struct called "Student" with the fields: "name", "id", and "grade."
  Write a program that creates one student and prints its information.

  Answer:
  A struct allows us to group related variables under one type. The Student struct can
  contain a string for the name, an integer for the ID, and a double or int for the grade.
  After defining the struct, we can create a Student variable, assign values to its fields,
  and print them using cout.
*/

struct Student {
    string name;
    int id;
    double grade;
};

int readInt() {
    int x;
    while (true) {
        if (cin >> x) return x;

        if (cin.eof()) {
            cout << "\nEnd of input detected. Exiting.\n";
            exit(0);
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter an integer: ";
    }
}

void loadNumbers(int arr[]) {
    cout << "Enter " << NUM_VALUES << " integers:\n";
    for (int i = 0; i < NUM_VALUES; i++) {
        cout << "Value " << i + 1 << ": ";
        arr[i] = readInt();
    }
}

/*
  Question 1: Write a C++ Program that reads an integer from the user and prints
  whether the number is positive, negative, or zero.

  Answer:
  To determine whether a number is positive, negative, or zero, we compare it using
  simple if–else statements. If the number is greater than zero, it is positive; if it is
  less than zero, it is negative; and if it equals zero, it is neither. The program reads
  the number using cin and prints the correct category.
*/

int signOf(int n) {
    return (n > 0) - (n < 0);
}

/*
  Question 2: Create a function that receives two integers and returns the larger
  value. How would you call this function from main?

  Answer:
  A function can compare two integers using an if statement or the ternary operator.
  It returns whichever value is greater. To call the function from main, you pass two
  integers as arguments, like maxOf(a, b), and print or store the returned result.
*/

int maxOf(int a, int b) {
    return (a > b) ? a : b;
}

/*
  Question 3: Given an array of integers, write code to find the sum and average of
  its elements. What loop structure would you use and why?

  Answer:
  To compute the sum, we loop through the array and add each element to a running
  total. The average is the total sum divided by the number of elements. A for-loop is
  ideal because the number of iterations is known in advance (the array size), making
  it simple and efficient for indexed access.
*/

int sumOf(const int arr[]) {
    int sum = 0;
    for (int i = 0; i < NUM_VALUES; i++)
        sum += arr[i];
    return sum;
}

/*
  Question 4: What is a pointer in C++? Write a small example where a function uses a
  pointer to modify the value of a variable declared in main().

  Answer:
  A pointer is a variable that stores the memory address of another variable. By
  passing a pointer to a function, the function can directly modify the original variable
  in main. This is known as pass-by-reference using pointers.
*/

void modifyValue(int* p) {
    *p = 999;  // Example modification
}

void menu(int arr[]) {
    while (true) {
        cout << "\n===== MENU =====\n"
             << "1. Replace Value\n"
             << "2. Display Signs of Values\n"
             << "3. Highest of 2 Values\n"
             << "4. Display Total of Array\n"
             << "5. Display Average of Array\n"
             << "6. Exit Program\n"
             << "Choose (1-6): ";

        int choice = readInt();
        if (choice == 6) {
            cout << "Exiting Program...\n";
            break;
        }

        switch (choice) {
            case 1: {
                int idx;
                do {
                    cout << "\nEnter Index (0–9): ";
                    idx = readInt();
                } while (idx < 0 || idx >= NUM_VALUES);

                cout << "Enter Value: ";
                arr[idx] = readInt();
                break;
            }

            case 2:
                cout << endl;
                for (int i = 0; i < NUM_VALUES; i++)
                    cout << "nums[" << i << "] = " << arr[i]
                         << " → sign = " << signOf(arr[i]) << endl;
                break;

            case 3: {
                cout << "\nEnter First Number: ";
                int a = readInt();
                cout << "Enter Second Number: ";
                int b = readInt();
                cout << "Highest Value = " << maxOf(a, b) << endl;
                break;
            }

            case 4:
                cout << "\nTotal Sum = " << sumOf(arr) << endl;
                break;

            case 5:
                cout << "\nAverage = "
                     << static_cast<double>(sumOf(arr)) / NUM_VALUES
                     << endl;
                break;

            default:
                cout << "Invalid choice.\n";
        }
    }
}

int main() {
    // Example for Question 5
    Student s = {"Alice", 12345, 92.5};
    cout << "\nStudent Info:\n";
    cout << "Name: " << s.name << endl;
    cout << "ID: " << s.id << endl;
    cout << "Grade: " << s.grade << endl << endl;

    int nums[NUM_VALUES];
    loadNumbers(nums);
    menu(nums);
    return 0;
}
