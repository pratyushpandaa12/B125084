#include <iostream>
using namespace std;

// Sum of integer array
int process(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

// Sum of floating-point array
float process(float arr[], int n)
{
    float sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

// Sum of first k elements
int process(int arr[], int n, int k)
{
    int sum = 0;

    for (int i = 0; i < k && i < n; i++)
        sum += arr[i];

    return sum;
}

int main()
{
    int n, k;

    cout << "Enter size of integer array: ";
    cin >> n;

    int arr[n];

    cout << "Enter integer array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nSum of integer array = "
         << process(arr, n) << endl;

    cout << "\nEnter k: ";
    cin >> k;

    cout << "Sum of first " << k << " elements = "
         << process(arr, n, k) << endl;


    int m;

    cout << "\nEnter size of floating-point array: ";
    cin >> m;

    float farr[m];

    cout << "Enter floating-point array elements:\n";
    for (int i = 0; i < m; i++)
        cin >> farr[i];

    cout << "Sum of floating-point array = "
         << process(farr, m) << endl;

    return 0;
}