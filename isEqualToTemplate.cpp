// Program to demonstrate a function template isEqualTo for comparing values using ==

#include <iostream>
#include <string>
using namespace std;

// Function template for equality comparison
template <typename T>
bool isEqualTo(T a, T b) {
    return a == b;
}

// User-defined class
class Person {
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    // Overload == operator
    bool operator==(const Person& other) const {
        return (name == other.name && age == other.age);
    }

    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    cout << boolalpha;

    // Built-in types
    cout << "5 == 5: " << isEqualTo(5, 5) << endl;
    cout << "5.5 == 5.5: " << isEqualTo(5.5, 5.5) << endl;
    cout << "'A' == 'B': " << isEqualTo('A', 'B') << endl;

    // User-defined type
    Person p1("Ali", 20);
    Person p2("Ali", 20);
    Person p3("Sara", 22);

    p1.display();
    p2.display();
    p3.display();

    cout << "p1 == p2: " << isEqualTo(p1, p2) << endl;
    cout << "p1 == p3: " << isEqualTo(p1, p3) << endl;

    return 0;
}
