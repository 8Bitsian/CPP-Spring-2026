/*
  Imani Hollie 03/06/2026
  HOME EXPENSE CALCULATOR
  A menu-driven program that:
  - Collects budgeted and actual expenses for multiple home categories
  - Adjusts totals based on a user-selected month range
  - Validates all user inputs (numbers, months, menu choices)
  - Displays total spending, budget comparisons, and a color-coded report
  - Allows exiting from any menu using -1
*/

// =============================== HEADER ================================
#include <iostream>     // For cout, cin, basic I/O
#include <iomanip>      // For formatting numbers (setprecision, fixed)
#include <limits>       // For numeric_limits used in input validation
#include <string>       // For standard string
#include <cctype>       // For toupper()
using namespace std;    // For use of standard names w/out std prefix

// =========================== CATEGORY STRUCT ===========================
struct Category {
    string name;        // Name of the category
    double budget = 0;  // Budgeted amount
    double actual = 0;  // Actual total cost (monthly * totalMonths)
};

// =========================== CATEGORY ARRAY ============================
Category categories[] = {
    {"Housing"}, {"Insurance"}, {"Electricity"}, {"Internet"}, {"Water"},
    {"Gas"}, {"Groceries"}, {"Restaurants"}, {"Maintenance"}, {"Renovation"}
};

// ==================== GLOBAL CONSTANTS & VARIABLES =====================
// Sentinel value used to indicate the user wants to exit the program.
const int EXIT_SENTINEL = -1;
// Number of categories in the array (computed automatically).
const int NUM_CATEGORIES = sizeof(categories) / sizeof(categories[0]);
// Number of months included in the expense calculation.
int totalMonths = 1;

// ========================= FUNCTION PROTOTYPES =========================
double getPositiveDouble(const string& prompt);   // Validates non-negative dollar input
int getValidMonth(const string& prompt);          // Validates month input (1–12)
char getMenuChar(const string& prompt);           // Reads menu input, detects "-1"
void getMonthRange();                             // Gets start/end month range
void enterCost(Category& c);                      // Inputs budget + actual for a category
double totalExpenses();                           // Computes total actual expenses
double totalBudget();                             // Computes total budgeted amount
void budgetComparisons();                         // Displays budget vs actual totals
void categoryReport();                            // Displays color-coded category report
int mainMenu();                                   // Main menu loop
int expensesMenu();                               // Expenses menu
int utilitiesMenu();                              // Utilities submenu
int operatingMenu();                              // Operating submenu
int mealsMenu();                                  // Food submenu

