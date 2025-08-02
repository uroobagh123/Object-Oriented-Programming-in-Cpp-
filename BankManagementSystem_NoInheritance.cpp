// Simple Bank Management System using classes (no inheritance)

#include <iostream>
#include <string>
using namespace std;
class BankAccount{
private:
    int accountNumber;
    string accountHolder;
    double balance;
    static int nextAccountNumber;
    static int totalAccounts;
public:
    BankAccount(const string accountHolder="N/A", double balance=0.0){
        accountNumber=nextAccountNumber++;
        this->accountHolder=accountHolder;
        this->balance=balance;
        totalAccounts++;
    }
    void deposit(double amount){
        if (amount>0){
            balance=balance+amount;
            cout<<"$"<<amount<<" deposited. new balance: $"<<balance<<endl;
        } else{
            cout<<"invalid amount deposited"<<endl;
        }
    }
    bool withdraw(double amount){
        if (amount<=0){
            cout<<"invalid amount for withdrawal"<<endl;
            return false;
        }
        if (amount>balance){
            cout<<"insufficient balance"<<endl;
            return false;
        }
        balance=balance-amount;
        cout<<"$"<<amount<<" withdrawn. new balance: $"<<balance<<endl;
        return true;
    }
    double getBalance()const{
        return balance;
    }
    int getAccountNumber()const{
        return accountNumber;
    }
    static int getTotalAccounts(){
        return totalAccounts;
    }
    string getAccountHolder()const{
        return accountHolder;
    }
};
int BankAccount::nextAccountNumber=1;
int BankAccount::totalAccounts=0;
class BankManager{
private:
    static const int maxNoOfAccounts=100;
    BankAccount* accounts[maxNoOfAccounts];
    int noOfAccounts;
public:
    BankManager():noOfAccounts(0){}
    ~BankManager(){
        for (int i=0; i<noOfAccounts; i++){
            delete accounts[i];
        }
    }
    BankAccount* createAccount(const string& accountHolder, double balance=0.0){
        if (noOfAccounts<maxNoOfAccounts){
            BankAccount* account=new BankAccount(accountHolder, balance);
            accounts[noOfAccounts]=account;
            noOfAccounts++;
            return account;
        } else {
            cout<<"max limit reached. new account cannot be created"<<endl;
            return nullptr;
        }
    }
    void deleteAccount(int accountNumber){
        for (int i=0; i<noOfAccounts; i++){
            if (accounts[i]->getAccountNumber()==accountNumber){
                delete accounts[i];
                for (int j=i; j<noOfAccounts-1; j++){
                    accounts[j]=accounts[j+1];
                }
                noOfAccounts--;
                cout<<"account number "<<accountNumber<<" has been deleted"<<endl;
                return;
            }
        }
        cout<<"account number "<<accountNumber<<" not found"<<endl;
    }
    BankAccount* findAccount(int accountNumber){
        for (int i=0; i<noOfAccounts; i++){
            if (accounts[i]->getAccountNumber()==accountNumber){
                return accounts[i];
            }
        }
        return nullptr;
    }
    void displayAllAccounts(){
        cout<<"bank accounts: "<<endl;
        for (int i=0; i<noOfAccounts; i++){
            cout<<"account number: "<<accounts[i]->getAccountNumber()<<endl;
            cout<<"account holder: "<<accounts[i]->getAccountHolder()<<endl;
            cout<<"balance: $"<<accounts[i]->getBalance()<<endl;
        }
    }
};
int main(){
    BankManager bankManager;
    int choice;
    string accountHolder;
    double balance;
    BankAccount* foundAccount=nullptr;
    do {
        cout<<"bank management system: "<<endl;
        cout<<"1: create account"<<endl;
        cout<<"2: delete account"<<endl;
        cout<<"3: find account"<<endl;
        cout<<"4: display all accounts"<<endl;
        cout<<"5: exit"<<endl;
        cout<<"enter choice: "<<endl;
        cin>>choice;
        switch (choice){
            case 1:
                cout<<"enter account holder's name: "<<endl;
                cin>>accountHolder;
                cout<<"enter initial balance: "<<endl;
                cin>>balance;
                bankManager.createAccount(accountHolder, balance);
                cout<<"account created"<<endl;
                break;
            case 2:
                int accountNumber;
                cout<<"enter account number to delete: "<<endl;
                cin>>accountNumber;
                bankManager.deleteAccount(accountNumber);
                break;
            case 3:
                int findAccountNumber;
                cout<<"enter account number to find: "<<endl;
                cin>>findAccountNumber;
                foundAccount=bankManager.findAccount(findAccountNumber);
                if (foundAccount){
                    cout<<"account found"<<endl;
                    cout<<"account number: "<<foundAccount->getAccountNumber()<<endl;
                    cout<<"account holder: "<<foundAccount->getAccountHolder()<<endl;
                    cout<<"balance: $"<<foundAccount->getBalance()<<endl;
                } else {
                    cout<<"account not found"<<endl;
                }
                break;
            case 4:
                bankManager.displayAllAccounts();
                break;
            case 5:
                cout<<"exiting"<<endl;
                break;
            default:
                cout<<"invalid choice. try again"<<endl;
        }
    } while (choice != 5);
}