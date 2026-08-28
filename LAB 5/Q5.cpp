#include <iostream>
using namespace std;

// Swap integers using references
void swapData(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Swap floating-point values using references
void swapData(float &a, float &b)
{
    float temp = a;
    a = b;
    b = temp;
}

// Swap integers using pointers
void swapData(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    float x, y;
    int p, q;

    cout << "Enter two integers for reference swap: ";
    cin >> a >> b;

    cout << "Before swapping: " << a << " " << b << endl;
    swapData(a, b);
    cout << "After swapping: " << a << " " << b << endl;


    cout << "\nEnter two floating-point values: ";
    cin >> x >> y;

    cout << "Before swapping: " << x << " " << y << endl;
    swapData(x, y);
    cout << "After swapping: " << x << " " << y << endl;


    cout << "\nEnter two integers for pointer swap: ";
    cin >> p >> q;

    cout << "Before swapping: " << p << " " << q << endl;
    swapData(&p, &q);
    cout << "After swapping: " << p << " " << q << endl;

    return 0;
}