// This program demonstrates the use of static data members and static functions in a class. It defines an Account class with account number, name, and a static counter to track total objects.

#include <iostream>
using namespace std;

class Account {
public:
    int accno;       // Account number
    string name;     // Account holder name
    static int count; // Static member to count objects

    // Constructor to initialize account number and name
    Account(int accno, string name) {
        this->accno = accno;
        this->name = name;
        count++; // Increment object count
    }

    // Function to display account details
    void display() {
        cout << "\nAccount no: " << accno << "\nAcc Name: " << name << endl;
    }

    // Static function to display total number of Account objects created
    static void displayCount() {
        cout << "\nTotal Objects: " << count << endl;
    }
};

// Static variable must be defined outside the class
int Account::count = 0;

int main() {
    // Creating Account objects
    Account a1(201, "Ali");
    Account a2(202, "Saad");
    Account a3(203, "Sharjeel");

    // Displaying account details
    a1.display();
    a2.display();
    a3.display();

    // Displaying the total count using object and class
    a1.displayCount();        // Via object
    Account::displayCount();  // Via class name

    return 0;
}
