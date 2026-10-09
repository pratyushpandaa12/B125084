
#include <iostream>
using namespace std;

class Matrix {
    int a[2][2];

public:
    Matrix() {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                a[i][j] = 0;
    }

    void input() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> a[i][j];
            }
        }
    }

    Matrix operator+(const Matrix& m) const {
        Matrix result;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.a[i][j] = a[i][j] + m.a[i][j];
            }
        }

        return result;
    }

    void display() const {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix m1, m2, result;

    cout << "Enter elements of first 2x2 matrix:\n";
    m1.input();

    cout << "Enter elements of second 2x2 matrix:\n";
    m2.input();

    result = m1 + m2;

    cout << "\nFirst matrix:\n";
    m1.display();

    cout << "Second matrix:\n";
    m2.display();

    cout << "Sum of matrices:\n";
    result.display();

    cout << "Original matrices remain unchanged.\n";

    return 0;
}
