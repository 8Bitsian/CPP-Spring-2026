#include <iostream>
#include <limits>
using namespace std;

const int NUM_VALUES = 10;

// Function prototypes
void ReplaceNumbers(int* ptr);
int CalcSignOfNums(int num);
int CalcHighOfNums(int a, int b);
void DisplaySumOfNums(int arr[], int size);
void DisplayAvgOfNums(int arr[], int size);

// Safe integer input
int GetInt() {
    int x;
    while (true) {
        cin >> x;
        if (!cin.fail()) return x;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ERROR: Invalid Input - Enter an integer: ";
    }
}

int main() {
    int nums[NUM_VALUES];

    cout << "Enter " << NUM_VALUES << " integers:\n";
    for (int i = 0; i < NUM_VALUES; i++) {
        cout << "Value " << i + 1 << ": ";
        nums[i] = GetInt();
    }

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

        choice = GetInt();
        while (choice < 1 || choice > 6) {
            cout << "Invalid. Enter 1–6: ";
            choice = GetInt();
        }

        switch (choice) {
        case 1: {
            cout << "Enter index (0–9): ";
            int idx = GetInt();
            while (idx < 0 || idx >= NUM_VALUES) {
                cout << "Invalid index. Enter 0–9: ";
                idx = GetInt();
            }
            ReplaceNumbers(&nums[idx]);
            break;
        }

        case 2:
            for (int i = 0; i < NUM_VALUES; i++) {
                int s = CalcSignOfNums(nums[i]);
                cout << nums[i] << " is "
                     << (s > 0 ? "Positive" : s < 0 ? "Negative" : "Zero")
                     << endl;
            }
            break;

        case 3: {
            cout << "Enter first number: ";
            int a = GetInt();
            cout << "Enter second number: ";
            int b = GetInt();
            cout << "Highest: " << CalcHighOfNums(a, b) << endl;
            break;
        }

        case 4:
            DisplaySumOfNums(nums, NUM_VALUES);
            break;

        case 5:
            DisplayAvgOfNums(nums, NUM_VALUES);
            break;

        case 6:
            cout << "Goodbye! Exiting program...\n";
            break;
        }

    } while (choice != 6);

    return 0;
}

// ===== Function Definitions =====
void ReplaceNumbers(int* ptr) {
    cout << "Enter new value: ";
    *ptr = GetInt();
}

int CalcSignOfNums(int num) {
    if (num > 0) return 1;
    if (num < 0) return -1;
    return 0;
}

int CalcHighOfNums(int a, int b) {
    return (a > b) ? a : b;
}

void DisplaySumOfNums(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    cout << "Total: " << sum << endl;
}

void DisplayAvgOfNums(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    cout << "Average: " << (double)sum / size << endl;
}
