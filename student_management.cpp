//Manages student names and course marks using structure and functions

#include <iostream>
#include <string>
using namespace std;

// Structure to store student data
struct Student {
    string name;
    int marks[3];
};

// Function to display data of all students
void Display_data(Student students[], int size) {
    cout << "\n--- Student Data ---\n";
    for (int i = 0; i < size; i++) {
        cout << "Student " << i + 1 << ": " << students[i].name << "\n";
        for (int j = 0; j < 3; j++) {
            cout << "  Course " << j + 1 << " Marks: " << students[i].marks[j] << "\n";
        }
        cout << "----------------------\n";
    }
}

// Function to change marks for a student
void Change_Marks(Student &student) {
    int courseNo, newMarks;
    cout << "Enter course number (1-3) to update marks: ";
    cin >> courseNo;
    
    if (courseNo < 1 || courseNo > 3) {
        cout << "Invalid course number!\n";
        return;
    }

    cout << "Enter new marks for course " << courseNo << ": ";
    cin >> newMarks;

    student.marks[courseNo - 1] = newMarks;
    cout << "Marks updated successfully.\n";
}

// Function to calculate average marks of a student
void Calc_Average_Marks(const Student &student) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += student.marks[i];
    }
    double average = sum / 3.0;
    cout << "Average marks of " << student.name << ": " << average << "\n";
}

int main() {
    const int numStudents = 2;
    Student students[numStudents];

    // Input data for students
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter name for Student " << i + 1 << ": ";
        cin.ignore();
        getline(cin, students[i].name);
        for (int j = 0; j < 3; j++) {
            cout << "Enter marks for course " << j + 1 << ": ";
            cin >> students[i].marks[j];
        }
    }

    Display_data(students, numStudents);

    // Modify marks for the first student
    cout << "\n--- Update Marks for " << students[0].name << " ---\n";
    Change_Marks(students[0]);

    // Re-display data
    Display_data(students, numStudents);

    // Calculate average for each student
    for (int i = 0; i < numStudents; i++) {
        Calc_Average_Marks(students[i]);
    }

    return 0;
}