// =========================== INPUT VALIDATION ==========================
/* -------------------------------------------------------------------
Ensures the user enters a non-negative dollar amount.
Used for budget and actual expense inputs.
------------------------------------------------------------------- */
double getPositiveDouble(const string& prompt) {
    double value;   // Stores the user's input
    while (true) {  // Loop until valid input is received
        // Get user input
        cout << prompt;
        cin >> value;
        
        // Check: input is a number AND non-negative
        if (!cin.fail() && value >= 0)
            return value;
        
        // Error message for invalid input
        cout << "ERROR: Invalid Input - Enter a non-negative number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

/* -------------------------------------------------------------------
Ensures the user enters a valid month number (1–12).
Used when defining the month range.
------------------------------------------------------------------- */
int getValidMonth(const string& prompt) {
    int m;              // Stores the user's month input
    while (true) {      // Loop until valid input is received
        // Get user input
        cout << prompt;
        cin >> m;
        
        // Check: input is a number AND within 1–12
        if (!cin.fail() && m >= 1 && m <= 12)
            return m;
        
        // Error message for invalid input
        cout << "ERROR: Invalid Input - Enter a month between 1 and 12.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

/* -------------------------------------------------------------------
Reads a single menu character from the user.
Supports:
- '1', '2', '3', etc.
- 'M' or 'm' for returning to a menu
- "-1" as a sentinel to exit (converted to 'X')
------------------------------------------------------------------- */
char getMenuChar(const string& prompt) {
    // Get user input
    cout << prompt;
    char c = cin.get();

    while (c == '\n')   // Skip newline characters
        c = cin.get();  // Read next character

    if (c == '-') {                 // Check if user typed '-'
        if (cin.peek() == '1') {    // Peek next character without consuming it
            cin.get();              // Consume the '1'
            return 'X';             // Return sentinel 'X' for exit
        }
    }

    return toupper(c);  // Convert to uppercase
}


// ============================ MAIN FUNCTION ============================
/* -------------------------------------------------------------------
Entry point of the program. Displays the title, explains how to exit,
asks the user for the month range, and then starts the main menu.
------------------------------------------------------------------- */
int main() {
    // Display program header and information about exit sentinel
    cout << "=== HOME EXPENSE CALCULATOR ===\n";
    cout << "Enter -1 at any menu to exit.\n\n";
    getMonthRange();    // Ask user for start/end month range
    mainMenu();         // Begin main menu loop
    return 0;           // End program successfully
}

// ============================= USER INPUT ==============================
/* -------------------------------------------------------------------
Prompts the user for a start and end month, validates them,
and calculates how many months are included in the expense totals.
------------------------------------------------------------------- */
void getMonthRange() {
    // Display section header and explain directions
    cout << "--- MONTH RANGE ---\n";
    cout << "Enter a range of months...\n";
    cout << "Ex. 1 is January, 2 is February, etc.\n\n";

    // Get user input
    int startMonth = getValidMonth("Enter Start Month (1-12): ");
    int endMonth   = getValidMonth("  Enter End Month (1-12): ");

    // Calculate number of months in range
    totalMonths = (endMonth - startMonth) + 1;
    
    // Check if userInput is negative or zero, default to 1 if invalid
    if (totalMonths < 1)
        totalMonths = 1;

    cout << "\nCalculating expenses for: " << totalMonths << " month(s).\n\n";
}

/* -------------------------------------------------------------------
Prompts the user for the budgeted amount and actual monthly cost
for a specific category, then multiplies the actual cost by the
number of months selected earlier.
------------------------------------------------------------------- */
void enterCost(Category& c) {
    // User input for budgeted and actual amounts
    c.budget = getPositiveDouble("\nEnter BUDGETED amount for " + c.name + ": $");
    double actual = getPositiveDouble("Enter ACTUAL amount for " + c.name + ": $");
    // Calculate total cost for all months
    c.actual = actual * totalMonths;
}

// ======================== CALCULATE TOTALS =========================
/* -------------------------------------------------------------------
Calculates the sum of all actual expenses across all categories.
Also prints the total to the screen.
------------------------------------------------------------------- */
double totalExpenses() {
    double total = 0;   // Running total of actual expenses
    
    // Calculate the running actual total via array
    for (auto& c : categories)
        total += c.actual;
    
    // Output formatted total expenses
    cout << fixed << setprecision(2);
    cout << "\nTotal Expenses: $" << total << "\n\n";

    return total;   // Return the computed total
}

// Calculates the sum of all budgeted amounts across all categories.
double totalBudget() {
    double total = 0;   // Running total of budgeted amounts
    
    // Calculate the running budgeted total via array
    for (auto& c : categories)
        total += c.budget;

    return total;   // Return the computed total
}

// ============================ MAIN MENU ============================
/* -------------------------------------------------------------------
Displays the main menu options and routes the user to the correct
part of the program based on their input. Loops until the user exits.
------------------------------------------------------------------- */
int mainMenu() {
    while (true) { // Iterate menu until the user returns or exits
        // Display main menu options
        cout << "===== MAIN MENU =====\n";
        cout << "1. Redefine Month Range\n";
        cout << "2. Input Monthly Expenses\n";
        cout << "3. View Total Expenses\n";
        cout << "4. View Budget Comparisons\n";
        cout << "5. Category-by-Category Report\n";
        cout << "(-1) Exit Program\n\n";
        
        // Get user input (Sentinal Values: -1 and 'M')
        char c = getMenuChar("Enter Option: ");
        switch (c) {
            case '1': getMonthRange(); break;
            case '2': expensesMenu(); break;
            case '3': totalExpenses(); break;
            case '4': budgetComparisons(); break;
            case '5': categoryReport(); break;
            case 'X': // -1 exit program
                cout << "\nExiting program...\n";
                return EXIT_SENTINEL;
        }
    }
}

// ============================ SUB-MENUS ============================
/* -------------------------------------------------------------------
Displays the sub-menu options and routes the user to the correct
part of the program based on their input. Loops until the user exits.
------------------------------------------------------------------- */
int expensesMenu() {
    while (true) {  // Iterate menu until the user returns or exits
        // Display expense menu options
        cout << "\n===== MONTHLY EXPENSES MENU =====\n";
        cout << "1. Mortgage/Rent Cost\n";
        cout << "2. Home-Insurance Cost\n";
        cout << "3. Utilities Expenses\n";
        cout << "4. Operating Expenses\n";
        cout << "5. Food Expenses\n";
        cout << "(M) Return to Main Menu\n";
        cout << "(-1) Exit Program\n\n";

        // Get user input (Sentinal Values: -1 and 'M')
        char c = getMenuChar("Enter Option: ");
        switch (c) {
            case '1': enterCost(categories[0]); break;  // Housing
            case '2': enterCost(categories[1]); break;  // Insurance
            case '3': utilitiesMenu(); break;
            case '4': operatingMenu(); break;
            case '5': mealsMenu(); break;
            case 'M': // Return to Main Menu
                cout << "\nReturning to Main Menu...\n";
                return 0;
            case 'X': // -1 exit program
                cout << "\nExiting program...\n";
                return EXIT_SENTINEL;
        }
    }
}

int utilitiesMenu() {
    while (true) { // Iterate menu until the user returns or exits
        cout << "\n===== UTILITY EXPENSES MENU =====\n";
        cout << "1. Electricity Cost\n";
        cout << "2. Internet Costs\n";
        cout << "3. Water Cost\n";
        cout << "4. Gas Cost\n";
        cout << "(M) Return to Expenses Menu\n";
        cout << "(-1) Exit Program\n\n";
        
        // Get user input (Sentinal Values: -1 and 'M')
        char c = getMenuChar("Enter Option: ");
        switch (c) {
            case '1': enterCost(categories[2]); break; // Electricity
            case '2': enterCost(categories[3]); break; // Internet
            case '3': enterCost(categories[4]); break; // Water
            case '4': enterCost(categories[5]); break; // Gas
            case 'M': // Return to Main Menu
                cout << "\nReturning to Main Menu...\n";
                return 0;
            case 'X': // -1 exit program
                cout << "\nExiting program...\n";
                return EXIT_SENTINEL;
        }
    }
}

int mealsMenu() {
    while (true) { // Iterate menu until the user returns or exits
        cout << "\n===== FOOD EXPENSES MENU =====\n";
        cout << "1. Groceries Cost\n";
        cout << "2. Restaurant Cost\n";
        cout << "(M) Return to Expenses Menu\n";
        cout << "(-1) Exit Program\n\n";
        
        // Get user input (Sentinal Values: -1 and 'M')
        char c = getMenuChar("Enter Option: ");
        switch (c) {
            case '1': enterCost(categories[6]); break; // Groceries
            case '2': enterCost(categories[7]); break; // Restaurant
            case 'M': // Return to Main Menu
                cout << "\nReturning to Main Menu...\n";
                return 0;
            case 'X': // -1 exit program
                cout << "\nExiting program...\n";
                return EXIT_SENTINEL;
        }
    }
}

int operatingMenu() {
    while (true) { // Iterate menu until the user returns or exits
        cout << "\n===== OPERATING EXPENSES MENU =====\n";
        cout << "1. Maintenance Cost\n"; // Includes repairs
        cout << "2. Renovation Cost\n";
        cout << "(M) Return to Expenses Menu\n";
        cout << "(-1) Exit Program\n\n";
        
        // Get user input (Sentinal Values: -1 and 'M')
        char c = getMenuChar("Enter Option: ");
        switch (c) {
            case '1': enterCost(categories[8]); break; // Maintenance
            case '2': enterCost(categories[9]); break; // Renovation
            case 'M': // Return to Main Menu
                cout << "\nReturning to Main Menu...\n";
                return 0;
            case 'X': // -1 exit program
                cout << "\nExiting program...\n";
                return EXIT_SENTINEL;
        }
    }
}

// ============================ OUTPUT REPORTS ============================
void budgetComparisons() {
    // Call functions
    double actual = totalExpenses(); // Display actual totals
    double budget = totalBudget();

    // Ensure consistent currency formatting (2 decimals)
    cout << fixed << setprecision(2);

    // Show the comparison header and totals
    cout << "\n=== BUDGET COMPARISON ===\n";
    cout << "Total Budget:   $" << budget << "\n";
    cout << "Total Expenses: $" << actual << "\n";

    // Calculate if total is under/overbudget
    if (actual > budget)
        cout << "You are OVER budget by $" << actual - budget << "\n\n";
    else
        cout << "You are UNDER budget by $" << budget - actual << "\n\n";
}

void categoryReport() {
    // Report header
    cout << "\n===== CATEGORY REPORT =====\n";
    cout << fixed << setprecision(2);  // Format all dollar values

    // Iterate through every category in the global array
    for (auto& c : categories) {
        // Calculate if Positive => over budget/Negative => under
        double diff = c.actual - c.budget;

        // Choose an ANSI color code:
        string color =
            diff > 0 ? "\033[31m" :   // OVER => red
            diff < 0 ? "\033[32m" :   // UNDER => green
                       "\033[0m";     // EXACT => default color

        // Print category header and values
        cout << "\n" << c.name << ":\n";
        cout << "  Budgeted: $" << c.budget << "\n";
        cout << "  Actual:   $" << c.actual << "\n";

        // Print the status line with color applied
        cout << "  Status: " << color;
        if (diff > 0)
            cout << "OVER by $" << diff;
        else if (diff < 0)
            cout << "UNDER by $" << -diff;
        else 
            cout << "Exactly on budget";

        // Reset terminal color
        cout << "\033[0m\n";
    }
    cout << endl;
}
