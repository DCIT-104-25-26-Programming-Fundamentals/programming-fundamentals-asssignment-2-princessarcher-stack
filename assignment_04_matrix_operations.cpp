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

using namespace std;

// Function to print a matrix in a neat, aligned grid
void print_matrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to input elements for a matrix
void read_matrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// PART A — Transpose a Matrix
void transpose_matrix() {
    int rows, cols;
    int matrix[10][10], result[10][10];

    cout << "\n--- PART A: Transpose Matrix ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    read_matrix(matrix, rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:" << endl;
    print_matrix(matrix, rows, cols);

    cout << "\nTransposed Matrix:" << endl;
    print_matrix(result, cols, rows);
}

// PART B — Add Two Matrices
void add_matrices() {
    int rows, cols;
    int A[10][10], B[10][10], sum[10][10];

    cout << "\n--- PART B: Add Two Matrices ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nEnter elements for Matrix A:" << endl;
    read_matrix(A, rows, cols);

    cout << "\nEnter elements for Matrix B:" << endl;
    read_matrix(B, rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nMatrix A + Matrix B:" << endl;
    print_matrix(sum, rows, cols);
}

// PART C — Multiply Two Matrices
void multiply_matrices() {
    int m, n, p;
    int A[10][10], B[10][10], product[10][10] = {0};

    cout << "\n--- PART C: Multiply Two Matrices ---" << endl;
    cout << "Enter rows for Matrix A (M): ";
    cin >> m;
    cout << "Enter columns for Matrix A / rows for Matrix B (N): ";
    cin >> n;
    cout << "Enter columns for Matrix B (P): ";
    cin >> p;

    cout << "\nEnter elements for Matrix A (" << m << "x" << n << "):" << endl;
    read_matrix(A, m, n);

    cout << "\nEnter elements for Matrix B (" << n << "x" << p << "):" << endl;
    read_matrix(B, n, p);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            product[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nMatrix A x Matrix B:" << endl;
    print_matrix(product, m, p);
}

int main() {
    int choice;
    cout << "Matrix Operations Menu:\n";
    cout << "1. Transpose a Matrix\n";
    cout << "2. Add Two Matrices\n";
    cout << "3. Multiply Two Matrices\n";
    cout << "Enter choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        transpose_matrix();
    } else if (choice == 2) {
        add_matrices();
    } else if (choice == 3) {
        multiply_matrices();
    } else {
        cout << "Error: Invalid choice." << endl;
    }

    return 0;
}