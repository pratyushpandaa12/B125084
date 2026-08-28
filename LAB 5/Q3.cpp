#include <iostream>
#include <cctype>
using namespace std;

// Check integer
void check(int n)
{
    if (n > 0)
        cout << "The number is Positive." << endl;
    else if (n < 0)
        cout << "The number is Negative." << endl;
    else
        cout << "The number is Zero." << endl;
}

// Check character
void check(char ch)
{
    if (isupper(ch))
        cout << "The character is Uppercase." << endl;
    else if (islower(ch))
        cout << "The character is Lowercase." << endl;
    else
        cout << "The character is not a letter." << endl;
}

// Search character in character array
void check(const char str[], char target)
{
    bool found = false;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == target)
        {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Character '" << target << "' is found in the string." << endl;
    else
        cout << "Character '" << target << "' is not found in the string." << endl;
}

int main()
{
    int n;
    char ch, target;
    char str[100];

    cout << "Enter an integer: ";
    cin >> n;

    check(n);

    cout << "\nEnter a character: ";
    cin >> ch;

    check(ch);

    cout << "\nEnter a character array/string: ";
    cin >> str;

    cout << "Enter character to search: ";
    cin >> target;

    check(str, target);

    return 0;
}