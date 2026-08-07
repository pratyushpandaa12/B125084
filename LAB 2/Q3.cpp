#include <iostream>
using namespace std;

class Temperature
{
private:
    float celsius;
    float fahrenheit;

public:
    void accept()
    {
        cout << "Enter temperature in Celsius: ";
        cin >> celsius;
    }

    void convert()
    {
        fahrenheit = (9.0 / 5.0) * celsius + 32.0;
    }

    void display()
    {
        cout << "\n----- Temperature Details -----" << endl;
        cout << "Celsius    : " << celsius << " °C" << endl;
        cout << "Fahrenheit : " << fahrenheit << " °F" << endl;
    }
};

int main()
{
    Temperature t;

    t.accept();
    t.convert();
    t.display();

    return 0;
}