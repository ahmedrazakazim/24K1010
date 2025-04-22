#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const string chapter1_filename = "chapter1.txt";
    const string chapter2_filename = "chapter2.txt";
    const string book_filename = "book.txt";

    // --- Pre-requisite: Manually create chapter1.txt and chapter2.txt ---
    // Example chapter1.txt content:
    // This is the first chapter.
    // It introduces the main topic.
    //
    // Example chapter2.txt content:
    // This is the second chapter, continuing the story.
    // More details are revealed here.

    ifstream inFile1;
    ifstream inFile2;
    ofstream outFile;

    inFile1.open(chapter1_filename);
    if (!inFile1) {
        cerr << "Error: Could not open file " << chapter1_filename << " for reading." << endl;
        return 1;
    }

    inFile2.open(chapter2_filename);
    if (!inFile2) {
        cerr << "Error: Could not open file " << chapter2_filename << " for reading." << endl;
        inFile1.close();
        return 1;
    }

    outFile.open(book_filename, ios::app);
    if (!outFile) {
        cerr << "Error: Could not open file " << book_filename << " for appending." << endl;
        inFile1.close();
        inFile2.close();
        return 1;
    }

    outFile << inFile1.rdbuf();
    outFile << endl;
    outFile << inFile2.rdbuf();

    cout << "Successfully appended contents of " << chapter1_filename
         << " and " << chapter2_filename << " to " << book_filename << "." << endl;

    inFile1.close();
    inFile2.close();
    outFile.close();


    cout << "\n--- Displaying contents of " << book_filename << " ---" << endl;
    ifstream resultFile;
    resultFile.open(book_filename);
    if (!resultFile) {
        cerr << "Error: Could not open file " << book_filename << " for reading back." << endl;
        return 1;
    }

    cout << resultFile.rdbuf();

    resultFile.close();
    cout << "\n--- Finished reading combined file ---" << endl;

    return 0;
}
