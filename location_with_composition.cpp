// C++ program to demonstrate composition.

#include <iostream>
using namespace std;

// A simple Point class
class Point {
private:
    int x;
    int y;

public:
    // Constructor
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    // Display function
    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

// A Location class using composition
class Location {
private:
    Point Source;
    Point Destination;

public:
    // Constructor
    Location(Point src, Point dest) : Source(src), Destination(dest) {}

    // Display function
    void showLocation() const {
        cout << "Source: ";
        Source.display();
        cout << "\nDestination: ";
        Destination.display();
        cout << endl;
    }
};

// Main function
int main() {
    Point p1(2, 3);
    Point p2(7, 8);

    Location route(p1, p2);
    route.showLocation();

    return 0;
}
