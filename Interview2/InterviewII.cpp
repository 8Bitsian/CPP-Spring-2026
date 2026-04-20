#include <iostream>
#include <limits>
using namespace std;

const int NUM_VALUES = 10;

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

int signOf(int n) {
    return (n > 0) - (n < 0);
}

int maxOf(int a, int b) {
    return (a > b) ? a : b;
}

int sumOf(const int arr[]) {
    int sum = 0;
    for (int i = 0; i < NUM_VALUES; i++)
        sum += arr[i];
    return sum;
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
    int nums[NUM_VALUES];
    loadNumbers(nums);
    menu(nums);
    return 0;
}
