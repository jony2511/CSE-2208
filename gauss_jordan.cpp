#include <iostream>
#include <vector>
#include <iomanip> // For formatting output

using namespace std;

typedef vector<vector<double>> Matrix;

void printMatrix(const Matrix& A) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < A[i].size(); ++j)
            cout << setw(10) << A[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

// Function for Gauss Elimination
void gauss_eli(Matrix &A) {
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        // Pivoting
        for (int k = i; k < n; ++k) {
            if (A[k][i] != 0) {
                swap(A[i], A[k]);
                break;
            }
        }

        // Make the diagonal element 1 and the below elements 0
        for (int j = i + 1; j < n; ++j) {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k <= n; ++k) {
                A[j][k] -= factor * A[i][k];
            }
        }
    }

    cout << "Matrix after Gauss Elimination (Upper Triangular Form):\n";
    printMatrix(A);
}

// Function for Gauss-Jordan Elimination
void jordan_eli(Matrix &A) {
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        // Pivoting
        for (int k = i; k < n; ++k) {
            if (A[k][i] != 0) {
                swap(A[i], A[k]);
                break;
            }
        }

        // Make the diagonal element 1
        double diagElem = A[i][i];
        for (int j = 0; j <= n; ++j) {
            A[i][j] /= diagElem;
        }

        // Make the other elements in the column 0
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                double factor = A[j][i];
                for (int k = i; k <= n; ++k) {
                    A[j][k] -= factor * A[i][k];
                }
            }
        }
    }

    cout << "Matrix after Gauss-Jordan Elimination (Reduced Row Echelon Form):\n";
    printMatrix(A);
}

// Function for Row Echelon Form (REF)
void row_echelon(Matrix &A) {
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        // Pivoting
        for (int k = i; k < n; ++k) {
            if (A[k][i] != 0) {
                swap(A[i], A[k]);
                break;
            }
        }

        // Make the diagonal element 1 and the below elements 0
        double diagElem = A[i][i];
        for (int j = i; j <= n; ++j) {
            A[i][j] /= diagElem;
        }

        // Make the below rows zero in current column
        for (int j = i + 1; j < n; ++j) {
            double factor = A[j][i];
            for (int k = i; k <= n; ++k) {
                A[j][k] -= factor * A[i][k];
            }
        }
    }

    cout << "Matrix in Row Echelon Form:\n";
    printMatrix(A);
}

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    Matrix A(n, vector<double>(n + 1));

    cout << "Enter the augmented matrix (coefficients and constants):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cin >> A[i][j];
        }
    }

    Matrix A1 = A, A2 = A;

    gauss_eli(A);
    jordan_eli(A1);
   // row_echelon(A2);

    return 0;
}

