// Program demonstrating a simple Student class with constructors, setters, getters, and a print function

#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    char sec;

public:
    Student(int RollNo = 0, string name = "N/A", char sec = '-') {
        setRollNo(RollNo);
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
    Student ali(1, "ali imran", 'A');
    ali.print();
}
