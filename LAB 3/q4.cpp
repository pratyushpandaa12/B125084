#include <iostream>
using namespace std;

// Return the first index containing x, or -1 when the value is absent.
int linearSearch(int *a, int n, int x) {
    for(int i=0;i<n;i++)
    if(*(a+i)==x) return i;
    return -1;
}

int main()
{
    int n,ele;
    cout << "Enter size of Array : ";
    cin >> n;
    int *a = new int[n]; // Array size is determined from user input.
    for ( int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i+1 << " : ";
        cin >> *(a+i);
    }
    cout << "Enter Element to Search in this Array : " ;
    cin >> ele;
    int idx = linearSearch(a,n,ele);
    if(idx != -1) cout << "Element " << ele << " found at Index " << idx << endl;
    else cout << "Element NOT found" << endl;
    delete[] a;
    a= nullptr;
    return 0;
}
