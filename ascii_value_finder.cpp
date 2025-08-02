// This program takes a single character input from the user and prints its corresponding ASCII value.

#include <iostream>
using namespace std;

int main() {
    char ch;
    
    cout << "Enter a character: ";
    cin >> ch;

    cout << "ASCII value of '" << ch << "' is: " << int(ch) << endl;

    return 0;
}
