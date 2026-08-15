#include <iostream>
#include <cctype>
using namespace std;

// Classify characters in a dynamically allocated string.
int main()
{
    int n;
    cout << "Enter size of String : ";
    cin >> n;
    cin.ignore();
    char *a = new char[n+1]; // Extra byte stores the terminating '\0'.
        cout << "Enter a String of Length " << n << " ";
        cin.getline(a, n+1);
       int vowels = 0,consonants = 0,digits = 0,spaces = 0;

for (int i=0; i < n; ++i) {
    char c = a[i];
    if (isalpha(c)) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels++;
        } else {
            consonants++;
        }
    } else if (isdigit(c)) {
        digits++;
    } else if (c == ' ') {
        spaces++;
    }
}

    // Print each count separately for readable output.
    cout << "Number of Vowels : " << vowels << endl;
    cout << "Number of Consonents : " << consonants << endl;
    cout << "Number of Digits : " << digits << endl;
    cout << "Number of Spaces : " << spaces << endl;

    
    delete[] a;
    a= nullptr;
    return 0;
}
