#include <iostream>
using namespace std;

// Read a dynamically allocated array and print it from last element to first.
int main()
{
    int n;
    cout << "Enter size of Array : ";
    cin >> n;
    int *a = new int[n]; // Allocate storage for n integers.

    for ( int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i+1 << " : ";
        cin >> *(a+i);
    }
    cout << "=== ARRAY IN REVERSE ORDER ===\n";
    for ( int i = n-1; i >= 0 ; i--)
        cout << *(a+i) << " ";
    cout << "\n";
    
    delete[] a; // Arrays allocated with new[] require delete[].
    a= nullptr;
    return 0;
}
