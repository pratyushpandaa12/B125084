#include <iostream>
using namespace std;

// Add two matrices whose dimensions are supplied at runtime.
int main() {
    int m, n;
    cout << "Enter rows (m) and columns (n): ";
    cin >> m >> n;
    // Allocate each matrix as an array of row pointers followed by its rows.
    int** mat1 = new int*[m];
    for(int i=0; i<m; ++i) {
        mat1[i] = new int[n];
    }
    int** mat2 = new int*[m];
    for(int i=0; i<m; ++i) {
        mat2[i] = new int[n];
    }
    cout << "Enter elements of first matrix:\n";
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> mat1[i][j];
        }
    }
    cout << "Enter elements of second matrix:\n";
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> mat2[i][j];
        }
    }
    int** result = new int*[m]; // Store the element-wise sums.
    for(int i=0; i<m; ++i) {
        result[i] = new int[n];
    }
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    cout << "Result of matrix addition:\n";
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    // Every row and then each row-pointer array must be released.
    for(int i=0; i<m; ++i) {
        delete[] mat1[i];
    }
    delete[] mat1;
    for(int i=0; i<m; ++i) {
        delete[] mat2[i];
    }
    delete[] mat2;
    for(int i=0; i<m; ++i) {
        delete[] result[i];
    }
    delete[] result;

    return 0;
}
