#include <iostream>
using namespace std;

// Find length
int information(const char str[])
{
    int length = 0;

    while (str[length] != '\0')
        length++;

    return length;
}

// Count occurrence of character
int information(const char str[], char ch)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
            count++;
    }

    return count;
}

// Count occurrence within first k positions
int information(const char str[], char ch, int k)
{
    int count = 0;

    for (int i = 0; str[i] != '\0' && i < k; i++)
    {
        if (str[i] == ch)
            count++;
    }

    return count;
}

int main()
{
    char str[100];
    char ch;
    int k;

    cout << "Enter a string: ";
    cin >> str;

    cout << "\nLength of string = "
         << information(str) << endl;

    cout << "\nEnter character to count: ";
    cin >> ch;

    cout << "Total occurrence of '" << ch << "' = "
         << information(str, ch) << endl;

    cout << "\nEnter k: ";
    cin >> k;

    cout << "Occurrence of '" << ch
         << "' in first " << k << " positions = "
         << information(str, ch, k) << endl;

    return 0;
}