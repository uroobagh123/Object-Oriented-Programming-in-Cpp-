// This program defines a class 'Invoice' for handling store item invoices, ensuring valid input and calculating the total amount.

#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    int pricePerItem;

public:
    // Constructor
    Invoice(string pNumber, string pDescription, int qty, int price) {
        partNumber = pNumber;
        partDescription = pDescription;
        setQuantity(qty);         // Ensure quantity is valid
        setPricePerItem(price);   // Ensure price is valid
    }

    // Setters
    void setPartNumber(string pNumber) {
        partNumber = pNumber;
    }

    void setPartDescription(string pDescription) {
        partDescription = pDescription;
    }

    void setQuantity(int qty) {
        quantity = (qty > 0) ? qty : 0;
    }

    void setPricePerItem(int price) {
        pricePerItem = (price > 0) ? price : 0;
    }

    // Getters
    string getPartNumber() const {
        return partNumber;
    }

    string getPartDescription() const {
        return partDescription;
    }

    int getQuantity() const {
        return quantity;
    }

    int getPricePerItem() const {
        return pricePerItem;
    }

    // Function to calculate invoice amount
    int getInvoiceAmount() const {
        return quantity * pricePerItem;
    }
};

// Main function to test the Invoice class
int main() {
    string number, description;
    int qty, price;

    cout << "Enter part number: ";
    getline(cin, number);

    cout << "Enter part description: ";
    getline(cin, description);

    cout << "Enter quantity: ";
    cin >> qty;

    cout << "Enter price per item: ";
    cin >> price;

    // Create an Invoice object
    Invoice item(number, description, qty, price);

    // Display invoice details
    cout << "\n--- Invoice Summary ---\n";
    cout << "Part Number     : " << item.getPartNumber() << endl;
    cout << "Description     : " << item.getPartDescription() << endl;
    cout << "Quantity        : " << item.getQuantity() << endl;
    cout << "Price Per Item  : Rs." << item.getPricePerItem() << endl;
    cout << "Total Amount    : Rs." << item.getInvoiceAmount() << endl;

    return 0;
}
