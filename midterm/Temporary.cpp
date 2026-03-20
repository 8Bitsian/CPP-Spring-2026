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
#include <iostream>     // Provides input/output functionality
#include <iomanip>      // Provides formatting tools (e.g., setprecision)
#include <limits>       // Provides numeric limits for input validation
#include <string>       // Provides the string class
#include <cctype>       // Provides character classification functions like toupper()
using namespace std;    // Use the standard namespace to simplify code readability

// =========================== CATEGORY STRUCT/DATA ===========================
/*
   An enumeration (enum) for integer constants to represent type of category
   - NORMAL means the cost applies per month
   - FULL_SPAN means the cost applies once per range
*/
enum CategoryType { NORMAL, FULL_SPAN };

/*
   A structure (struct) creates a new user-defined data type that can be used to group related variables
   Each category has a name, uppercase name, type (normal, full_span), scaling rule, menu number, and cost fields (budget, actual)
*/
struct Category {
    string name;                // Name of the category
    string upper;               // Uppercase name of the category
    CategoryType categoryType;  // NORMAL or FULL_SPAN
    bool multiplyByMonths;      // TRUE (multiplied by months) or FALSE (one-time expense)
    int menuNumber;             // Menu number for this category
    double budget = 0;          // Budgeted amount for this category
    double actual = 0;          // Actual amount for this category
};

/*
  An array is a data structure that stores a fixed-size of elements of the same data type
  The array "categories" stores "Category" objects
*/
Category categories[] = {
    {"Housing",     "HOUSING",     NORMAL,    true,  1},
    {"Insurance",   "INSURANCE",   NORMAL,    true,  2},
    {"Electricity", "ELECTRICITY", NORMAL,    true,  3},
    {"Internet",    "INTERNET",    NORMAL,    true,  4},
    {"Water",       "WATER",       NORMAL,    true,  5},
    {"Gas",         "GAS",         NORMAL,    true,  6},
    {"Maintenance", "MAINTENANCE", FULL_SPAN, false, 7},
    {"Renovation",  "RENOVATION",  FULL_SPAN, false, 8},
    {"Groceries",   "GROCERIES",   NORMAL,    true,  9},
    {"Restaurants", "RESTAURANTS", NORMAL,    true,  0}
};

// Constant for the number of categories using sizeof()
const int NUM_CATEGORIES = sizeof(categories) / sizeof(categories[0]);

// Variable to store the month range
int totalMonths = 1;

// ========================= FUNCTION PROTOTYPES =========================
// --- Helper Functions ---
void clearCost(Category& c);
void showBreadcrumb(const string& location);
void showWarnings();
void showCategoryStatus();
// --- Menus ---
int mainMenu();
int expensesMenu();
// --- User Input ---
void getMonthRange();
int getValidMonth(const string& prompt);
int getMenuChoice(int min, int max);
bool getCostInput(const string& prompt, double& value, const Category& c);
void enterCategoryCosts(Category& c);
// --- Calculate ---
double totalExpenses();
double totalBudget();
// --- Output ---
void budgetComparisons();
void categoryReport();

// =========================== HELPER FUNCTIONS ===========================

// clearCost() : Resets both the budget and actual values for a category
void clearCost(Category& c) { c.budget = 0; c.actual = 0; }

// showBreadcrumb() : Displays a breadcrumb trail to show the user's current location
void showBreadcrumb(const string& location) { cout << "[You are here: " << location << "]\n\n"; }

// showWarnings() : Displays warnings for categories that have missing budget or actual values
void showWarnings() {
    // 1: Loop through all categories
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        // 1.1: Validate if the category has missing budget or actual values
        if (categories[i].budget == 0 || categories[i].actual == 0) {
            // 1.2: Display a warning message for this category
            cout << "WARNING: " << categories[i].upper
                 << " has missing budget or actual values.\n";
        }
    }

    // 2: Print a blank line for spacing
    cout << "\n";
}

// showCategoryStatus() : Displays the status of each category (OK or N/A)
void showCategoryStatus() {
    // 1: Print a header for the status table.
    cout << "Category Status:\n";

    // 2: Loop through all categories
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        // 2.1: Print the category name
        cout << categories[i].upper << ": ";
        // 2.2: Show whether the budget value has been entered
        if (categories[i].budget > 0)
            cout << "Budget OK, ";
        else
            cout << "Budget N/A, ";
        // 2.3: Show whether the actual value has been entered
        if (categories[i].actual > 0)
            cout << "Actual OK\n";
        else
            cout << "Actual N/A\n";
    }
    // 3: Print a blank line for spacing.
    cout << "\n";
}


