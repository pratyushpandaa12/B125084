
#include <iostream>
using namespace std;

class Duration {
    int hours, minutes;

public:
    Duration(int h = 0, int m = 0) {
        hours = h + m / 60;
        minutes = m % 60;
    }

    Duration operator+(const Duration& d) const {
        int totalMinutes = minutes + d.minutes;
        int totalHours = hours + d.hours;

        return Duration(totalHours, totalMinutes);
    }

    void display() const {
        cout << hours << " hours "
             << minutes << " minutes";
    }
};

int main() {
    int h1, m1, h2, m2;

    cout << "Enter first duration (hours minutes): ";
    cin >> h1 >> m1;

    cout << "Enter second duration (hours minutes): ";
    cin >> h2 >> m2;

    if (h1 < 0 || h2 < 0 || m1 < 0 || m2 < 0) {
        cout << "Invalid duration.\n";
        return 0;
    }

    Duration d1(h1, m1), d2(h2, m2);
    Duration result = d1 + d2;

    cout << "First duration: ";
    d1.display();

    cout << "\nSecond duration: ";
    d2.display();

    cout << "\nTotal duration: ";
    result.display();

    cout << endl;
    return 0;
}
