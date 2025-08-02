//This program simulates rolling a dice using a class named Dice. It randomly generates numbers between 1 and 6, displays the result, and prints "Chakkaaaa" when the result is 6.

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

class Dice {
private:
    int value;

public:
    // Default constructor
    Dice() {
        value = 0;
    }

    // Setter method
    void setValue(int v) {
        value = v;
    }

    // Getter method
    int getValue() {
        return value;
    }

    // Method to roll the dice
    void roll() {
        value = rand() % 6 + 1;
        cout << "Side: " << value;
        if (value == 6) {
            cout << " (Chakkaaaa)";
        } else {
            cout << " (Better luck next time)";
        }
        cout << endl;
    }
};

int main() {
    srand(time(0)); // Seed the random number generator

    Dice d;
    char choice;

    do {
        cout << "Do you want to roll the dice? Y/N: ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            d.roll();
        } else if (choice == 'N' || choice == 'n') {
            cout << "(Program exits)" << endl;
            break;
        } else {
            cout << "Invalid input. Please enter Y or N." << endl;
        }

    } while (true);

    return 0;
}