// ============================= USER INPUT ==============================
// getMonthRange() : Handles input for the month range and displays the result
void getMonthRange() {
    // 1. Show where the user is in the program
    showBreadcrumb("Month Range");

    // 2. Display the section header
    cout << "\n===== MONTH RANGE =====\n";

    // 3. Get user input
    int startMonth = getValidMonth("Start Month (1-12): ");
    int endMonth   = getValidMonth("End Month (1-12): ");

    // 4. Compute the number of months, ensuring it is at least 1.
    totalMonths = max(1, endMonth - startMonth + 1);

    // 5. Display the number of months that will be used in calculations.
    cout << "\nUsing " << totalMonths << " month(s).\n";
}

/*
   getValidMonth()
   Prompts the user for a month number (1–12) and validates it.
*/
int getValidMonth(const string& prompt) {
    // 1: Declare variable
    int month;

    // 2: Loop until the user enters a valid month number
    while (true) {
        // 2.1: Get user input
        cout << prompt;
        if (cin >> month) {
            // 2.2: Validate if the month is within the valid range
            if (month >= 1 && month <= 12) {
                // 2.3: Return the valid month
                return month;
            }
        }

        // Step 3: Clear invalid input and show an ERROR message
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ERROR: Invalid Input - Please enter a number from 1 to 12.\n";
    }
}

// getMenuChoice() : Prompts the user for a menu choice and validates the input
int getMenuChoice(int min, int max) {
    // 1: Declare variable
    int choice;

    // 2: Loop until the user enters a valid number
    while (true) {
        // 2.1: Get user input
        cout << "Enter your choice: ";
        if (cin >> choice) {
            // 2.2: Vaidate if the number is within the valid range
            if (choice >= min && choice <= max) {
                // 2.3: Return the valid choice
                return choice;
            }
        }

        // 3: Clear invalid input and show an ERROR message
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ERROR: Invalid Input - Please enter a number between " << min << " and " << max << ".\n";
    }
}

// getCostInput() : Prompts the user for a cost value and validates the input (true if valid, else false)
bool getCostInput(const string& prompt, double& value, const Category& c) {
    // 1. Get user input
    cout << prompt;
    // 2. Validate non-negative
    if (cin >> value && value >= 0)
        return true;
  
    // 3. Clear invalid input and show an ERROR message
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "ERROR: Invalid Input - Please enter a non-negative number.\n";
    return false;
}

// enterCategoryCosts() : Handles all input for a single category including budget and actual amounts
void enterCategoryCosts(Category& c) {
    // 1. Show where the user is in the program
    showBreadcrumb("Monthly Expenses > " + c.upper);

    // 2. Show the section header
    cout << "\n===== ENTER COSTS =====\n";
    cout << "Category: " << c.upper << "\n";
    cout << "Months: " << totalMonths << "\n";
    cout << "Type [C] to clear this category.\n\n";

    // 3. Vlaidate if the category is a full-span type and notify the user
    if (c.categoryType == FULL_SPAN)
        cout << "(This category is a full-span total.)\n\n";

    // 4. Declare variables to store the budget and actual values.
    double budgetValue, actualValue;

    // 5. Get user input until valid input is received
    while (!getCostInput("Enter BUDGETED amount: $", budgetValue, c));
    while (!getCostInput("Enter ACTUAL amount: $", actualValue, c));

    // 6. Show warnings based on the actual value
    showWarnings(actualValue);

    // 7. Store the budgeted amount and the actual amount, scaling by months in necessary
    c.budget = budgetValue;
    c.actual = c.multiplyByMonths ? actualValue * totalMonths : actualValue;

    // 8. Confirm to the user that the values were saved and show progress
    cout << "\nSaved successfully.\n";
    showProgressAndMissingCategories();
}

// totalExpenses() : Adds up all actual expenses across all categories.
double totalExpenses() {
    // 1. Calculate each categories actual amount
    double total = 0;
    for (auto& c : categories)
        total += c.actual;

    // 2. Return the final computed total
    return total;
}

// totalBudget() : Adds up all budgeted amounts across all categories.
double totalBudget() {
    // 1. Calculate each categories budgeted amount
    double total = 0;
    for (auto& c : categories)
        total += c.budget;

    // 2. Return the final computed budget
    return total;
}

/*
   budgetComparisons()
   Shows the total budget, total expenses, and whether the user
   is over, under, or exactly on budget.
*/
void budgetComparisons() {
    // Clear the screen for a clean display.
    clearScreen();

    // Show a breadcrumb so the user knows where they are.
    showBreadcrumb("Budget Comparisons");

    // Compute the total actual expenses across all categories.
    double actual = totalExpenses();

    // Compute the total budgeted amount across all categories.
    double budget = totalBudget();

    // Format all numbers to two decimal places.
    cout << fixed << setprecision(2);

    // Display the report header.
    cout << "\n===== BUDGET COMPARISON =====\n";

    // Show the total budgeted amount.
    cout << "Budget:   $" << budget << "\n";

    // Show the total actual expenses.
    cout << "Expenses: $" << actual << "\n";

    // Compare actual spending to the budget and display the result.
    if (actual > budget)
        cout << "You are OVER by $" << actual - budget << "\n";
    else if (actual < budget)
        cout << "You are UNDER by $" << budget - actual << "\n";
    else
        cout << "You are EXACTLY on budget.\n";
}

