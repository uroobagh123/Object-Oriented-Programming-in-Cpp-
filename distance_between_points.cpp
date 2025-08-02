// C++ program to calculate the distance between two points using structure and a function.

#include <iostream>
#include <cmath> // for sqrt and pow
using namespace std;

// Structure to represent a point
struct Point {
    float x;
    float y;

    // Member function to set coordinates
    void set(float x_val, float y_val) {
        x = x_val;
        y = y_val;
    }
};

// Function to calculate distance between two points
float calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to display the distance
void displayDistance(float distance) {
    cout << "Distance between the two points: " << distance << endl;
}

int main() {
    Point point1, point2;

    // Input coordinates for the first point
    cout << "Enter x and y for Point 1: ";
    cin >> point1.x >> point1.y;

    // Input coordinates for the second point
    cout << "Enter x and y for Point 2: ";
    cin >> point2.x >> point2.y;

    // Calculate and display the distance
    float dist = calculateDistance(point1, point2);
    displayDistance(dist);

    return 0;
}
