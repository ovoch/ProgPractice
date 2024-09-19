#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 10; // Maximum size for the matrix

bool isSkewSymmetric(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] != -matrix[j][i]) {
                return false; // If they don't match, the matrix is not skew-symmetric
            }
        }
    }
    return true; // If all elements meet the condition
}

int main() {
    ifstream file("matrix.txt");
    if (!file) {
        cerr << "Unable to open file!" << endl;
        return EXIT_FAILURE;
    }

    int n; // Size of the square matrix
    file >> n; // Read the size (must be square)

    if (n > MAX_SIZE) {
        cerr << "Matrix size exceeds maximum allowed size!" << endl;
        return EXIT_FAILURE;
    }

    int matrix[MAX_SIZE][MAX_SIZE]; // Declare the matrix

    // Read the matrix from the file
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> matrix[i][j];
        }
    }

    file.close(); // Close the file

    // Check if the matrix is skew-symmetric
    if (isSkewSymmetric(matrix, n)) {
        cout << "The matrix is skew-symmetric." << endl;
    }
    else {
        cout << "The matrix is not skew-symmetric." << endl;
    }

    return 0;
}