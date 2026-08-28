#include <iostream>
using namespace std;

// Average of two integers
double evaluate(int a, int b)
{
    return (a + b) / 2.0;
}

// Average of three integers
double evaluate(int a, int b, int c)
{
    return (a + b + c) / 3.0;
}

// Average of two floating-point values
double evaluate(double a, double b)
{
    return (a + b) / 2.0;
}

// Average of integer array
double evaluate(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return (double)sum / n;
}

// Average of two integers using pointers
double evaluate(int *a, int *b)
{
    return (*a + *b) / 2.0;
}

int main()
{
    int a, b, c;
    double x, y;
    int n;

    // Two integers
    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Average of two integers = "
         << evaluate(a, b) << endl;


    // Three integers
    cout << "\nEnter three integers: ";
    cin >> a >> b >> c;

    cout << "Average of three integers = "
         << evaluate(a, b, c) << endl;


    // Two floating-point values
    cout << "\nEnter two floating-point values: ";
    cin >> x >> y;

    cout << "Average of two floating-point values = "
         << evaluate(x, y) << endl;


    // Integer array
    cout << "\nEnter size of integer array: ";
    cin >> n;

    int arr[100];

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Average of array = "
         << evaluate(arr, n) << endl;


    // Pointer version
    int p, q;

    cout << "\nEnter two integers for pointer evaluation: ";
    cin >> p >> q;

    cout << "Average using pointers = "
         << evaluate(&p, &q) << endl;

    return 0;
}