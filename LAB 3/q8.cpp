#include <iostream>
using namespace std;

// Use helper functions to summarize a dynamically allocated integer array.
void accept(int* arr, int n) {
    // Fill the caller-owned array.
    for (int i=0; i < n; ++i) {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }
}
int sum(int* arr, int n) {
    // Add every element through indexed pointer storage.
    int total = 0;
    for (int i=0; i < n; ++i) {
        total += arr[i];
    }
    return total;
}
int findMin(int* arr, int n) {
    int min = arr[0];
    for (int i=1; i < n; ++i) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}
int findMax(int* arr, int n) {
    int max = arr[0];
    for (int i=1; i < n; ++i) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
void display(int* arr, int n) {
    cout << "Array elements: ";
    for (int i=0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
cout << "Enter n: ";
cin >> n;

int* arr = new int[n];

accept(arr, n);

int total = sum(arr, n);
int minVal = findMin(arr, n);
int maxVal = findMax(arr, n);

display(arr, n);

cout << "Sum is " << total << endl;
cout << "Minimum is " << minVal << endl;
cout << "Maximum is " << maxVal << endl;
delete[] arr; // Release the dynamic array after all calculations.
return 0;
}
