/*
  Imani Hollie 04/26/2026
  HOME EXPENSE CALCULATOR
  A file-driven program that:
  - Validates all user inputs (menu choices)
  - Displays total spending, budget comparisons, and a report
  - Allows exiting from any menu using X
*/

// HEADER ===========================================================
#include <iostream>      // Console input/output (cin, cout)
#include <iomanip>       // Output formatting (setw, setprecision)
#include <vector>        // Dynamic storage for all expenses
#include <set>           // Used to collect unique categories
#include <fstream>       // File reading (ifstream)
#include <limits>        // Clearing invalid input from cin
#include <string>        // String handling
#include <cctype>        // Character utilities (toupper)
#include <algorithm>     // Sorting monthly totals
#include <stdexcept>     // Exception handling for stoi()
using namespace std;     // Simplifies standard library usage

// DATA MODEL =======================================================
// Represents a month and its computed total spending
struct MonthTotal {
    int month;           // Month number (1–12)
    double total;        // Total spending for that month
};

// Represents one record from expenses.txt
struct Expense {
    int month;           // Month number (1–12)
    string category;     // Expense category (no spaces)
    double amount;       // Actual amount spent
    double budgeted;     // Budgeted amount for that category
};

// Stores all valid expenses loaded from the file
vector<Expense> expenses;

// FUNCTION PROTOTYPES ==============================================
void loadExpenses(const string& filename);      // Reads and validates file data
int getValidMonth(const string& prompt);        // Prompts user for a valid month
string getMenuChoice(const string& prompt);     // Reads and normalizes menu input
vector<double> computeMonthlyTotals();          // Computes total spending per month
void showMonthlyExpenses();                     // Displays expenses grouped by month
void showHighestExpenses();                     // Shows month with highest spending
void showTotalsSorted(bool descending);         // Displays totals sorted asc/desc
void showReport(int month);                     // Detailed report for a single month
void showCategories();                          // Displays all unique categories
void reportMenu();                              // Menu for selecting month reports
void totalsMenu();                              // Menu for sorted totals
void mainMenu();                                // Main navigation menu

// HELPER UTILITIES =================================================
// Loads all valid expense entries from the file into the global vector
void loadExpenses(const string& filename) {
    ifstream in(filename);                      // Attempt to open the file
    if (!in) {                                  // If file cannot be opened
        cout << "ERROR: Data Deficit - No data loaded.\n";
        return;
    }

    Expense e;                                   // Temporary storage for each record
    while (in >> e.month >> e.category >> e.amount >> e.budgeted) {
        // Reject invalid month values
        if (e.month < 1 || e.month > 12) continue;

        // Reject negative spending or budget values
        if (e.amount < 0 || e.budgeted < 0) continue;

        // Store valid expense entry
        expenses.push_back(e);
    }

    // If file opened but contained no valid entries
    if (expenses.empty()) {
        cout << "ERROR: Data Deficit - No data loaded.\n";
    }
}

// USER INPUT =======================================================
// Prompts until the user enters a valid month number (1–12)
int getValidMonth(const string& prompt) {
    int month;
    while (true) {
        cout << prompt;

        // Accept valid integer input in range
        if (cin >> month && month >= 1 && month <= 12)
            return month;

        // Handle invalid input
        cout << "ERROR: Invalid Input - Enter a month between 1 and 12\n";
        cin.clear();                             // Reset error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
    }
}

// Reads a menu choice and uppercases it if it's a single letter
string getMenuChoice(const string& prompt) {
    string choice;
    cout << prompt;
    cin >> choice;

    // Normalize single-letter commands (m → M, x → X)
    if (choice.size() == 1)
        choice[0] = static_cast<char>(toupper(choice[0]));

    return choice;
}

// CALCULATIONS =====================================================
// Computes total spending for each month and returns a 13-element vector
vector<double> computeMonthlyTotals() {
    vector<double> totals(13, 0.0);              // Index 1–12 used; index 0 unused

    // Add each expense to its corresponding month total
    for (const auto& e : expenses)
        totals[e.month] += e.amount;

    return totals;
}

// REPORTING ========================================================
// Displays all expenses grouped by month
void showMonthlyExpenses() {
    cout << "\n===== MONTHLY EXPENSES =====\n";

    // Loop through all 12 months
    for (int m = 1; m <= 12; m++) {
        cout << "\n--- Month " << m << " ---\n";
        bool found = false;                      // Tracks whether month has entries

        // Print each expense belonging to this month
        for (const auto& e : expenses) {
            if (e.month == m) {
                found = true;
                cout << left << setw(12) << e.category
                     << " Spent: $" << e.amount
                     << " | Budgeted: $" << e.budgeted << "\n";
            }
        }

        // If no expenses exist for this month
        if (!found)
            cout << "(No expenses recorded)\n";
    }
}

// Finds and displays the month with the highest total spending
void showHighestExpenses() {
    auto totals = computeMonthlyTotals();        // Compute totals for all months

    int bestMonth = 1;                           // Start with month 1 as baseline
    for (int m = 2; m <= 12; m++)
        if (totals[m] > totals[bestMonth])
            bestMonth = m;                       // Update when a higher total is found

    cout << "\n===== HIGHEST EXPENSE MONTH =====\n";
    cout << "Month " << bestMonth
         << " with total spending: $" << fixed << setprecision(2)
         << totals[bestMonth] << "\n";
}

