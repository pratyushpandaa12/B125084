#include <iostream>
using namespace std;

// Count even and odd values while reading a dynamic integer array.
int main()
{
    int n;
    cout << "Enter size of Array : ";
    cin >> n;
    int *a = new int[n]; // Dynamic storage is sized at runtime.
    int oddNo = 0, evenNo = 0;
    for ( int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i+1 << " : ";
        cin >> *(a+i);
        if(*(a+i) % 2 == 0) evenNo++;
        else oddNo++;
    }
    cout << "Total Even Numbers is " << evenNo << endl;
    cout << "Total Odd Numbers is " << oddNo << endl;

    delete[] a;
    a= nullptr;
    return 0;
}
