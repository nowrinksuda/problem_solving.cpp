// 3. Multiple Inheritance Problem:

//    Suppose you're developing a student management system for a school. Define a base class called `Student` with properties like `name` and `rollNumber`, representing basic student information. Create another base class `Test` with properties like `marks` and `grade`, representing test results. Derive a class `Result` from both `Student` and `Test` to represent combined student information and test results. Implement member functions to input student details and test marks, and to display the student's name, roll number, marks, and grade. Test your code by creating objects representing student results.

#include <bits/stdc++.h>
using namespace std;
class Student {
protected:
    string name;
    int rollNumber;
public:
    void inputStudentDetails() {
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cin.ignore(); // Clear the input buffer
    }
    void displayStudentDetails() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
    }
};

class Test {
protected:
    int marks;
    char grade;
public:
    void inputTestMarks() {
        cout << "Enter marks obtained: ";
        cin >> marks;
        // Determine grade based on marks (you can define your own criteria)
        if (marks >= 90)
            grade = 'A';
        else if (marks >= 80)
            grade = 'B';
        else if (marks >= 70)
            grade = 'C';
        else if (marks >= 60)
            grade = 'D';
        else
            grade = 'F';
    }
    void displayTestMarks() {
        cout << "Marks Obtained: " << marks << endl;
        cout << "Grade: " << grade << endl;
    }
};

class Result : public Student, public Test {
public:
    void inputResult() {
        inputStudentDetails();
        inputTestMarks();
    }
    void displayResult() {
        displayStudentDetails();
        displayTestMarks();
    }
};

int main() {
    Result result;
    cout << "Enter student details and test marks:\n";
    result.inputResult();
    cout << "\nDisplaying student results:\n";
    result.displayResult();

    return 0;
}