// Sorts and displays monthly totals in ascending or descending order
void showTotalsSorted(bool descending) {
    auto totals = computeMonthlyTotals();        // Retrieve monthly totals
    vector<MonthTotal> list;                     // Holds month + total pairs

    // Populate list with all months
    for (int m = 1; m <= 12; m++)
        list.push_back({m, totals[m]});

    // Sort using a lambda that switches behavior based on 'descending'
    sort(list.begin(), list.end(),
         [descending](const MonthTotal& a, const MonthTotal& b) {
             return descending ? a.total > b.total : a.total < b.total;
         });

    cout << "\n===== MONTHLY TOTALS "
         << (descending ? "(Descending)" : "(Ascending)") << " =====\n";

    // Print sorted results
    for (const auto& mt : list) {
        cout << "Month " << mt.month << ": $"
             << fixed << setprecision(2) << mt.total << "\n";
    }
}

// Displays a detailed report for a specific month
void showReport(int month) {
    cout << "\n===== EXPENSE REPORT FOR MONTH " << month << " =====\n";

    double totalOver = 0;                        // Sum of over-budget amounts
    double totalSavings = 0;                     // Sum of under-budget amounts
    bool found = false;                          // Tracks if month has entries

    // Loop through all expenses for the selected month
    for (const auto& e : expenses) {
        if (e.month == month) {
            found = true;
            double diff = e.amount - e.budgeted; // Positive = over budget

            cout << "Category: " << setw(12) << e.category
                 << " Spent: $" << e.amount
                 << " | Budgeted: $" << e.budgeted;

            // Track over-budget or savings totals
            if (diff > 0) {
                cout << " | Over-Budget by $" << diff;
                totalOver += diff;
            } else {
                totalSavings += -diff;           // Convert negative diff to positive savings
            }

            cout << "\n";
        }
    }

    // If no expenses exist for this month
    if (!found) {
        cout << "(No expenses recorded)\n";
        return;
    }

    // Print summary totals
    cout << "\nTotal Over-Budget: $" << totalOver << "\n";
    cout << "Savings: $" << totalSavings << "\n";
}

// Displays all unique categories found in the dataset
void showCategories() {
    cout << "\n===== CATEGORY LIST =====\n";
    set<string> uniqueCats;                      // Automatically removes duplicates

    // Insert each category into the set
    for (const auto& e : expenses)
        uniqueCats.insert(e.category);

    // Print categories alphabetically (set is ordered)
    for (const auto& c : uniqueCats)
        cout << c << "\n";
}

// MENU FUNCTIONS ===================================================
// Menu for selecting a month report or exiting
void reportMenu() {
    while (true) {
        cout << "\n===== REPORT MENU =====\n";
        cout << "1-12. View report for a specific month\n";
        cout << "M. Return to Main Menu\n";
        cout << "X. Exit Program\n";

        string choice = getMenuChoice("Enter choice (1-12, M, X): ");

        if (choice == "M")
            return;                               // Return to main menu
        else if (choice == "X") {                 // Exit program entirely
            cout << "Exiting program...\n";
            exit(0);
        } else {
            try {
                size_t pos = 0;
                int month = stoi(choice, &pos);   // Convert input to integer

                // Validate conversion and range
                if (pos != choice.size() || month < 1 || month > 12)
                    throw invalid_argument("bad");

                showReport(month);                // Display report for valid month
            }
            catch (...) {
                cout << "ERROR: Invalid Input - Enter 1-12, M, or X\n";
            }
        }
    }
}

// Menu for viewing sorted monthly totals
void totalsMenu() {
    while (true) {
        cout << "\n===== TOTALS MENU =====\n";
        cout << "1. View Monthly Totals (Ascending)\n";
        cout << "2. View Monthly Totals (Descending)\n";
        cout << "M. Return to Main Menu\n";
        cout << "X. Exit Program\n";

        string choice = getMenuChoice("Enter choice: ");

        if (choice == "1")
            showTotalsSorted(false);              // Ascending order
        else if (choice == "2")
            showTotalsSorted(true);               // Descending order
        else if (choice == "M")
            return;                               // Back to main menu
        else if (choice == "X") {
            cout << "Exiting program...\n";
            exit(0);
        }
        else
            cout << "ERROR: Invalid Input - Enter 1-2, M, or X\n";
    }
}

// Main navigation menu for the entire program
void mainMenu() {
    while (true) {
        cout << "\n====================================\n";
        cout <<   "        HOMEOWNER EXPENSE MENU      \n";
        cout <<   "====================================\n";
        cout << "1. Display all expenses (grouped by month)\n";
        cout << "2. Display detailed report for a month\n";
        cout << "3. View monthly totals (ascending/descending)\n";
        cout << "4. View month with highest total expenses\n";
        cout << "5. Display list of categories\n";
        cout << "X. Exit program\n";
        cout << "------------------------------------\n";

        string choice = getMenuChoice("Enter choice: ");

        if      (choice == "1") showMonthlyExpenses();
        else if (choice == "2") reportMenu();
        else if (choice == "3") totalsMenu();
        else if (choice == "4") showHighestExpenses();
        else if (choice == "5") showCategories();
        else if (choice == "X") {
            cout << "Exiting program...\n";
            break;                                 // End main loop → exit program
        }
        else
            cout << "ERROR: Invalid Input - Enter 1-5 or X\n";
    }
}

// MAIN FUNCTION ====================================================
// Entry point of the program
int main() {
    cout << fixed << setprecision(2);             // Format all numeric output to 2 decimals
    loadExpenses("expenses.txt");                 // Load expense data from file
    mainMenu();                                   // Begin main menu loop
    return 0;                                     // End program
}
