//Program demonstrating inheritance: PersonData → CustomerData

#include <iostream>
#include <string>
using namespace std;

// Base class: PersonData
class PersonData {
private:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zip;
    string phone;

public:
    // Setters (mutators)
    void setLastName(const string& ln) { lastName = ln; }
    void setFirstName(const string& fn) { firstName = fn; }
    void setAddress(const string& addr) { address = addr; }
    void setCity(const string& c) { city = c; }
    void setState(const string& s) { state = s; }
    void setZip(const string& z) { zip = z; }
    void setPhone(const string& p) { phone = p; }

    // Getters (accessors)
    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getAddress() const { return address; }
    string getCity() const { return city; }
    string getState() const { return state; }
    string getZip() const { return zip; }
    string getPhone() const { return phone; }
};

// Derived class: CustomerData
class CustomerData : public PersonData {
private:
    int customerNumber;
    bool mailingList;

public:
    // Setters
    void setCustomerNumber(int num) { customerNumber = num; }
    void setMailingList(bool status) { mailingList = status; }

    // Getters
    int getCustomerNumber() const { return customerNumber; }
    bool getMailingList() const { return mailingList; }
};

// Main function to demonstrate usage
int main() {
    CustomerData customer;

    // Setting person details
    customer.setFirstName("Urooba");
    customer.setLastName("Gohar");
    customer.setAddress("123 Design Street");
    customer.setCity("Peshawar");
    customer.setState("KPK");
    customer.setZip("25000");
    customer.setPhone("0300-1234567");

    // Setting customer-specific details
    customer.setCustomerNumber(1001);
    customer.setMailingList(true);

    // Displaying customer info
    cout << "Customer Information:\n";
    cout << "----------------------\n";
    cout << "Name: " << customer.getFirstName() << " " << customer.getLastName() << endl;
    cout << "Address: " << customer.getAddress() << ", " << customer.getCity() << ", "
         << customer.getState() << " " << customer.getZip() << endl;
    cout << "Phone: " << customer.getPhone() << endl;
    cout << "Customer Number: " << customer.getCustomerNumber() << endl;
    cout << "Mailing List: " << (customer.getMailingList() ? "Yes" : "No") << endl;

    return 0;
}
