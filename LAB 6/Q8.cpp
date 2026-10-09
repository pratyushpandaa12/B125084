
#include <iostream>
using namespace std;

class Temperature {
    double celsius;

public:
    Temperature(double c = 0) {
        celsius = c;
    }

    bool operator>(const Temperature& t) const {
        return celsius > t.celsius;
    }

    bool operator<(const Temperature& t) const {
        return celsius < t.celsius;
    }

    Temperature operator-() const {
        return Temperature(-celsius);
    }

    void display() const {
        cout << celsius << " degrees Celsius";
    }
};

int main() {
    double t1, t2;

    cout << "Enter first temperature in Celsius: ";
    cin >> t1;

    cout << "Enter second temperature in Celsius: ";
    cin >> t2;

    Temperature temp1(t1), temp2(t2);

    cout << "\nFirst temperature: ";
    temp1.display();

    cout << "\nSecond temperature: ";
    temp2.display();

    cout << "\n\nFirst > Second: "
         << (temp1 > temp2 ? "True" : "False");

    cout << "\nFirst < Second: "
         << (temp1 < temp2 ? "True" : "False");

    Temperature negated = -temp1;

    cout << "\nNegated first temperature: ";
    negated.display();

    cout << "\nOriginal first temperature: ";
    temp1.display();

    cout << endl;
    return 0;
}
