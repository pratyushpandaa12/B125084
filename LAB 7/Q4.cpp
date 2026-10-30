
#include <iostream>
using namespace std;

class LibraryAccess {
protected:
    int books;

public:
    LibraryAccess(int b) {
        books = b;
    }
};

class LaboratoryAccess {
protected:
    int pending;

public:
    LaboratoryAccess(int p) {
        pending = p;
    }
};

class StudentAccess : public LibraryAccess,
                      public LaboratoryAccess {
public:
    StudentAccess(int b, int p)
        : LibraryAccess(b), LaboratoryAccess(p) {}

    void display() {
        cout << "\n--- University Resource Access ---\n";
        cout << "Books Borrowed: " << books << endl;
        cout << "Pending Submissions: " << pending << endl;

        if (books <= 5 && pending == 0)
            cout << "Full Resource Access Granted\n";
        else
            cout << "Full Resource Access Denied\n";
    }
};

int main() {
    int books, pending;

    cout << "Enter number of books borrowed: ";
    cin >> books;

    cout << "Enter pending lab submissions: ";
    cin >> pending;

    StudentAccess s(books, pending);
    s.display();

    return 0;
}
