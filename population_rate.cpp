// C++ program that defines a Population class to calculate birth rate and death rate.

#include <iostream>
using namespace std;

class Population {
private:
    int population;
    int births;
    int deaths;

public:
    // Constructor with validation
    Population(int pop, int birth, int death) {
        setPopulation(pop);
        setBirths(birth);
        setDeaths(death);
    }

    // Setters with input validation
    void setPopulation(int pop) {
        if (pop < 1) {
            cout << "Invalid population. Setting to 1.\n";
            population = 1;
        } else {
            population = pop;
        }
    }

    void setBirths(int birth) {
        if (birth < 0) {
            cout << "Invalid number of births. Setting to 0.\n";
            births = 0;
        } else {
            births = birth;
        }
    }

    void setDeaths(int death) {
        if (death < 0) {
            cout << "Invalid number of deaths. Setting to 0.\n";
            deaths = 0;
        } else {
            deaths = death;
        }
    }

    // Getters for birth rate and death rate
    double getBirthRate() {
        return static_cast<double>(births) / population;
    }

    double getDeathRate() {
        return static_cast<double>(deaths) / population;
    }

    // Display function
    void display() {
        cout << "\n--- Population Statistics ---\n";
        cout << "Population: " << population << endl;
        cout << "Births: " << births << endl;
        cout << "Deaths: " << deaths << endl;
        cout << "Birth Rate: " << getBirthRate() << endl;
        cout << "Death Rate: " << getDeathRate() << endl;
    }
};

// Main function
int main() {
    int pop, births, deaths;

    // Taking input from user
    cout << "Enter population: ";
    cin >> pop;
    cout << "Enter number of births: ";
    cin >> births;
    cout << "Enter number of deaths: ";
    cin >> deaths;

    // Create Population object
    Population p(pop, births, deaths);

    // Display results
    p.display();

    return 0;
}
