#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

// #include<bits/stdc++.h>

using namespace std;

// Define a struct for student data
struct Student {
    string name;
    int age;
    string major;
};

// Function to add a new student to the list
void addStudent(vector<Student>& students) {
    Student newStudent;

    cout << "Enter student name: ";
    cin.ignore(); // ignore newline character in input buffer
    getline(cin, newStudent.name);
    cout << "Enter student age: ";
    cin >> newStudent.age;
    cout << "Enter student major: ";
    cin.ignore();
    getline(cin ,newStudent.major );

    
    // cin.ignore(); // ignore newline character in input buffer

    students.push_back(newStudent);

    cout << "Student added successfully!" << endl;
}

// Function to display students whose name contains a search string
bool displayStudents(vector<Student>& students, string searchName = "") {
    if (students.empty()) {
        cout << "No students found." << endl;
        return -1;
    }

    cout << "List of students:" << endl;

    for (const auto& student : students) {
        if (searchName.empty() || student.name.find(searchName) != string::npos) {
            cout << "Name: " << student.name << endl;
            cout << "Age: " << student.age << endl;
            cout << "Major: " << student.major << endl;
            cout << endl;
        }
    }
}

// Function to search for a student by name
// Function to search for a student by name
void searchStudent(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students found." << endl;
        return;
    }

    string searchName;
    cout << "Enter student name to search for: ";
    cin.ignore(); // ignore newline character in input buffer
    getline(cin, searchName);

    if (!displayStudents(students, searchName)) {
        cout << "No such student." << endl;
    }
}



// Function to save the list of students to a file
void saveToFile(vector<Student>& students, string fileName) {
    ofstream outFile(fileName);

    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    for (const auto& student : students) {
        outFile << student.name << "," << student.age << "," << student.major << endl;
    }

    outFile.close();

    cout << "Student data saved to file successfully!" << endl;
}

// Function to load a list of students from a file
void loadFromFile(vector<Student>& students, string fileName) { 
    ifstream inFile(fileName);

    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        Student student;
        size_t pos = 0;


        pos = line.find(",");
        student.name = line.substr(0, pos);
        
        line.erase(0, pos + 1);
        pos = line.find(",");
        student.age = stoi(line.substr(0, pos));

        line.erase(0, pos + 1);
        student.major = line;

        students.push_back(student);
    }

    inFile.close();

    cout << "Student data loaded from file successfully!" << endl;
}



int main() {
    vector<Student> students;
    string fileName = "students.txt";

    // Load any existing student data from file
    loadFromFile(students, fileName);

   while (true) {
    // Display menu options
    cout << "Menu:" << endl;
    cout << "1. Add new student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Search for a student by name" << endl;
    cout << "4. Save student data to file" << endl;
    cout << "5. Quit" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            addStudent(students);
            break;
        case 2:
            displayStudents(students);
            break;
        case 3:
            searchStudent(students);
            break;
        case 4:
            saveToFile(students, fileName);
            break;
        case 5:
            // Save any new student data to file before quitting
            saveToFile(students, fileName);
            cout << "Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

    return 0;
}