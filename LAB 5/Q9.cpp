#include <iostream>
using namespace std;

// Display integer variable
void inspect(int value)
{
    cout << "Value of integer variable = "
         << value << endl;
}

// Display value stored at pointer
void inspect(int *ptr)
{
    cout << "Value stored at pointer = "
         << *ptr << endl;
}

// Display array using pointer
void inspect(int *ptr, int n)
{
    cout << "Array elements: ";

    for (int i = 0; i < n; i++)
        cout << *(ptr + i) << " ";

    cout << endl;
    cout<<"Size of Array is "<<n;
}

int main()
{
    int value;
    int n;

    cout << "Enter an integer value: ";
    cin >> value;

    inspect(value);

    cout << "\nInspecting using pointer:\n";
    inspect(&value);


    cout << "\nEnter size of array: ";
    cin >> n;

    int arr[100];

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    inspect(arr, n);

    return 0;
}