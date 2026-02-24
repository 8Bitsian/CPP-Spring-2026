/*
  Imani Hollie 02/23/2026
  In-Class Assignment: Array Template
  Write a program that creates an array and a vector with even numbered elements
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Function Prototypes
int mainMenu();
int continueMenu();
void createFixedArray();
void createDynamicArray();

int main() {
    int choice;

    cout << "Choose to create a fixed or dynamic array (-1 to Exit).\n";

    do {
        choice = mainMenu();

        switch (choice) {
            case 1:
                do {
                    createFixedArray();
                } while (continueMenu() == 2);
                break;

            case 2:
                do {
                    createDynamicArray();
                } while (continueMenu() == 2);
                break;

            case -1:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "ERROR: Invalid Input - Try Again.\n";
        }

    } while (choice != -1);

    return 0;
}

// =======================
// MAIN MENU
// =======================
int mainMenu() {
    int choice;

    cout << "\n=== MAIN MENU ===\n";
    cout << "1. Create Fixed Array\n";
    cout << "2. Create Dynamic Array\n";
    cout << "-1. EXIT\n";
    cout << "Enter Choice: ";
    cin >> choice;

    return choice;
}

// =======================
// CONTINUE MENU
// =======================
int continueMenu() {
    int choice;

    cout << "\n=== CONTINUE MENU ===\n";
    cout << "1. Main Menu\n";
    cout << "2. Try Again\n";
    cout << "-1. EXIT\n";
    cout << "Enter Choice: ";
    cin >> choice;

    return choice;
}

// =======================
// FIXED ARRAY
// =======================
void createFixedArray() {
    const int SIZE = 10;
    int arr[SIZE];
    vector<int> vec;
    int num;

    cout << "\n--- FIXED ARRAY INPUT ---\n";

    for (int i = 0; i < SIZE; i++) {
        do {
            cout << "Enter even number " << i + 1 << ": ";
            cin >> num;

            if (num % 2 != 0)
                cout << "ERROR: Invalid Input - Number must be even.\n";

        } while (num % 2 != 0);

        arr[i] = num;
        vec.push_back(num);
    }

    cout << "\nFixed Array Contents:\n";
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << "\n";

    cout << "\nFixed Vector Contents:\n";
    for (int n : vec)
        cout << n << " ";
    cout << "\n";
}

// =======================
// DYNAMIC ARRAY
// =======================
void createDynamicArray() {
    int size;
    cout << "\n--- DYNAMIC ARRAY INPUT ---\n";
    cout << "Enter Storage Size: ";
    cin >> size;

    int* arr = new int[size];
    vector<int> vec;
    int num;

    for (int i = 0; i < size; i++) {
        do {
            cout << "Enter even number " << i + 1 << ": ";
            cin >> num;

            if (num % 2 != 0)
                cout << "ERROR: Invalid Input - Number must be even.\n";

        } while (num % 2 != 0);

        arr[i] = num;
        vec.push_back(num);
    }

    cout << "\nDynamic Array Contents:\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";

    cout << "\nDynamic Vector Contents:\n";
    for (int n : vec)
        cout << n << " ";
    cout << "\n";

    delete[] arr;
}
