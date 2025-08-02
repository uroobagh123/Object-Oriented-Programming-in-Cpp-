//This program demonstrates inheritance in C++.

#include <iostream>
#include <string>
using namespace std;

// Base class
class Animal {
public:
    string name;
    int age;

    Animal(string n, int a) {
        name = n;
        age = a;
    }

    virtual void speak() {}  // Virtual for overriding
};

// Derived class Bird (privately inherits Animal)
class Bird : private Animal {
private:
    float wingLength;

public:
    Bird(string n, int a, float w) : Animal(n, a) {
        wingLength = w;
    }

    void speak() override {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "I am a Bird and I can sing!" << endl;
        cout << "Wing Length: " << wingLength << " cm\n" << endl;
    }
};

// Derived class Reptile (privately inherits Animal)
class Reptile : private Animal {
private:
    string habitat;

public:
    Reptile(string n, int a, string h) : Animal(n, a) {
        habitat = h;
    }

    void speak() override {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "I am a Reptile and I can creep!" << endl;
        cout << "Habitat: " << habitat << endl;
    }
};

// Main function
int main() {
    Bird b("Parrot", 3, 25.5);
    Reptile r("Lizard", 2, "Desert");

    b.speak();
    r.speak();

    return 0;
}
