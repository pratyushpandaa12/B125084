#include <iostream>
using namespace std;

class Inventory {
private:
    int playerID;
    int numberOfItems;
    int *quantity;

public:
    Inventory(int id, int n) {
        playerID = id;
        numberOfItems = n;

        quantity = new int[numberOfItems];

        for (int i = 0; i < numberOfItems; i++) {
            cout << "Enter quantity of item " << i + 1 << ": ";
            cin >> quantity[i];
        }
    }

    void display() {
        cout << "\nPlayer ID: " << playerID << endl;

        cout << "Item Quantities:\n";

        for (int i = 0; i < numberOfItems; i++) {
            cout << "Item " << i + 1
                 << ": " << quantity[i] << endl;
        }
    }

    // GameController can access private members
    friend class GameController;

    ~Inventory() {
        delete[] quantity;
    }
};

class GameController {
public:

    // Inspect private inventory information
    void inspectInventory(Inventory &inv) {
        cout << "\n--- Inventory Inspection ---\n";

        cout << "Player ID: " << inv.playerID << endl;
        cout << "Number of Items: " << inv.numberOfItems << endl;

        for (int i = 0; i < inv.numberOfItems; i++) {
            cout << "Item " << i + 1
                 << " Quantity: " << inv.quantity[i] << endl;
        }
    }

    // Modify private inventory information
    void changeQuantity(Inventory &inv, int position, int newQuantity) {

        if (position < 1 || position > inv.numberOfItems) {
            cout << "Invalid item position!\n";
            return;
        }

        inv.quantity[position - 1] = newQuantity;

        cout << "Quantity updated successfully.\n";
    }
};

int main() {
    int playerID;
    int numberOfItems;

    cout << "Enter Player ID: ";
    cin >> playerID;

    cout << "Enter number of items: ";
    cin >> numberOfItems;

    // Dynamic Inventory object
    Inventory *inventory = new Inventory(playerID, numberOfItems);

    GameController controller;

    controller.inspectInventory(*inventory);

    int position;
    int newQuantity;

    cout << "\nEnter item position to modify: ";
    cin >> position;

    cout << "Enter new quantity: ";
    cin >> newQuantity;

    controller.changeQuantity(*inventory, position, newQuantity);

    cout << "\n--- Updated Inventory ---\n";
    inventory->display();

    // Release dynamic memory
    delete inventory;

    return 0;
}