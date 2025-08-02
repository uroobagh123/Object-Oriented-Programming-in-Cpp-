//Takes two numbers from the user and performs basic arithmetic operations.

#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    // Input values from user
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    // Perform arithmetic operations
    cout << "\nResults:\n";
    cout << "Addition: " << num1 + num2 << endl;
    cout << "Subtraction: " << num1 - num2 << endl;
    
    if (num2 != 0) {
        cout << "Division: " << (float)num1 / num2 << endl;
        cout << "Remainder: " << num1 % num2 << endl;
    } else {
        cout << "Division and remainder cannot be performed (division by zero)." << endl;
    }

    cout << "Multiplication: " << num1 * num2 << endl;

    return 0;
}
