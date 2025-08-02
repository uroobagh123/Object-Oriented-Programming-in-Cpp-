// A program to calculate salaries of employees based on hours worked, including overtime.

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    string jobTitle;
    int hoursWorked;
    float hourlyRate;

public:
    // Default constructor
    Employee() {
        id = 0;
        name = "N/A";
        jobTitle = "N/A";
        hoursWorked = 0;
        hourlyRate = 0.0;
    }

    // Parameterized constructor (optional, for use if needed)
    Employee(int i, string n, string jt, int hw, float hr) {
        id = i;
        name = n;
        jobTitle = jt;
        hoursWorked = hw;
        hourlyRate = hr;
    }

    // Setters
    void setId(int i) { id = i; }
    void setName(string n) { name = n; }
    void setJobTitle(string jt) { jobTitle = jt; }
    void setHoursWorked(int hw) { hoursWorked = hw; }
    void setHourlyRate(float hr) { hourlyRate = hr; }

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getJobTitle() const { return jobTitle; }
    int getHoursWorked() const { return hoursWorked; }
    float getHourlyRate() const { return hourlyRate; }

    // Method to calculate salary
    float calcSalary() const {
        if (hoursWorked <= 40) {
            return hoursWorked * hourlyRate;
        } else {
            int overtime = hoursWorked - 40;
            float basePay = 40 * hourlyRate;
            float overtimePay = overtime * (2 * hourlyRate); // double pay for overtime
            return basePay + overtimePay;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee* employees = new Employee[n]; // dynamically create array

    // Input details for each employee
    for (int i = 0; i < n; i++) {
        int id, hours;
        float rate;
        string name, title;

        cout << "\nEnter details for employee " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> id;
        cin.ignore(); // Clear input buffer
        cout << "Name: ";
        getline(cin, name);
        cout << "Job Title: ";
        getline(cin, title);
        cout << "Hours Worked per Week: ";
        cin >> hours;
        cout << "Hourly Rate: ";
        cin >> rate;

        // Set the employee's data
        employees[i].setId(id);
        employees[i].setName(name);
        employees[i].setJobTitle(title);
        employees[i].setHoursWorked(hours);
        employees[i].setHourlyRate(rate);
    }

    // Display name and salary of each employee
    cout << "\n--- Employee Salaries ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << employees[i].getName()
             << " | Salary: Rs." << employees[i].calcSalary() << endl;
    }

    // Clean up
    delete[] employees;

    return 0;
}
