#include "bits/stdc++.h"
using namespace std;

// Function to calculate the factorial of a number
unsigned int factorial(int num) {
    int result = 1;
    for (int i = num; i > 0; i--) {
        result *= i;
    }
    return result;
}

// Function to validate if the input is a number
bool isNumber(double& num) {
    cin >> num;
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input
        return false;
    }
    return true;
}

int main() {
    double firstNumber, secondNumber, result, memory = 0;
    char operation;
    char choice[10];
    set<char> validOperations = {'+', '-', '/', '*', '^', '!'};
    cout << "+ to add, - to subtract, * to multiply, / to divide, ^ to power, ! to factorial\n\n";
    
    start: // THE BEGINNING

    // Input the first number with validation
    cout << "Enter the first number: ";
    while (!isNumber(firstNumber)) {
        cout << "Invalid input. Please enter a number: ";
    }

    reused: //

    // Input the operator
    cout << "Enter the operator: ";
    cin >> operation;
    if (validOperations.find(operation) == validOperations.end()) {
        cout << "Invalid input\n";
        goto end;
    }

    // Perform the operation based on the input operator
    if (operation == '!') {
        result = factorial(static_cast<int>(firstNumber)); 
    } else {
        // Input the second number with validation
        cout << "Enter the second number: ";
        while (!isNumber(secondNumber)) {
            cout << "Invalid input. Please enter a number: ";
        }
        if (operation == '+') result = firstNumber + secondNumber;
        if (operation == '-') result = firstNumber - secondNumber;
        if (operation == '*') result = firstNumber * secondNumber;
        if (operation == '/') result = firstNumber / secondNumber;
        if (operation == '^') result = pow(firstNumber, secondNumber);
    }

    // Output the result
    cout << "=" << result << endl;

    // Memory operations
    cout << "\nType 'mi' to insert the number into memory, or 'mc' to clear memory\n";
    cin >> choice;

    if (!strcmp(choice, "mi")) memory = result; // Insert into memory
    else if (!strcmp(choice, "mc")) memory = 0; // Clear memory
    else cout << "command unknown, program will go on\n"; // Default case

    // Loop control options
    cout << "\nType 'restart' to start again from the beginning, 'reuse' to use the result, \n'mr' to reuse the number in the memory, or 'quit' to quit: ";
    cin >> choice; // Input the choice for the next step

    if (!strcmp(choice, "restart")) goto start; // Restart from the beginning
    if (!strcmp(choice, "reuse")) {
        firstNumber = result; 
        cout << firstNumber << endl; 
        goto reused; // Start with the result
    }
    if (!strcmp(choice, "mr")) {
        firstNumber = memory;
        cout << firstNumber << endl;
        goto reused; // Start with the memory
    }
    if (!strcmp(choice, "quit")) goto end; // Quit the program

    goto start; // Restart if none of the above options were chosen

    end: // To quit the program
    return 0;
}
