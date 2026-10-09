
#include <iostream>
using namespace std;

class Bill {
    int items;
    double amount;

public:
    Bill(int i = 0, double a = 0) {
        items = i;
        amount = a;
    }

    Bill operator+(const Bill& b) const {
        return Bill(items + b.items,
                    amount + b.amount);
    }

    bool operator>(const Bill& b) const {
        return amount > b.amount;
    }

    void display() const {
        cout << "Number of items: " << items
             << "\nTotal amount: Rs. " << amount
             << endl;
    }
};

int main() {
    int items1, items2;
    double amount1, amount2;

    cout << "Enter first bill (number of items, amount): ";
    cin >> items1 >> amount1;

    cout << "Enter second bill (number of items, amount): ";
    cin >> items2 >> amount2;

    Bill b1(items1, amount1);
    Bill b2(items2, amount2);

    Bill combined = b1 + b2;

    cout << "\nFirst bill:\n";
    b1.display();

    cout << "Second bill:\n";
    b2.display();

    cout << "Combined bill:\n";
    combined.display();

    cout << "\nIs first bill greater than second bill? "
         << (b1 > b2 ? "Yes" : "No") << endl;

    return 0;
}
