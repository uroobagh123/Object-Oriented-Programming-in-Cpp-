// This program simulates the behavior of a Skimmer — a hybrid vehicle that can both swim like a boat and fly like a plane. It uses protected inheritance from Boat and Plane classes.

#include <iostream>
using namespace std;

// Boat class
class Boat {
protected:
    float boatLength;

public:
    Boat(float length) {
        boatLength = length;
    }

    void swim() {
        cout << "I am swimming." << endl;
    }
};

// Plane class
class Plane {
protected:
    float maxAltitude;

public:
    Plane(float altitude) {
        maxAltitude = altitude;
    }

    void fly() {
        cout << "I am flying." << endl;
    }
};

// Skimmer class - derived from Boat and Plane using protected inheritance
class Skimmer : protected Boat, protected Plane {
private:
    int numPassengers;

public:
    Skimmer(float length, float altitude, int passengers)
        : Boat(length), Plane(altitude) {
        numPassengers = passengers;
    }

    void display() {
        cout << "Skimmer Details:" << endl;
        cout << "Boat Length: " << boatLength << " meters" << endl;
        cout << "Max Altitude: " << maxAltitude << " meters" << endl;
        cout << "Number of Passengers: " << numPassengers << endl;
    }

    void swimAndFly() {
        swim(); // Call swim from Boat
        fly();  // Call fly from Plane
    }
};

// Main function
int main() {
    // Create Skimmer object with length=20m, altitude=1000m, passengers=6
    Skimmer s(20.0, 1000.0, 6);

    s.display();
    s.swimAndFly();

    return 0;
}
