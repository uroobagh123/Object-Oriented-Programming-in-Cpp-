//Demonstrates friend function to add two Complex numbers

#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imag;

public:
    // Constructor
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    // Friend function declaration
    friend Complex addComplex(Complex c1, Complex c2);

    // Display function
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

// Friend function definition
Complex addComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

// Main function
int main() {
    Complex num1(4, 5);
    Complex num2(3, -2);

    Complex sum = addComplex(num1, num2);

    cout << "First Complex Number: ";
    num1.display();

    cout << "Second Complex Number: ";
    num2.display();

    cout << "Sum: ";
    sum.display();

    return 0;
}
