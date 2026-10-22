// Inventory Management System using Array of Structures
// Note: enter names without spaces (use Pen_Box instead of "Pen Box")

#include <iostream>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    string category;
    int quantity;
    float price;
};

Product item[100];   // stores up to 100 products
int total = 0;       // number of products currently stored

// returns position of product with given ID, or -1 if not found
int findProduct(int id) {
    for (int i = 0; i < total; i++) {
        if (item[i].id == id)
            return i;
    }
    return -1;
}

void addProduct() {
    if (total == 100) {
        cout << "Inventory is full.\n";
        return;
    }

    int id;
    cout << "Enter ID: ";
    cin >> id;

    if (findProduct(id) != -1) {
        cout << "ID already exists!\n";
        return;
    }

    item[total].id = id;
    cout << "Enter Name: ";
    cin >> item[total].name;
    cout << "Enter Category: ";
    cin >> item[total].category;
    cout << "Enter Quantity: ";
    cin >> item[total].quantity;
    cout << "Enter Price: ";
    cin >> item[total].price;

    total++;
    cout << "Product added.\n";
}

void deleteProduct() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    int pos = findProduct(id);
    if (pos == -1) {
        cout << "Product not found.\n";
        return;
    }

    // shift all products after pos one step left
    for (int i = pos; i < total - 1; i++) {
        item[i] = item[i + 1];
    }
    total--;
    cout << "Product deleted.\n";
}

void updateProduct() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    int pos = findProduct(id);
    if (pos == -1) {
        cout << "Product not found.\n";
        return;
    }

    cout << "Enter new Name: ";
    cin >> item[pos].name;
    cout << "Enter new Category: ";
    cin >> item[pos].category;
    cout << "Enter new Quantity: ";
    cin >> item[pos].quantity;
    cout << "Enter new Price: ";
    cin >> item[pos].price;
    cout << "Product updated.\n";
}

void searchProduct() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    int pos = findProduct(id);
    if (pos == -1) {
        cout << "Product not found.\n";
        return;
    }

    cout << "ID\tName\tCategory\tQty\tPrice\n";
    cout << item[pos].id << "\t" << item[pos].name << "\t"
         << item[pos].category << "\t" << item[pos].quantity << "\t"
         << item[pos].price << endl;
}

void displayProducts() {
    if (total == 0) {
        cout << "Inventory is empty.\n";
        return;
    }

    cout << "ID\tName\tCategory\tQty\tPrice\n";
    for (int i = 0; i < total; i++) {
        cout << item[i].id << "\t" << item[i].name << "\t"
             << item[i].category << "\t" << item[i].quantity << "\t"
             << item[i].price << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- INVENTORY MANAGEMENT SYSTEM ---\n";
        cout << "1. Add Product\n";
        cout << "2. Delete Product\n";
        cout << "3. Update Product\n";
        cout << "4. Search Product\n";
        cout << "5. Display All Products\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addProduct(); break;
            case 2: deleteProduct(); break;
            case 3: updateProduct(); break;
            case 4: searchProduct(); break;
            case 5: displayProducts(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}