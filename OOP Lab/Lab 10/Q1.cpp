
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    float gpa;
};

Student getStudentData() {
    Student s;
    cout << "Enter Student ID: ";
    cin >> s.id;
    cin.ignore(); // Consume the newline character left by cin

    cout << "Enter Student Name: ";
    getline(cin, s.name);

    cout << "Enter Student GPA: ";
    cin >> s.gpa;
    cin.ignore(); // Consume the newline character left by cin
    return s;
}

int main() {
    ofstream outFile;
    ifstream inFile;
    const string filename = "students.txt";
    const int INITIAL_STUDENTS = 5;
    const int APPEND_STUDENTS = 1;

    cout << "--- Enter details for the first " << INITIAL_STUDENTS << " students ---" << endl;
    outFile.open(filename, ios::out);

    if (!outFile) {
        cerr << "Error: Could not open file " << filename << " for writing." << endl;
        return 1;
    }

    for (int i = 0; i < INITIAL_STUDENTS; ++i) {
        cout << "\nEnter details for Student #" << (i + 1) << ":" << endl;
        Student currentStudent = getStudentData();
        outFile << currentStudent.id << " " << currentStudent.gpa << " " << currentStudent.name << endl;
    }

    outFile.close();
    cout << "\nSuccessfully wrote " << INITIAL_STUDENTS << " student records to " << filename << "." << endl;

    cout << "\n--- Enter details for the additional student to append ---" << endl;
    outFile.open(filename, ios::app);

    if (!outFile) {
        cerr << "Error: Could not open file " << filename << " for appending." << endl;
        return 1;
    }

     for (int i = 0; i < APPEND_STUDENTS; ++i) {
        cout << "\nEnter details for Student #" << (INITIAL_STUDENTS + i + 1) << ":" << endl;
        Student appendStudent = getStudentData();
        outFile << appendStudent.id << " " << appendStudent.gpa << " " << appendStudent.name << endl;
    }

    outFile.close();
    cout << "\nSuccessfully appended " << APPEND_STUDENTS << " student record(s) to " << filename << "." << endl;


    cout << "\n--- Reading all student records from " << filename << " ---" << endl;
    inFile.open(filename);

    if (!inFile) {
        cerr << "Error: Could not open file " << filename << " for reading." << endl;
        return 1;
    }

    Student tempStudent;
    while (inFile >> tempStudent.id >> tempStudent.gpa) {
        getline(inFile >> ws, tempStudent.name);
        cout << "ID: " << tempStudent.id
             << ", Name: " << tempStudent.name
             << ", GPA: " << tempStudent.gpa << endl;
    }

    inFile.close();
    cout << "--- Finished reading file ---" << endl;

    return 0;
}
