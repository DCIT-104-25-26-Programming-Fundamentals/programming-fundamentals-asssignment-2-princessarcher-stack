// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

double calculate_sum(double numbers[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum;
}

double calculate_average(double numbers[], int size) {
    if (size == 0) return 0; // Avoid division by zero
    double sum = calculate_sum(numbers, size);
    return sum / size;
}
double find_maximum(double numbers[], int size) {
    if (size == 0) return 0; // Handle empty array case
    double max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}
double find_minimum(double numbers[], int size) {
    if (size == 0) return 0; // Handle empty array case
    double min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}
int main() {
    int N;
    cout << "How many numbers? ";
    cin >> N;

    if (N <= 0) {
        cout << "Error: Number of elements must be a positive integer." << endl;
        return 1; // Exit with error
    }

    double* numbers = new double[N]; // Dynamically allocate array

    for (int i = 0; i < N; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    double sum = calculate_sum(numbers, N);
    double average = calculate_average(numbers, N);
    double maximum = find_maximum(numbers, N);
    double minimum = find_minimum(numbers, N);

    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;

    delete[] numbers; // Free dynamically allocated memory
    return 0;
}