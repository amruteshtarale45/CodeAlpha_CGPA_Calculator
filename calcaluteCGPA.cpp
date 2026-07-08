#include <iostream>
#include <string>
using namespace std;

int main() {
    int semesters;
    cout << "Enter number of semesters: ";
    cin >> semesters;
    cin.ignore(); // clear newline from buffer

    float overallGradePoints = 0, overallCredits = 0;

    for (int s = 1; s <= semesters; s++) {
        int n;
        cout << "\n===== Semester " << s << " =====\n";
        cout << "Enter number of courses: ";
        cin >> n;
        cin.ignore();

        string courseName[20];
        float grade[20], credits[20];
        float totalCredits = 0, totalGradePoints = 0;

        for (int i = 0; i < n; i++) {
            cout << "\nCourse " << i+1 << " name: ";
            getline(cin, courseName[i]);   // allows multi-word names
            cout << "Grade (0-10): ";
            cin >> grade[i];
            cout << "Credits: ";
            cin >> credits[i];
            cin.ignore();

            totalCredits += credits[i];
            totalGradePoints += grade[i] * credits[i];
        }

        float sgpa = totalGradePoints / totalCredits;

        cout << "\n--- Semester " << s << " Result ---\n";
        cout << "Course\t\tGrade\tCredits\n";
        for (int i = 0; i < n; i++) {
            cout << courseName[i] << "\t\t" << grade[i] << "\t" << credits[i] << endl;
        }
        cout << "Semester GPA (SGPA) = " << sgpa << endl;

        // accumulate for overall CGPA
        overallCredits += totalCredits;
        overallGradePoints += totalGradePoints;
    }

    float cgpa = overallGradePoints / overallCredits;
    cout << "\n==========================================\n";
    cout << "Final CGPA across " << semesters << " semesters = " << cgpa << endl;
    cout << "==========================================\n";

    return 0;
}
