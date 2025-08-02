// Demonstrates constructor overloading in a Student class using different parameter orders

#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    char sec;

public:
    // Default constructor
    Student() {
        setRollNo(0);
        setName("N/A");
        setSec('-');
    }

    // Constructor with name and section
    Student(string name, char sec) {
        setRollNo(0);
        setName(name);
        setSec(sec);
    }

    // Constructor with section and name (overloaded)
    Student(char sec, string name) {
        setRollNo(0);
        setName(name);
        setSec(sec);
    }

    void setRollNo(int rollNo) {
        this->rollNo = rollNo;
    }

    void setName(string name) {
        this->name = name;
    }

    void setSec(char sec) {
        this->sec = sec;
    }

    int getRollNo() {
        return rollNo;
    }

    string getName() {
        return name;
    }

    char getSec() {
        return sec;
    }

    void print() {
        cout << "roll no: " << getRollNo() << endl;
        cout << "name: " << getName() << endl;
        cout << "sec: " << getSec() << endl;
    }
};

int main() {
    Student ali;
    ali.print();

    Student waqas("waqas ali", 'A');
    waqas.print();

    Student mahad('C', "mahad imran");
    mahad.print();
}
