#include <iostream>
#include <cmath>
using namespace std;

// Two integers
int nearValue(int a, int b)
{
    if (abs(a) <= abs(b))
        return a;
    else
        return b;
}

// Two floating-point values
double nearValue(double a, double b)
{
    if (fabs(a) <= fabs(b))
        return a;
    else
        return b;
}

// Integer array
int nearValue(int arr[], int n)
{
    int nearest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (abs(arr[i]) < abs(nearest))
            nearest = arr[i];
    }

    return nearest;
}

int main()
{
    int a, b;
    double x, y;
    int n;

    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Integer closest to zero = "
         << nearValue(a, b) << endl;


    cout << "\nEnter two floating-point values: ";
    cin >> x >> y;

    cout << "Floating-point value closest to zero = "
         << nearValue(x, y) << endl;


    cout << "\nEnter size of integer array: ";
    cin >> n;

    int arr[100];

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Array element closest to zero = "
         << nearValue(arr, n) << endl;

    return 0;
}