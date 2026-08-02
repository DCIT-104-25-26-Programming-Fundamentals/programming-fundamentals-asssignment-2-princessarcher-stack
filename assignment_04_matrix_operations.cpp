// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

using Matrix = std::array<std::array<int, 10>, 10>;

void print_matrix(const Matrix& matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}Matrix input_matrix(int& rows, int& cols) {
    Matrix matrix;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    return matrix;
}
Matrix transpose_matrix(const Matrix& matrix, int rows, int cols) {
    Matrix transposed;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

Matrix add_matrices(const Matrix& A, const Matrix& B, int rows, int cols) {
    Matrix sum;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }
    return sum;
}

Matrix multiply_matrices(const Matrix& A, const Matrix& B, int rowsA, int colsA, int colsB) {
    Matrix product = {};
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return product;
}

int main() {
    // Part A: Transpose a Matrix
    int rowsA, colsA;
    cout << "Part A: Transpose a Matrix" << endl;
    Matrix matrixA = input_matrix(rowsA, colsA);
    cout << "Original Matrix:" << endl;
    print_matrix(matrixA, rowsA, colsA);
    Matrix transposed = transpose_matrix(matrixA, rowsA, colsA);
    cout << "Transposed Matrix:" << endl;
    print_matrix(transposed, colsA, rowsA);

    // Part B: Add Two Matrices
    int rowsB, colsB;
    cout << "\nPart B: Add Two Matrices" << endl;
    cout << "Matrix 1:" << endl;
    Matrix matrixB1 = input_matrix(rowsB, colsB);
    cout << "Matrix 2:" << endl;
    Matrix matrixB2 = input_matrix(rowsB, colsB);
    Matrix sum = add_matrices(matrixB1, matrixB2, rowsB, colsB);
    cout << "Sum of Matrices:" << endl;
    print_matrix(sum, rowsB, colsB);

    // Part C: Multiply Two Matrices
    int rowsC1, colsC1, rowsC2, colsC2;
    cout << "\nPart C: Multiply Two Matrices" << endl;
    cout << "Matrix A:" << endl;
    Matrix matrixC1 = input_matrix(rowsC1, colsC1);
    cout << "Matrix B:" << endl;
    Matrix matrixC2 = input_matrix(rowsC2, colsC2);

    if (colsC1 != rowsC2) {
        cout << "Error: Number of columns in A must equal number of rows in B." << endl;
        return 1; // Exit with error
    }

    Matrix product = multiply_matrices(matrixC1, matrixC2, rowsC1, colsC1, colsC2);
    cout << "Product of Matrices:" << endl;
    print_matrix(product, rowsC1, colsC2);

    return 0;
}
