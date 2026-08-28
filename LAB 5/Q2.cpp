#include <iostream>
using namespace std;

// Area of square
double area(double side)
{
    return side * side;
}

// Area of rectangle
double area(double length, double breadth)
{
    return length * breadth;
}

// Area of circle
double area(double radius, char s)
{
    return 3.14159 * radius * radius;
}

int main()
{
    double side, length, breadth;
    double radius;

    cout << "Enter side of square: ";
    cin >> side;

    cout << "Enter length of rectangle: ";
    cin >> length;

    cout << "Enter breadth of rectangle: ";
    cin >> breadth;

    cout << "Enter radius of circle: ";
    cin >> radius;

    cout << "\n--- Areas ---\n";
    cout << "Area of Square = " << area(side) << endl;
    cout << "Area of Rectangle = " << area(length, breadth) << endl;
    cout << "Area of Circle = " << area(radius,'c') << endl;

    return 0;
}