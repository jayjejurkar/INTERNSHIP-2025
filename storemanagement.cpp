#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Store {
public:
    void showMenu();
    void addItem();
    void viewItems();
    void searchItem();
    void updateItem();
    void deleteItem();
};

void Store::showMenu() {
    system("cls");
    cout << "====== Department Store ======\n";
    cout << "1. Add Item\n";
    cout << "2. View All Items\n";
    cout << "3. Search Item\n";
    cout << "4. Update Item\n";
    cout << "5. Delete Item\n";
    cout << "6. Exit\n";
}

void Store::addItem() {
    ofstream file("D://items.txt", ios::app);
    int code, qty;
    string name, brand;

    cout << "\nEnter Item Code: ";
    cin >> code;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Brand: ";
    cin >> brand;
    cout << "Enter Quantity: ";
    cin >> qty;

    file << code << " " << name << " " << brand << " " << qty << "\n";
    file.close();

    cout << "Item Added.\n";
}

void Store::viewItems() {
    ifstream file("D://items.txt");
    int code, qty;
    string name, brand;

    cout << "\n--- Item List ---\n";
    while (file >> code >> name >> brand >> qty) {
        cout << "Code: " << code << ", Name: " << name << ", Brand: " << brand << ", Qty: " << qty << "\n";
    }
    file.close();
}

void Store::searchItem() {
    ifstream file("D://items.txt");
    int code, qty, searchCode;
    string name, brand;
    bool found = false;

    cout << "\nEnter Item Code to Search: ";
    cin >> searchCode;

    while (file >> code >> name >> brand >> qty) {
        if (code == searchCode) {
            cout << "Found - Name: " << name << ", Brand: " << brand << ", Qty: " << qty << "\n";
            found = true;
        }
    }

    if (!found)
        cout << "Item Not Found.\n";

    file.close();
}

void Store::updateItem() {
    ifstream file("D://items.txt");
    ofstream temp("D://temp.txt");

    int code, qty, newQty;
    string name, brand;
    int searchCode;
    bool found = false;

    cout << "\nEnter Item Code to Update: ";
    cin >> searchCode;

    while (file >> code >> name >> brand >> qty) {
        if (code == searchCode) {
            cout << "Enter New Name: ";
            cin >> name;
            cout << "Enter New Brand: ";
            cin >> brand;
            cout << "Enter New Quantity: ";
            cin >> newQty;

            temp << code << " " << name << " " << brand << " " << newQty << "\n";
            found = true;
        } else {
            temp << code << " " << name << " " << brand << " " << qty << "\n";
        }
    }

    file.close();
    temp.close();

    remove("D://items.txt");
    rename("D://temp.txt", "D://items.txt");

    if (found)
        cout << "Item Updated.\n";
    else
        cout << "Item Not Found.\n";
}

void Store::deleteItem() {
    ifstream file("D://items.txt");
    ofstream temp("D://temp.txt");

    int code, qty, deleteCode;
    string name, brand;
    bool found = false;

    cout << "\nEnter Item Code to Delete: ";
    cin >> deleteCode;

    while (file >> code >> name >> brand >> qty) {
        if (code != deleteCode) {
            temp << code << " " << name << " " << brand << " " << qty << "\n";
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("D://items.txt");
    rename("D://temp.txt", "D://items.txt");

    if (found)
        cout << "Item Deleted.\n";
    else
        cout << "Item Not Found.\n";
}

int main() {
    Store shop;
    int choice;
    char again;

    do {
        shop.showMenu();
        cout << "\nChoose Option: ";
        cin >> choice;

        switch (choice) {
            case 1: shop.addItem(); break;
            case 2: shop.viewItems(); break;
            case 3: shop.searchItem(); break;
            case 4: shop.updateItem(); break;
            case 5: shop.deleteItem(); break;
            case 6: exit(0);
            default: cout << "Invalid choice.\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();

    } while (true);

    return 0;
}
