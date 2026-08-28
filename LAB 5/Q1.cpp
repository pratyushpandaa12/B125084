#include <iostream>
using namespace std;

// Kilometers to meters
int convert(int km)
{
    return km * 1000;
}

// Meters to centimeters
int convert(long m)
{
    return m * 100;
}

// Floating-point kilometers to meters
double convert(double km)
{
    return km * 1000;
}

int main()
{
    int km, meters;
    double decimalKm;

    cout << "Enter distance in kilometers (integer): ";
    cin >> km;

    cout << "Enter distance in meters: ";
    cin >> meters;

    cout << "Enter distance in kilometers (decimal): ";
    cin >> decimalKm;

    cout << "\n--- Converted Values ---\n";

    cout << km << " km = " << convert(km) << " meters" << endl;

    cout << meters << " meters = " << convert((long)meters)
         << " centimeters" << endl;

    cout << decimalKm << " km = " << convert(decimalKm)
         << " meters" << endl;

    return 0;
}