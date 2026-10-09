
#include <iostream>
using namespace std;

class AccountBalance {
    double balance;

public:
    AccountBalance(double b = 0) {
        balance = b;
    }

    AccountBalance operator-() const {
        return AccountBalance(-balance);
    }

    void display() const {
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main() {
    double amount;

    cout << "Enter account balance: Rs. ";
    cin >> amount;

    AccountBalance original(amount);
    AccountBalance adjusted = -original;

    cout << "\nOriginal account:\n";
    original.display();

    cout << "Negated account:\n";
    adjusted.display();

    cout << "Original balance after operation:\n";
    original.display();

    return 0;
}
