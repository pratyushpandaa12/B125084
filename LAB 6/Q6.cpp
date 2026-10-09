
#include <iostream>
using namespace std;

class Date {
    int day, month, year;

public:
    Date(int d = 1, int m = 1, int y = 2000) {
        day = d;
        month = m;
        year = y;
    }

    bool operator==(const Date& d) const {
        return day == d.day &&
               month == d.month &&
               year == d.year;
    }

    bool operator!=(const Date& d) const {
        return !(*this == d);
    }

    void display() const {
        cout << day << "/" << month << "/" << year;
    }
};

int main() {
    int d1, m1, y1, d2, m2, y2;

    cout << "Enter first date (day month year): ";
    cin >> d1 >> m1 >> y1;

    cout << "Enter second date (day month year): ";
    cin >> d2 >> m2 >> y2;

    Date date1(d1, m1, y1);
    Date date2(d2, m2, y2);

    cout << "\nFirst date: ";
    date1.display();

    cout << "\nSecond date: ";
    date2.display();

    cout << "\n\nAre dates equal? "
         << (date1 == date2 ? "Yes" : "No");

    cout << "\nAre dates unequal? "
         << (date1 != date2 ? "Yes" : "No");

    cout << endl;
    return 0;
}
