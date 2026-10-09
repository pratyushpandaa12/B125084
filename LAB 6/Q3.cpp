
#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    double price;

public:
    Book(string t = "", double p = 0) {
        title = t;
        price = p;
    }

    bool operator<(const Book& b) const {
        if (price == b.price)
            return title < b.title;

        return price < b.price;
    }

    void display() const {
        cout << "Title: " << title
             << ", Price: Rs. " << price << endl;
    }
};

int main() {
    string t1, t2;
    double p1, p2;

    cout << "Enter first book title: ";
    getline(cin, t1);
    cout << "Enter first book price: ";
    cin >> p1;
    cin.ignore();

    cout << "Enter second book title: ";
    getline(cin, t2);
    cout << "Enter second book price: ";
    cin >> p2;

    Book b1(t1, p1), b2(t2, p2);

    cout << "\nFirst book:\n";
    b1.display();

    cout << "Second book:\n";
    b2.display();

    if (b1 < b2)
        cout << "First book is smaller.\n";
    else if (b2 < b1)
        cout << "Second book is smaller.\n";
    else
        cout << "Both books are equal.\n";

    return 0;
}