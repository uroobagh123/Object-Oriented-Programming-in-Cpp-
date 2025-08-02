//Takes a grade as input and displays a corresponding message using switch.

#include <iostream>
using namespace std;

int main() {
    char grade;

    cout << "Enter your grade (A, B, C, D, F): ";
    cin >> grade;

    switch (grade) {
        case 'A':
        case 'a':
            cout << "Excellent" << endl;
            break;
        case 'B':
        case 'b':
            cout << "Very Good" << endl;
            break;
        case 'C':
        case 'c':
            cout << "Good" << endl;
            break;
        case 'D':
        case 'd':
            cout << "Poor" << endl;
            break;
        case 'F':
        case 'f':
            cout << "Fail" << endl;
            break;
        default:
            cout << "Invalid grade entered!" << endl;
    }

    return 0;
}
