// This program displays the size (in bytes) of basic C++ data types using the sizeof() operator: char, int, float, long, and double.

#include <iostream>
using namespace std;

int main() {
    cout << "Size of char   : " << sizeof(char)   << " byte" << endl;
    cout << "Size of int    : " << sizeof(int)    << " byte" << endl;
    cout << "Size of float  : " << sizeof(float)  << " byte" << endl;
    cout << "Size of long   : " << sizeof(long)   << " byte" << endl;
    cout << "Size of double : " << sizeof(double) << " byte" << endl;

    return 0;
}
