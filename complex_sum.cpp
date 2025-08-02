// Program to define a class for complex numbers, calculate their sum, and display the result.

#include <iostream>
using namespace std;

class Complex {
private:
    float real;      // To store the real part
    float imag;      // To store the imaginary part

public:
    // Function to set the real and imaginary parts
    void set(float r, float i) {
        real = r;
        imag = i;
    }

    // Function to display the complex number
    void disp() {
        cout << real << " + " << imag << "i" << endl;
    }

    // Function to return the sum of two complex numbers
    Complex sum(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
};

int main() {
    Complex c1, c2, c3;  // Creating three complex number objects

    // Setting values for the first complex number
    c1.set(3.5, 2.5);

    // Setting values for the second complex number
    c2.set(1.5, 4.5);

    // Calculating the sum of c1 and c2, storing in c3
    c3 = c1.sum(c2);

    // Displaying all complex numbers
    cout << "First complex number: ";
    c1.disp();

    cout << "Second complex number: ";
    c2.disp();

    cout << "Sum of the two complex numbers: ";
    c3.disp();

    return 0;
}
