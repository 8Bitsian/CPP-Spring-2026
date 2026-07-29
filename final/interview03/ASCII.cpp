/*
    Imani Hollie 04/27/2026
    CIST 2361 CRN 48597
    Interview III: ASCII Code Program
    Directions: Create a C++ program that prompts the user to enter a single
    character and then displays the ASCII value associated with that character.
*/

// ========================== HEADER ===========================
#include <iostream>   // Provides console input/output
#include <string>     // Enables use of std::string
using namespace std;  // Allows use of standard names without std:: prefix

// ==================== FUNCTION PROTOTYPES ====================
void runProgram();                                          // Manages program flow
string getUserInput();                                      // Gets user input
bool validateInput(const string &input, char *validChar);   // Validates input
int getAsciiCode(char c);                                   // Converts char to ASCII
void displayAscii(char c, int asciiValue);                  // Displays results

// ======================== MAIN METHOD =========================
// main() : Program execution starts here
int main() {
    runProgram();   // Start the program
    return 0;       // End program
}

// ==================== FUNCTION DEFINITIONS ====================

// runProgram() : Controls the main loop and program logic
void runProgram() {
    string input;
    char validChar;
    
    cout << "\nEntering program...\n";  // Notify user program has started
    
    while (true) {  // Begin program loop
        
        input = getUserInput();  // Prompt user for input
        
        if (input == "EXIT") {   // Check for exit command
            cout << "\nExiting program...";
            break;               // Exit loop and end program
        }
        
        // Validate input and process if valid
        if (validateInput(input, &validChar)) {  // Validate input
            
            int asciiValue = getAsciiCode(validChar);  // Convert character to ASCII
            
            displayAscii(validChar, asciiValue);       // Display results
        }
    }
}

// getUserInput() : Prompts user for input and returns the full line
string getUserInput() {
    string input;
    cout << "\nEnter one character (EXIT to quit): ";  // Ask user for input
    getline(cin, input);                               // Read entire line
    return input;                                      // Return input
}

// validateInput() : Validates that input is exactly one printable ASCII character
bool validateInput(const string &input, char *validChar) {
    
    if (input.length() == 0) {  // Check for empty input
        cout << "\nERROR: Invalid Input - Input cannot be empty.\n";
        return false;
    }
    
    if (input.length() > 1) {   // Ensure only one character was entered
        cout << "\nERROR: Invalid Input - Please enter exactly ONE character.\n";
        return false;
    }

    char c = input[0];          // Extract the character
    
    if (c < 32 || c > 127) {    // Check printable ASCII range
        cout << "\nERROR: Invalid Input - Character must be in ASCII range 32–127.\n";
        return false;
    }

    *validChar = c;             // Store valid character
    return true;                // Input is valid
}

// getAsciiCode() : Returns ASCII integer value of the character
int getAsciiCode(char c) {
    return int(c);              // Convert char to ASCII integer
}

// displayAscii() : Displays the character and its ASCII code
void displayAscii(char c, int asciiValue) {
    cout << "\nCharacter entered: " << c << endl;      // Show character
    cout << "ASCII code: " << asciiValue << endl;      // Show ASCII value
}
