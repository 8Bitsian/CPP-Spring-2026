#include <iostream>
#include <limits>
using namespace std;

const int NUM_VALUES = 10;

// ===== GLOBAL ARRAY =====
int nums[NUM_VALUES];

// ===== FUNCTION PROTOTYPES =====
int ReadValidatedInt();
void LoadInitialNumbers();
void mainMenu();
void ReplaceNumbers(int* ptr);
int CalcSignOfNums(int num);
int CalcHighOfNums(int a, int b);
void DisplaySumOfNums(int arr[], int size);
void DisplayAvgOfNums(int arr[], int size);

// ===== INPUT VALIDATION FUNCTION =====
int ReadValidatedInt() {
    int value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter an integer: ";
    }
    return value;
}

// ===== FUNCTION DEFINITIONS =====

// Reads initial values into the global array
void LoadInitialNumbers() {
    cout << "Enter " << NUM_VALUES << " integers:\n";
    for (int i = 0; i < NUM_VALUES; i++) {
        cout << "Value " << i + 1 << ": ";
        nums[i] = ReadValidatedInt();
    }
}

// Displays the menu and handles all user choices
void mainMenu() {
    int choice;

    do {
        cout << "\n===== MENU =====\n"
             << "1. Replace Value\n"
             << "2. Display Signs\n"
             << "3. Highest of Two Numbers\n"
             << "4. Display Total\n"
             << "5. Display Average\n"
             << "6. Exit\n"
             << "Choose (1–6): ";

        choice = ReadValidatedInt();
        while (choice < 1 || choice > 6) {
            cout << "Invalid. Enter 1–6: ";
            choice = ReadValidatedInt();
        }

        switch (choice) {
        case 1: {
            cout << "Enter index (0–9): ";
            int idx = ReadValidatedInt();
            while (idx < 0 || idx >= NUM_VALUES) {
                cout << "Invalid index. Enter 0–9: ";
                idx = ReadValidatedInt();
            }
            ReplaceNumbers(&nums[idx]);
            break;
        }

        case 2:
            for (int i = 0; i < NUM_VALUES; i++) {
                int s = CalcSignOfNums(nums[i]);
                cout << "nums[" << i << "] = " << nums[i]
                     << " → sign = " << s << endl;
            }
            break;

        case 3: {
            cout << "Enter first number: ";
            int a = ReadValidatedInt();
            cout << "Enter second number: ";
            int b = ReadValidatedInt();
            cout << "Highest = " << CalcHighOfNums(a, b) << endl;
            break;
        }

        case 4:
            DisplaySumOfNums(nums, NUM_VALUES);
            break;

        case 5:
            DisplayAvgOfNums(nums, NUM_VALUES);
            break;

        case 6:
            cout << "Exiting...\n";
            break;
        }

    } while (choice != 6);
}
