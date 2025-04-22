#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string name;
    string email;
    int yearsOfExperience;
    string summary;
    const string filename = "resume.txt";

    cout << "--- Enter Resume Details ---" << endl;

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Email: ";
    getline(cin, email);

    cout << "Enter Years of Experience: ";
    cin >> yearsOfExperience;
    cin.ignore();

    cout << "Enter Summary (can be multiple lines, end with an empty line):" << endl;
    string line;
    while (getline(cin, line) && !line.empty()) {
         summary += line + "\n";
    }
    if (!summary.empty()) {
        summary.pop_back();
    }

    ofstream outFile;
    outFile.open(filename, ios::out | ios::trunc);

    if (!outFile) {
        cerr << "Error: Could not open file " << filename << " for writing." << endl;
        return 1;
    }

    outFile << "Name: " << name << endl;
    outFile << "Email: " << email << endl;
    outFile << "Years of Experience: " << yearsOfExperience << endl;
    outFile << "Summary:" << endl << summary << endl;

    outFile.close();
    cout << "\nResume data successfully written to " << filename << "." << endl;


    cout << "\n--- Reading data back from " << filename << " ---" << endl;
    ifstream inFile;
    inFile.open(filename);

    if (!inFile) {
        cerr << "Error: Could not open file " << filename << " for reading." << endl;
        return 1;
    }

    string fileContent;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
    cout << "--- Finished reading file ---" << endl;

    return 0;
}
