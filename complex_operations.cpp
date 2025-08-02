//This program demonstrates operations on complex numbers using a separate Operations class

#include <iostream>
using namespace std;

// Class to represent a Complex number
class Complex {
private:
    int real;   // Real part of the complex number
    int imag;   // Imaginary part of the complex number

public:
    // Constructor with default parameters
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    // Grant access to private members for Operations class
    friend class Operations;

    // Function to display a complex number in a + bi format
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

// Class that performs operations on Complex numbers
class Operations {
public:
    // Function to add two complex numbers
    Complex add(Complex c1, Complex c2) {
        Complex result;  // Create a result Complex object
        result.real = c1.real + c2.real;  // Add real parts
        result.imag = c1.imag + c2.imag;  // Add imaginary parts
        return result;  // Return result
    }

    // Function to subtract two complex numbers
    Complex subtract(Complex c1, Complex c2) {
        Complex result;  // Create a result Complex object
        result.real = c1.real - c2.real;  // Subtract real parts
        result.imag = c1.imag - c2.imag;  // Subtract imaginary parts
        return result;  // Return result
    }
};

// Main function
int main() {
    // Create two Complex number objects
    Complex num1(6, 4);     // 6 + 4i
    Complex num2(2, 1);     // 2 + 1i

    // Create an Operations object to perform operations
    Operations op;

    // Add the complex numbers using Operations class
    Complex sum = op.add(num1, num2);

    // Subtract the complex numbers using Operations class
    Complex diff = op.subtract(num1, num2);

    // Display inputs and results
    cout << "First Complex Number: ";
    num1.display();

    cout << "Second Complex Number: ";
    num2.display();

    cout << "Sum: ";
    sum.display();

    cout << "Difference: ";
    diff.display();

    return 0;  // End of program
}
