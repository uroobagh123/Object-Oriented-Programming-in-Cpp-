//A C++ program to manage a bank account using a class. It allows the user to create an account, deposit or withdraw money, and check balance using a menu.

#include <iostream>
#include <string>
using namespace std;

// Account class definition
class Account {
private:
    string name;
    double balance;

public:
    // Constructor
    Account() {
        name = "";
        balance = 0.0;
    }

    // Setter for name
    void setName(string n) {
        name = n;
    }

    // Setter for balance
    void setBalance(double b) {
        if (b >= 0)
            balance = b;
        else
            cout << "Balance cannot be negative.\n";
    }

    // Getter for name
    string getName() {
        return name;
    }

    // Getter for balance
    double getBalance() {
        return balance;
    }

    // Deposit method
    void depositAmount(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Withdraw method
    void withdrawAmount(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }
};

// Function to create and initialize account object
Account createAccount() {
    Account acc;
    string name;
    double initialBalance;

    cout << "Enter account holder name: ";
    getline(cin, name);

    cout << "Enter initial balance: ";
    cin >> initialBalance;
    cin.ignore(); // clear input buffer

    acc.setName(name);
    acc.setBalance(initialBalance);

    return acc;
}

int main() {
    Account myAccount = createAccount();
    int choice;
    double amount;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Display Balance\n";
        cout << "2. Deposit Amount\n";
        cout << "3. Withdraw Amount\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Account Holder: " << myAccount.getName() << "\n";
            cout << "Current Balance: Rs. " << myAccount.getBalance() << "\n";
            break;
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            myAccount.depositAmount(amount);
            break;
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            myAccount.withdrawAmount(amount);
            break;
        case 4:
            cout << "Exiting... Thank you!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
