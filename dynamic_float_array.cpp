// C++ program that defines a class to manage a dynamic array of floats.

#include <iostream>
using namespace std;

class FloatArray {
private:
    float* arr;        // Pointer to dynamic array
    int size;          // Size of the array

public:
    // Constructor
    FloatArray(int s) {
        size = s;
        arr = new float[size]; // Dynamic memory allocation

        // Initialize array elements to 0.0
        for (int i = 0; i < size; ++i) {
            arr[i] = 0.0f;
        }
    }

    // Destructor
    ~FloatArray() {
        delete[] arr; // Free allocated memory
    }

    // Store a number in the array
    void store(int index, float value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        } else {
            cout << "Invalid index!" << endl;
        }
    }

    // Retrieve a number from the array
    float retrieve(int index) const {
        if (index >= 0 && index < size) {
            return arr[index];
        } else {
            cout << "Invalid index!" << endl;
            return 0.0f;
        }
    }

    // Find highest value in the array
    float highest() const {
        float max = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] > max) max = arr[i];
        }
        return max;
    }

    // Find lowest value in the array
    float lowest() const {
        float min = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] < min) min = arr[i];
        }
        return min;
    }

    // Calculate average of array elements
    float average() const {
        float sum = 0.0f;
        for (int i = 0; i < size; ++i) {
            sum += arr[i];
        }
        return sum / size;
    }
};

// Main function to demonstrate the class
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Create FloatArray object
    FloatArray numbers(n);

    // Input values
    for (int i = 0; i < n; ++i) {
        float value;
        cout << "Enter value for index " << i << ": ";
        cin >> value;
        numbers.store(i, value);
    }

    // Display values
    cout << "\nStored Values: ";
    for (int i = 0; i < n; ++i) {
        cout << numbers.retrieve(i) << " ";
    }

    // Display statistics
    cout << "\n\nHighest value: " << numbers.highest();
    cout << "\nLowest value: " << numbers.lowest();
    cout << "\nAverage value: " << numbers.average() << endl;

    return 0;
}
