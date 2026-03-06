/*
  Imani Hollie
  03/06/2026
  HOME EXPENSE CALCULATOR
  - Tracks budgeted vs actual expenses
  - Validates all user input
  - Provides category-by-category color-coded report
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cctype>
using namespace std;

// ========================= GLOBAL CONSTANTS =========================
// Sentinel values for exiting menus
const int EXIT_SENTINEL = -1;
const char MENU_SENTINEL = 'M';

// ========================= GLOBAL VARIABLES =========================
// Number of months included in the calculation
int totalMonths = 1;

// Actual expenses (calculated * totalMonths)
double totalHousing = 0;
double totalInsurance = 0;
double totalElectric = 0;
double totalInternet = 0;
double totalWater = 0;
double totalGas = 0;
double totalGroceries = 0;
double totalRestaurants = 0;
double totalMaintenance = 0;
double totalRenovation = 0;

// Budgeted amounts (entered once per category)
double budgetHousing = 0;
double budgetInsurance = 0;
double budgetElectric = 0;
double budgetInternet = 0;
double budgetWater = 0;
double budgetGas = 0;
double budgetGroceries = 0;
double budgetRestaurants = 0;
double budgetMaintenance = 0;
double budgetRenovation = 0;

// ========================= FUNCTION PROTOTYPES =========================
int mainMenu();
int expensesMenu();
int utilitiesMenu();
int operatingMenu();
int mealsMenu();

void getMonthRange();
void totalExpenses();
void budgetComparisons();
void categoryReport();
double totalBudget();

double housingCost();
double insuranceCost();
double electricCost();
double internetCost();
double waterCost();
double gasCost();
double groceriesCost();
double restaurantCost();
double maintenanceCost();
double renovationCost();

// ========================= MAIN =========================

int main() {
    cout << "=== HOME EXPENSE CALCULATOR ===\n";
    cout << "Enter -1 at any main menu to exit.\n\n";

    getMonthRange();   // Ask user for month range
    mainMenu();        // Start main menu loop
    return 0;
}

// ========================= INPUT VALIDATION HELPERS =========================

// Ensures user enters a non-negative dollar amount
double getPositiveDouble(string prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        // Valid input AND non-negative
        if (!cin.fail() && value >= 0)
            return value;

        // Handle invalid input
        cout << "ERROR: Enter a non-negative number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Ensures user enters a valid menu choice
int getMenuChoice(int min, int max) {
    int c;
    while (true) {
        cout << "Enter Option: ";
        cin >> c;

        if (!cin.fail() && c >= min && c <= max)
            return c;

        cout << "ERROR: Invalid menu option.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Ensures user enters a valid month (1–12)
int getValidMonth(string prompt) {
    int m;
    while (true) {
        cout << prompt;
        cin >> m;

        if (!cin.fail() && m >= 1 && m <= 12)
            return m;

        cout << "ERROR: Enter a month between 1 and 12.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Reads a menu character (M, 1, 2, etc.)
char getMenuChar(string prompt) {
    char c;
    while (true) {
        cout << prompt;
        cin >> c;
        c = toupper(c);

        if (!cin.fail())
            return c;

        cout << "ERROR: Invalid input.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// ========================= MONTH RANGE =========================

void getMonthRange() {
    cout << "--- MONTH RANGE ---\n";

    // Get validated month inputs
    int startMonth = getValidMonth("Enter Starting Month (1-12): ");
    int endMonth   = getValidMonth("Enter Ending Month (1-12): ");

    // Calculate number of months included
    totalMonths = (endMonth - startMonth) + 1;

    // Prevent invalid ranges
    if (totalMonths < 1)
        totalMonths = 1;

    cout << "Calculating expenses for: " << totalMonths << " month(s).\n\n";
}

// ========================= MAIN MENU =========================

int mainMenu() {
    while (true) {
        cout << "=== MAIN MENU ===\n";
        cout << "1. Input Month Range\n";
        cout << "2. Input Monthly Expenses\n";
        cout << "3. View Total Expenses\n";
        cout << "4. View Budget Comparisons\n";
        cout << "5. Category-by-Category Report\n";
        cout << "(-1) Exit Program\n\n";

        int choice = getMenuChoice(-1, 4);

        switch (choice) {
            case 1: getMonthRange(); break;
            case 2: expensesMenu(); break;
            case 3: totalExpenses(); break;
            case 4: budgetComparisons(); break;
            case 5: categoryReport(); break;
            case -1:
                cout << "Exiting program...\n";
                return EXIT_SENTINEL;
        }
    }
}

// ========================= EXPENSES MENU =========================

int expensesMenu() {
    while (true) {
        cout << "\n=== MONTHLY EXPENSES MENU ===\n";
        cout << "1. Mortgage/Rent Cost\n";
        cout << "2. Home-Insurance Cost\n";
        cout << "3. Utilities Expenses\n";
        cout << "4. Operating Expenses\n";
        cout << "5. Food Expenses\n";
        cout << "6. Return to Main Menu\n";
        cout << "(-1) Exit Program\n\n";

        int choice = getMenuChoice(-1, 6);

        switch (choice) {
            case 1: totalHousing = housingCost(); break;
            case 2: totalInsurance = insuranceCost(); break;
            case 3: utilitiesMenu(); break;
            case 4: operatingMenu(); break;
            case 5: mealsMenu(); break;
            case 6:
              cout << "Returning to main menu...\n";
              return 0;
            case -1:
              cout << "Exiting program...\n";
              return EXIT_SENTINEL;
        }
    }
}

// ========================= UTILITIES MENU =========================

int utilitiesMenu() {
    while (true) {
        cout << "\n=== UTILITY EXPENSES MENU ===\n";
        cout << "1. Electricity Cost\n";
        cout << "2. Internet Costs\n";
        cout << "3. Water Cost\n";
        cout << "4. Gas Cost\n";
        cout << "(M) Return to Expenses Menu\n";
        cout << "(-1) Exit Program\n\n";

        char c = getMenuChar("Enter Option: ");

        switch (c) {
            case '1': totalElectric = electricCost(); break;
            case '2': totalInternet = internetCost(); break;
            case '3': totalWater = waterCost(); break;
            case '4': totalGas = gasCost(); break;
            case 'M':
              cout << "Returning to expenses menu...\n";
              return 0;
            case '-':
              cout << "Exiting program...\n";
              return EXIT_SENTINEL;
        }
    }
}

// ========================= OPERATING MENU =========================

int operatingMenu() {
    while (true) {
        cout << "\n=== OPERATING EXPENSES MENU ===\n";
        cout << "1. Maintenance Cost\n";
        cout << "2. Renovation Cost\n";
        cout << "(M) Return to Expenses Menu\n";
        cout << "(-1) Exit Program\n\n";

        char c = getMenuChar("Enter Option: ");

        switch (c) {
            case '1': totalMaintenance = maintenanceCost(); break;
            case '2': totalRenovation = renovationCost(); break;
            case 'M':
              cout << "Returning to expenses menu...\n";
              return 0;
            case '-':
              cout << "Exiting program...\n";
              return EXIT_SENTINEL;
        }
    }
}

// ========================= FOOD MENU =========================

int mealsMenu() {
    while (true) {
        cout << "\n=== FOOD EXPENSES MENU ===\n";
        cout << "1. Groceries Cost\n";
        cout << "2. Restaurant Cost\n";
        cout << "3. Return to Expenses Menu\n";
        cout << "(-1) Exit Program\n\n";

        int choice = getMenuChoice(-1, 3);

        switch (choice) {
            case 1: totalGroceries = groceriesCost(); break;
            case 2: totalRestaurants = restaurantCost(); break;
            case 3:
              cout << "Returning to expenses menu...\n";
              return 0;
            case -1:
              cout << "Exiting program...\n";
              return EXIT_SENTINEL;
        }
    }
}

// ========================= EXPENSE INPUT FUNCTIONS =========================
// Each function:
// - Asks for budgeted amount
// - Asks for actual amount
// - Multiplies actual by totalMonths

double housingCost() {
    budgetHousing = getPositiveDouble("Enter BUDGETED amount for mortgage/rent: $");
    double actual = getPositiveDouble("Enter ACTUAL amount for mortgage/rent: $");
    return actual * totalMonths;
}

double insuranceCost() {
    budgetInsurance = getPositiveDouble("Enter BUDGETED amount for insurance: $");
    double actual = getPositiveDouble("Enter ACTUAL monthly insurance cost: $");
    return actual * totalMonths;
}

double electricCost() {
    budgetElectric = getPositiveDouble("Enter BUDGETED amount for electricity: $");
    double actual = getPositiveDouble("Enter ACTUAL monthly electricity cost: $");
    return actual * totalMonths;
}

double internetCost() {
    budgetInternet = getPositiveDouble("Enter BUDGETED amount for internet: $");
    double actual = getPositiveDouble("Enter ACTUAL monthly internet cost: $");
    return actual * totalMonths;
}

double waterCost() {
    budgetWater = getPositiveDouble("Enter BUDGETED amount for water: $");
    double actual = getPositiveDouble("Enter ACTUAL monthly water cost: $");
    return actual * totalMonths;
}

double gasCost() {
    budgetGas = getPositiveDouble("Enter BUDGETED amount for gas: $");
    double actual = getPositiveDouble("Enter ACTUAL monthly gas cost: $");
    return actual * totalMonths;
}

double groceriesCost() {
    budgetGroceries = getPositiveDouble("Enter BUDGETED amount for groceries: $");
    double actual = getPositiveDouble("Enter ACTUAL monthly groceries cost: $");
    return actual * totalMonths;
}

double restaurantCost() {
    budgetRestaurants = getPositiveDouble("Enter BUDGETED amount for restaurants: $");
    double actual = getPositiveDouble("Enter ACTUAL monthly restaurant cost: $");
    return actual * totalMonths;
}

double maintenanceCost() {
    budgetMaintenance = getPositiveDouble("Enter BUDGETED amount for maintenance: $");
    double actual = getPositiveDouble("Enter ACTUAL monthly maintenance cost: $");
    return actual * totalMonths;
}

double renovationCost() {
    budgetRenovation = getPositiveDouble("Enter BUDGETED amount for renovations: $");
    double actual = getPositiveDouble("Enter ACTUAL monthly renovation cost: $");
    return actual * totalMonths;
}

// ========================= TOTAL EXPENSES =========================

void totalExpenses() {
    double total =
        totalHousing + totalInsurance +
        totalElectric + totalInternet + totalWater + totalGas +
        totalGroceries + totalRestaurants +
        totalMaintenance + totalRenovation;

    cout << fixed << setprecision(2);
    cout << "\n=== TOTAL EXPENSES ===\n";
    cout << "Total Expenses for " << totalMonths << " month(s): $" << total << "\n\n";
}

// ========================= TOTAL BUDGET =========================

double totalBudget() {
    return
        budgetHousing + budgetInsurance +
        budgetElectric + budgetInternet + budgetWater + budgetGas +
        budgetGroceries + budgetRestaurants +
        budgetMaintenance + budgetRenovation;
}

// ========================= BUDGET COMPARISON =========================

void budgetComparisons() {
    double actual =
        totalHousing + totalInsurance +
        totalElectric + totalInternet + totalWater + totalGas +
        totalGroceries + totalRestaurants +
        totalMaintenance + totalRenovation;

    double budget = totalBudget();

    cout << fixed << setprecision(2);

    cout << "\n=== BUDGET COMPARISON ===\n";
    cout << "Total Budget:   $" << budget << "\n";
    cout << "Total Expenses: $" << actual << "\n";

    if (actual > budget)
        cout << "You are OVER budget by $" << actual - budget << "\n\n";
    else
        cout << "You are UNDER budget by $" << budget - actual << "\n\n";
}

// ========================= CATEGORY REPORT (COLOR CODED) =========================

void categoryReport() {
    cout << "\n=== CATEGORY-BY-CATEGORY REPORT ===\n";
    cout << fixed << setprecision(2);

    struct Category {
        string name;
        double budget;
        double actual;
    };

    // List of categories for easy looping
    Category categories[] = {
        {"Housing (Mortgage/Rent)", budgetHousing, totalHousing},
        {"Insurance", budgetInsurance, totalInsurance},
        {"Electricity", budgetElectric, totalElectric},
        {"Internet", budgetInternet, totalInternet},
        {"Water", budgetWater, totalWater},
        {"Gas", budgetGas, totalGas},
        {"Groceries", budgetGroceries, totalGroceries},
        {"Restaurants", budgetRestaurants, totalRestaurants},
        {"Maintenance", budgetMaintenance, totalMaintenance},
        {"Renovation", budgetRenovation, totalRenovation}
    };

 // Loop through each category
    for (auto &c : categories) {
        double diff = c.actual - c.budget;

        // Choose color based on over/under budget
        string color;
        if (diff > 0) {
            color = "\033[31m"; // Red = over budget
        } else if (diff < 0) {
            color = "\033[32m"; // Green = under budget
        } else {
            color = "\033[0m"; // White = on budget
        }
        
        cout << "\n" << c.name << ":\n";
        cout << "  Budgeted: $" << c.budget << "\n";
        cout << "  Actual:   $" << c.actual << "\n";

        cout << "  Status: " << color;

        if (diff > 0) {
            cout << "OVER by $" << diff;
        } else if (diff < 0) {
            cout << "UNDER by $" << -diff;
        } else {
            cout << "Exactly on budget";
        }
        
        cout << "\033[0m\n"; // Reset color
    }

    cout << endl;
}
