// A simple calculator that performs addition, subtraction, multiplication, and division on two user-input numbers using if-else.

#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char op;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    if (op == '+') {
        result = num1 + num2;
        cout << "Result: " << result << endl;
    }
    else if (op == '-') {
        result = num1 - num2;
        cout << "Result: " << result << endl;
    }
    else if (op == '*') {
        result = num1 * num2;
        cout << "Result: " << result << endl;
    }
    else if (op == '/') {
        if (num2 != 0) {
            result = num1 / num2;
            cout << "Result: " << result << endl;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
        }
    }
    else {
        cout << "Invalid operator entered." << endl;
    }

    return 0;
}
