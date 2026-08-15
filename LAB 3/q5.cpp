#include <iostream>
#include <string>
using namespace std;

// A Book object is created dynamically and accessed through a pointer.
class Book
{
    int bookID;
    string title;
    string author;
    float price;

public:

    // Read all book fields, including titles or authors containing spaces.
    void accept()
    {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Price: ";
        cin >> price;
    }

    // Print the stored book information.
    void display()
    {
        cout << "\n--- Book Details ---" << endl;
        cout << "Book ID: " << bookID << endl;
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }
};

int main()
{
    Book *b = new Book;

    b->accept();
    b->display();

    delete b;

    return 0;
}
