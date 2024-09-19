#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

const int MAX_SIZE = 10; 

double determinant(double matrix[MAX_SIZE][MAX_SIZE], int n) {
    double det = 1.0;

    for (int i = 0; i < n; ++i) {
        double maxEl = fabs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (fabs(matrix[k][i]) > maxEl) {
                maxEl = fabs(matrix[k][i]);
                maxRow = k;
            }
        }

        if (i != maxRow) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[maxRow][j], matrix[i][j]);
            }
            det = -det; 
        }


        if (matrix[i][i] == 0) {
            return 0;
        }

        for (int k = i + 1; k < n; ++k) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < n; ++j) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }

        det *= matrix[i][i]; 
    }

    return det;
}

int main() {
    ifstream file("matrix.txt");
    if (!file) {
        cerr << "Unable to open file!" << endl;
        return EXIT_FAILURE;
    }

    int n;
    file >> n; 
    double matrix[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> matrix[i][j];
        }
    }
    file.close();

    double det = determinant(matrix, n);
    cout << "The determinant of the matrix is: " << det << endl;

    return 0;
}