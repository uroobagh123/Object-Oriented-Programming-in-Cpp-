// C++ program demonstrating composition by including a DOB class inside a Person class.

#include <iostream>
using namespace std;

// Date of Birth class
class DOB {
private:
    int day;
    int month;
    int year;

public:
    // Getters
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    // Setters
    void setDay(int day) { this->day = day; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }
};

// Person class
class Person {
private:
    string name;
    DOB date;

public:
    // Constructor
    Person(string name, int day, int month, int year) {
        this->name = name;
        this->date.setDay(day);
        this->date.setMonth(month);
        this->date.setYear(year);
    }

    // Set name
    void setName(string name) { this->name = name; }

    // Set date of birth
    void setDate(int day, int month, int year) {
        this->date.setDay(day);
        this->date.setMonth(month);
        this->date.setYear(year);
    }

    // Get name
    string getName() { return name; }

    // Get date as string
    string getDate() {
        return to_string(date.getDay()) + "/" + to_string(date.getMonth()) + "/" + to_string(date.getYear());
    }
};

// Main function
int main() {
    Person p("Khan", 28, 2, 1999);

    cout << "Name: " << p.getName() << endl;
    cout << "DOB: " << p.getDate() << endl;

    return 0;
}
