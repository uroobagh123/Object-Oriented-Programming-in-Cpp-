//Reverses a 3-digit number entered by the user.

#include <iostream>
using namespace std;

int main() {
    int num, reversed = 0;

    // Input a 3-digit number
    cout << "Enter a three-digit number: ";
    cin >> num;

    // Check if it's a 3-digit number
    if (num >= 100 && num <= 999) {
        // Extract digits and reverse
        int hundreds = num / 100;
        int tens = (num / 10) % 10;
        int ones = num % 10;

        reversed = ones * 100 + tens * 10 + hundreds;

        cout << "Reversed number is: " << reversed << endl;
    } else {
        cout << "Error: Please enter a valid three-digit number." << endl;
    }

    return 0;
}
