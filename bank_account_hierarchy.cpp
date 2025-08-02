//A program demonstrating inheritance in a bank system: Account, SavingsAccount, and CheckingAccount.

#include <iostream>
using namespace std;

// Base class: Account
class Account {
protected:
    double balance;

public:
    Account(double initialBalance) {
        if (initialBalance >= 0.0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            cout << "Error: Initial balance invalid. Balance set to 0.0" << endl;
        }
    }

    virtual void credit(double amount) {
        balance += amount;
    }

    // Returns true if debit successful, false if not
    virtual bool debit(double amount) {
        if (amount > balance) {
            cout << "Debit amount exceeded account balance." << endl;
            return false;
        } else {
            balance -= amount;
            return true;
        }
    }

    double getBalance() const {
        return balance;
    }
};

// Derived class: SavingsAccount
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double rate)
        : Account(initialBalance) {
        interestRate = rate;
    }

    double calculateInterest() {
        return balance * interestRate;
    }
};

// Derived class: CheckingAccount
class CheckingAccount : public Account {
private:
    double transactionFee;

    void chargeFee() {
        balance -= transactionFee;
    }

public:
    CheckingAccount(double initialBalance, double fee)
        : Account(initialBalance) {
        transactionFee = fee;
    }

    void credit(double amount) override {
        Account::credit(amount);
        chargeFee();
    }

    bool debit(double amount) override {
        bool success = Account::debit(amount);
        if (success) {
            chargeFee();
        }
        return success;
    }
};

// Test program
int main() {
    cout << "Creating Savings Account with balance 1000 and interest rate 5%" << endl;
    SavingsAccount savings(1000.0, 0.05);

    cout << "Creating Checking Account with balance 1000 and transaction fee 2" << endl;
    CheckingAccount checking(1000.0, 2.0);

    // SavingsAccount test
    double interest = savings.calculateInterest();
    cout << "\nSavings Account Interest Earned: " << interest << endl;
    savings.credit(interest);
    cout << "Savings Account Balance after adding interest: " << savings.getBalance() << endl;

    // CheckingAccount test
    cout << "\nDepositing 100 in Checking Account" << endl;
    checking.credit(100.0);
    cout << "Checking Account Balance: " << checking.getBalance() << endl;

    cout << "Withdrawing 200 from Checking Account" << endl;
    checking.debit(200.0);
    cout << "Checking Account Balance: " << checking.getBalance() << endl;

    cout << "Attempting to withdraw 2000 (exceeds balance)" << endl;
    checking.debit(2000.0);
    cout << "Checking Account Balance: " << checking.getBalance() << endl;

    return 0;
}
