#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const string filename = "info.txt";
    const string initial_sentence = "C++ is a powerful programming language.";
    const string replacement_word = "dynamic";

    ofstream outFile;
    outFile.open(filename, ios::out);
    if (!outFile) {
        cerr << "Error: Could not open file " << filename << " for initial writing." << endl;
        return 1;
    }
    outFile << initial_sentence;
    outFile.close();
    cout << "Initial sentence written to " << filename << endl;

    fstream file;
    file.open(filename, ios::in | ios::out);
    if (!file) {
        cerr << "Error: Could not open file " << filename << " for read/write." << endl;
        return 1;
    }
    cout << "\nFile reopened in read/write mode." << endl;

    cout << "Initial Get Pointer (tellg): " << file.tellg() << endl;
    cout << "Initial Put Pointer (tellp): " << file.tellp() << endl;

    file.seekg(6);
    string wordRead;
    file >> wordRead;
    cout << "\nMoved Get Pointer to position 6." << endl;
    cout << "Word read from Get Pointer: " << wordRead << endl;
    cout << "Get Pointer after read (tellg): " << file.tellg() << endl;


    file.seekp(6);
    file << replacement_word;
    cout << "\nMoved Put Pointer to position 6." << endl;
    cout << "Overwritten with \"" << replacement_word << "\"." << endl;

    cout << "Get Pointer after write (tellg): " << file.tellg() << endl;
    cout << "Put Pointer after write (tellp): " << file.tellp() << endl;


    cout << "\n--- Displaying Updated File Content ---" << endl;
    file.seekg(0);
    string line;
    getline(file, line);
    cout << line << endl;

    file.close();
    cout << "--- File closed ---" << endl;

    return 0;
}
