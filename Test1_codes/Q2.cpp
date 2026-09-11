#include <iostream>
using namespace std;

class Borrower {
private:
    int borrowerID;
    int overdueDays;
    double fine;

public:
    Borrower(int id, int days) {
        borrowerID = id;
        overdueDays = days;
        fine = 0;
    }

    // Fine using only overdue days
    void calculateFine(double ratePerDay) {
        fine = overdueDays * ratePerDay;
    }

    // Fine using overdue days and special rate
    void calculateFine(double ratePerDay, double specialRate) {
        fine = overdueDays * specialRate;
    }

    friend void compareFine(const Borrower &, const Borrower &);

    void display() {
        cout << "Borrower ID: " << borrowerID << endl;
        cout << "Overdue Days: " << overdueDays << endl;
        cout << "Fine: " << fine << endl;
    }
};

void compareFine(const Borrower &b1, const Borrower &b2) {
    cout << "\n--- Fine Comparison ---\n";

    if (b1.fine > b2.fine) {
        cout << "Borrower " << b1.borrowerID
             << " has the higher fine: " << b1.fine << endl;
    }
    else if (b2.fine > b1.fine) {
        cout << "Borrower " << b2.borrowerID
             << " has the higher fine: " << b2.fine << endl;
    }
    else {
        cout << "Both borrowers have the same fine: "
             << b1.fine << endl;
    }
}

int main() {
    int id1, days1;
    int id2, days2;

    cout << "Enter Borrower 1 ID: ";
    cin >> id1;

    cout << "Enter overdue days: ";
    cin >> days1;

    cout << "\nEnter Borrower 2 ID: ";
    cin >> id2;

    cout << "Enter overdue days: ";
    cin >> days2;

    Borrower *b1 = new Borrower(id1, days1);
    Borrower *b2 = new Borrower(id2, days2);

    double normalRate;

    cout << "\nEnter normal fine rate per day: ";
    cin >> normalRate;

    b1->calculateFine(normalRate);

    double specialRate;

    cout << "Enter special fine rate per day for Borrower 2: ";
    cin >> specialRate;

    b2->calculateFine(normalRate, specialRate);

    cout << "\n--- Borrower 1 ---\n";
    b1->display();

    cout << "\n--- Borrower 2 ---\n";
    b2->display();

    compareFine(*b1, *b2);

    delete b1;
    delete b2;

    return 0;
}