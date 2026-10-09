
#include <iostream>
using namespace std;

class InventoryItem {
    int productID;
    double unitPrice;
    int quantity;

public:
    InventoryItem(int id = 0, double price = 0,
                  int qty = 0) {
        productID = id;
        unitPrice = price;
        quantity = qty;
    }

    InventoryItem operator+(const InventoryItem& item) const {
        if (productID == item.productID &&
            unitPrice == item.unitPrice) {
            return InventoryItem(
                productID, unitPrice,
                quantity + item.quantity
            );
        }

        cout << "Error: Incompatible inventory items.\n";
        return *this;
    }

    void display() const {
        cout << "Product ID: " << productID
             << ", Unit price: Rs. " << unitPrice
             << ", Quantity: " << quantity << endl;
    }

    bool compatible(const InventoryItem& item) const {
        return productID == item.productID &&
               unitPrice == item.unitPrice;
    }
};

int main() {
    int id1, id2, q1, q2;
    double p1, p2;

    cout << "Enter first item (ID price quantity): ";
    cin >> id1 >> p1 >> q1;

    cout << "Enter second item (ID price quantity): ";
    cin >> id2 >> p2 >> q2;

    InventoryItem item1(id1, p1, q1);
    InventoryItem item2(id2, p2, q2);

    cout << "\nFirst item:\n";
    item1.display();

    cout << "Second item:\n";
    item2.display();

    if (item1.compatible(item2)) {
        InventoryItem combined = item1 + item2;
        cout << "\nCombined inventory:\n";
        combined.display();
    } else {
        cout << "\nCannot combine items because "
             << "product IDs or unit prices differ.\n";
    }

    cout << "\nOriginal items after operation:\n";
    item1.display();
    item2.display();

    return 0;
}
