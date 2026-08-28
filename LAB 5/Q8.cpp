#include <iostream>
using namespace std;

// Update integer variable
void update(int &value, int amount)
{
    value += amount;
}

// Update floating-point variable
void update(float &value, float amount)
{
    value += amount;
}

// Update integer array
void update(int arr[], int n, int amount)
{
    for (int i = 0; i < n; i++)
        arr[i] += amount;
}

int main()
{
    int value, amount;
    float fvalue, famount;
    int n;

    cout << "Enter an integer value: ";
    cin >> value;

    cout << "Enter amount to increase: ";
    cin >> amount;

    cout << "Before update: " << value << endl;

    update(value, amount);

    cout << "After update: " << value << endl;


    cout << "\nEnter a floating-point value: ";
    cin >> fvalue;

    cout << "Enter amount to increase: ";
    cin >> famount;

    cout << "Before update: " << fvalue << endl;

    update(fvalue, famount);

    cout << "After update: " << fvalue << endl;


    cout << "\nEnter size of integer array: ";
    cin >> n;

    int arr[100];

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter amount to increase: ";
    cin >> amount;

    cout << "Before update:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    update(arr, n, amount);

    cout << "\nAfter update:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}