//Calculates net salary after applying fund deduction rules.

#include <iostream>
using namespace std;

int main() {
    float salary, deduction = 0, netPay;

    // Input salary from user
    cout << "Enter your salary (Rs.): ";
    cin >> salary;

    // Apply deduction rules
    if (salary < 10000) {
        deduction = 0;
    } else if (salary >= 10000 && salary < 20000) {
        deduction = 1000;
    } else {
        deduction = salary * 0.07;
    }

    // Calculate net payable amount
    netPay = salary - deduction;

    // Output result
    cout << "Deduction: Rs." << deduction << endl;
    cout << "Net Payable Salary: Rs." << netPay << endl;

    return 0;
}
