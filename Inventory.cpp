// A menu-driven program that models a grocery store's inventory system. Allows adding, displaying, updating, and searching items using an array of objects.

#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    int id;
    string name;
    float price;
    int quantity;

public:
    // Default constructor
    Item() {
        id = 0;
        name = "None";
        price = 0.0;
        quantity = 0;
    }

    // Parameterized constructor
    Item(int i, string n, float p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
    }

    // Destructor
    ~Item() {
        cout << "Item object with ID " << id << " destroyed.\n";
    }

    // Setters
    void setId(int i) { id = i; }
    void setName(string n) { name = n; }
    void setPrice(float p) { price = p; }
    void setQuantity(int q) { quantity = q; }

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    float getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    // Display method
    void displayItem() const {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Price: Rs." << price
             << " | Quantity: " << quantity << endl;
    }
};

// Function to display all items
void displayItems(Item items[], int size) {
    cout << "\n--- Inventory List ---\n";
    for (int i = 0; i < size; i++) {
        items[i].displayItem();
    }
}

// Function to update item (by reference)
void updateItem(Item &item) {
    int choice;
    cout << "\nUpdate Menu:\n1. Update Price\n2. Update Quantity\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        float newPrice;
        cout << "Enter new price: ";
        cin >> newPrice;
        item.setPrice(newPrice);
        cout << "Price updated successfully.\n";
    } else if (choice == 2) {
        int newQty;
        cout << "Enter new quantity: ";
        cin >> newQty;
        item.setQuantity(newQty);
        cout << "Quantity updated successfully.\n";
    } else {
        cout << "Invalid choice.\n";
    }
}

// Function to search for an item by ID
void searchItemByID(Item items[], int size, int searchId) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (items[i].getId() == searchId) {
            cout << "\nItem found:\n";
            items[i].displayItem();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item with ID " << searchId << " not found.\n";
    }
}

int main() {
    int totalItems;
    cout << "Enter total number of items: ";
    cin >> totalItems;

    // Create array of Item objects
    Item *items = new Item[totalItems];

    // Input item details
    for (int i = 0; i < totalItems; i++) {
        int id, qty;
        float price;
        string name;

        cout << "\nEnter details for item " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> id;
        cin.ignore(); // to handle getline properly
        cout << "Name: ";
        getline(cin, name);
        cout << "Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> qty;

        items[i] = Item(id, name, price, qty);
    }

    // Menu-driven loop
    int choice;
    do {
        cout << "\n--- Grocery Store Menu ---\n";
        cout << "1. Display Items\n";
        cout << "2. Update Item Details\n";
        cout << "3. Search Item by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayItems(items, totalItems);
                break;

            case 2: {
                int idToUpdate;
                cout << "Enter item ID to update: ";
                cin >> idToUpdate;
                bool found = false;
                for (int i = 0; i < totalItems; i++) {
                    if (items[i].getId() == idToUpdate) {
                        updateItem(items[i]);
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Item not found.\n";
                break;
            }

            case 3: {
                int searchId;
                cout << "Enter item ID to search: ";
                cin >> searchId;
                searchItemByID(items, totalItems, searchId);
                break;
            }

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    // Clean up memory
    delete[] items;

    return 0;
}
