// Program to demonstrate inheritance with Employee and ProductionWorker classes

#include <iostream>
#include <string>
using namespace std;

// Base class: Employee
class Employee {
private:
    string name;        // Employee name
    int number;         // Employee number
    string hireDate;    // Hire date

public:
    // Default constructor
    Employee() {
        name = "";
        number = 0;
        hireDate = "";
    }

    // Parameterized constructor
    Employee(string empName, int empNumber, string empHireDate) {
        name = empName;
        number = empNumber;
        hireDate = empHireDate;
    }

    // Setters (mutators)
    void setName(string empName) {
        name = empName;
    }

    void setNumber(int empNumber) {
        number = empNumber;
    }

    void setHireDate(string empHireDate) {
        hireDate = empHireDate;
    }

    // Getters (accessors)
    string getName() const {
        return name;
    }

    int getNumber() const {
        return number;
    }

    string getHireDate() const {
        return hireDate;
    }
};

// Derived class: ProductionWorker
class ProductionWorker : public Employee {
private:
    int shift;              // 1 = Day, 2 = Night
    double hourlyPayRate;   // Pay rate

public:
    // Default constructor
    ProductionWorker() : Employee() {
        shift = 1;
        hourlyPayRate = 0.0;
    }

    // Parameterized constructor
    ProductionWorker(string name, int number, string hireDate, int empShift, double payRate)
        : Employee(name, number, hireDate) {
        shift = empShift;
        hourlyPayRate = payRate;
    }

    // Setters
    void setShift(int empShift) {
        shift = empShift;
    }

    void setHourlyPayRate(double payRate) {
        hourlyPayRate = payRate;
    }

    // Getters
    int getShift() const {
        return shift;
    }

    double getHourlyPayRate() const {
        return hourlyPayRate;
    }

    // Display function
    void displayInfo() const {
        cout << "Employee Name: " << getName() << endl;
        cout << "Employee Number: " << getNumber() << endl;
        cout << "Hire Date: " << getHireDate() << endl;
        cout << "Shift: " << (shift == 1 ? "Day" : "Night") << endl;
        cout << "Hourly Pay Rate: $" << hourlyPayRate << endl;
    }
};

// Main function to demonstrate usage
int main() {
    // Create a ProductionWorker object using parameterized constructor
    ProductionWorker worker("Urooba Gohar", 9216, "01-Aug-2025", 2, 850.50);

    // Display employee information
    cout << "=== Production Worker Details ===" << endl;
    worker.displayInfo();

    return 0;
}