/*
   categoryReport()
   Shows a detailed breakdown for each category, including
   budget, actual, difference, and full-span status.
*/
void categoryReport() {
    // Clear the screen for a clean display.
    clearScreen();

    // Show a breadcrumb so the user knows where they are.
    showBreadcrumb("Category Report");

    // Display the report header.
    cout << "\n===== CATEGORY REPORT =====\n";

    // Format all numbers to two decimal places.
    cout << fixed << setprecision(2);

    // Loop through each category and display its details.
    for (auto& c : categories) {
        // Compute the difference between actual and budget.
        double diff = c.actual - c.budget;

        // Display the category name.
        cout << "\n" << c.upper << "\n";

        // Display a simple separator line.
        cout << "---------------------------\n";

        // Show the budgeted amount.
        cout << "Budget: $" << c.budget << "\n";

        // Show the actual amount spent.
        cout << "Actual: $" << c.actual << "\n";

        // Indicate if this category is a full-span total.
        if (c.categoryType == FULL_SPAN)
            cout << "(Full-span total)\n";

        // Display the status (over, under, or on budget).
        cout << "Status: ";
        if (diff > 0)
            cout << "OVER by $" << diff;
        else if (diff < 0)
            cout << "UNDER by $" << -diff;
        else
            cout << "ON BUDGET";

        // Move to the next line for spacing.
        cout << "\n";
    }
}

/*
   expensesMenu()
   Displays the list of categories, handles user selection,
   and routes the user to enterCategoryCosts().
*/
int expensesMenu() {
    // Loop so the menu reappears after each action.
    while (true) {
        // Clear the screen for a clean display.
        clearScreen();

        // Show a breadcrumb so the user knows where they are.
        showBreadcrumb("Monthly Expenses");

        // Display the menu header.
        cout << "\n===== EXPENSES MENU =====\n";

        // List all categories with their menu numbers.
        for (auto& c : categories)
            cout << c.menuNumber << ". " << c.name << "\n";

        // Provide options to return to main menu or exit.
        cout << "[M] Main Menu\n";
        cout << "[X] Exit\n\n";

        // Ask the user for a menu choice.
        char choice = getMenuChoice("Choose: ");

        // Return to the main menu.
        if (choice == 'M') return 0;

        // Exit the program immediately.
        if (choice == 'X') exit(0);

        // If the user typed a digit, check if it matches a category.
        if (isdigit(choice)) {
            // Convert the character digit to an integer.
            int num = choice - '0';

            // Find the category with the matching menu number.
            for (auto& c : categories)
                if (c.menuNumber == num)
                    enterCategoryCosts(c);  // Open cost entry for that category.
        }
    }
}

/*
   mainMenu()
   Displays the main navigation menu and calls the appropriate actions.
*/
int mainMenu() {
    // Define a small struct to pair menu labels with their actions.
    struct MenuItem {
        string label;
        void (*action)();
    };

    // Create the list of main menu options and their corresponding functions.
    MenuItem items[] = {
        {"Redefine Month Range", getMonthRange},
        {"Input Monthly Expenses", [](){ expensesMenu(); }},
        {"View Budget Comparisons", budgetComparisons},
        {"View Category Report", categoryReport}
    };

    // Compute how many menu items exist.
    const int COUNT = sizeof(items) / sizeof(items[0]);

    // Loop so the main menu reappears after each action.
    while (true) {
        // Clear the screen for a clean display.
        clearScreen();

        // Show a breadcrumb so the user knows where they are.
        showBreadcrumb("Main Menu");

        // Display the menu header.
        cout << "\n===== MAIN MENU =====\n";

        // List each menu item with a number.
        for (int i = 0; i < COUNT; i++)
            cout << i+1 << ". " << items[i].label << "\n";

        // Provide an option to exit the program.
        cout << "[X] Exit\n\n";

        // Ask the user for a menu choice.
        char choice = getMenuChoice("Choose: ");

        // Exit the program immediately.
        if (choice == 'X')
            exit(0);

        // If the user typed a digit, check if it matches a menu item.
        if (isdigit(choice)) {
            // Convert the character digit to a zero‑based index.
            int index = choice - '1';

            // Ensure the index is valid before calling the action.
            if (index >= 0 && index < COUNT)
                items[index].action();
        }
    }
}

/*
   main()
   Starts the program by asking for the month range,
   then opens the main menu.
*/
int main() {
    // Ask the user to define the month range first.
    getMonthRange();

    // Open the main menu loop.
    mainMenu();
}
