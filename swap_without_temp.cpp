// Program to swap two numbers without using a third variable

#include <iostream>
using namespace std;

int main() {
    int a, b;

    // Taking input from the user
    cout << "Enter first number (a): ";
    cin >> a;

    cout << "Enter second number (b): ";
    cin >> b;

    // Swapping logic without using a third variable
    a = a + b;
    b = a - b;
    a = a - b;

    // Displaying results
    cout << "\nAfter swapping:\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
