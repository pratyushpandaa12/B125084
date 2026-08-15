#include <iostream>
using namespace std;

// Allocate two integers dynamically and perform the four basic operations.
int main()
{
    // Store the input values on the free store.
    int *a = new int;
    int *b = new int;

    cout << "Enter two integers: ";
    cin >> *a >> *b;
    cout << "Sum = " << *a + *b << endl << "Difference = " << *a - *b << endl << "Product = " << (*a)*(*b) << endl;
    if (*b != 0)
        cout << "Quotient = " << (double)*a / *b << endl;
    else
        cout << "Quotient is undefined (division by zero)." << endl;

    // Release each scalar allocation once it is no longer needed.
    delete a;
    delete b;
    a = nullptr;
    b = nullptr;
    return 0;
}
