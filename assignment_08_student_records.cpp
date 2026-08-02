// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>

using namespace std;

// Define the Student struct
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Helper function to calculate average score
double calculate_student_average(const Student& s) {
    if (s.scores.empty()) return 0.0;
    double sum = 0;
    for (double score : s.scores) {
        sum += score;
    }
    return sum / s.scores.size();
}

// 1. Add a Student
void add_student(vector<Student>& students) {
    Student s;
    cout << "\nStudent name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    int num_scores;
    cout << "How many scores? ";
    cin >> num_scores;

    for (int i = 0; i < num_scores; ++i) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully.\n";
}

// 2. Display All Students
void display_all_students(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo students have been added yet.\n";
        return;
    }

    cout << "\n------------------------------------------------------------\n";
    cout << left << setw(20) << "Name" 
         << setw(12) << "ID" 
         << setw(20) << "Scores" 
         << setw(10) << "Average" << endl;
    cout << "------------------------------------------------------------\n";

    for (const auto& s : students) {
        string scores_str = "";
        for (size_t i = 0; i < s.scores.size(); ++i) {
            scores_str += to_string((int)s.scores[i]);
            if (i < s.scores.size() - 1) scores_str += ", ";
        }

        cout << left << setw(20) << s.name 
             << setw(12) << s.id 
             << setw(20) << scores_str 
             << fixed << setprecision(2) << calculate_student_average(s) << endl;
    }
    cout << "------------------------------------------------------------\n";
}

// 3. Calculate Average Score for a Specific Student
void calculate_specific_average(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo students available.\n";
        return;
    }

    int search_id;
    cout << "\nEnter student ID: ";
    cin >> search_id;

    for (const auto& s : students) {
        if (s.id == search_id) {
            double avg = calculate_student_average(s);
            cout << s.name << "'s average score: " 
                 << fixed << setprecision(2) << avg << endl;
            return;
        }
    }

    cout << "Error: Student with ID " << search_id << " not found.\n";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n================================\n";
        cout << "   STUDENT RECORD SYSTEM MENU   \n";
        cout << "================================\n";
        cout << "1. Add student\n";
        cout << "2. Display all students\n";
        cout << "3. Calculate average score\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_student(students);
                break;
            case 2:
                display_all_students(students);
                break;
            case 3:
                calculate_specific_average(students);
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Error: Invalid choice. Please enter a number from 1 to 4.\n";
        }
    } while (choice != 4);

    return 0;
}