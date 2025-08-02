//Calculates the volume of a sphere using user-input radius.

#include <iostream>
#include <cmath>  // for pow() and M_PI
using namespace std;

int main() {
    float radius, volume;

    // Input radius from user
    cout << "Enter the radius of the sphere: ";
    cin >> radius;

    // Volume formula: (4/3) * π * r^3
    volume = (4.0 / 3.0) * M_PI * pow(radius, 3);

    // Output the result
    cout << "The volume of the sphere is: " << volume << endl;

    return 0;
}
