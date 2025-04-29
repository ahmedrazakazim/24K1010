#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

class FileException : public exception {
protected:
    string message;
public:
    FileException(const string& msg = "Generic File Error") : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
    virtual ~FileException() noexcept {}
};

class FileNotFoundException : public FileException {
public:
    FileNotFoundException(const string& filename = "")
        : FileException("FileNotFoundException - File not found: " + (filename.empty() ? "Unknown" : filename)) {}
};

class PermissionDeniedException : public FileException {
public:
    PermissionDeniedException(const string& filename = "")
        : FileException("PermissionDeniedException - Access denied!") {}
};

void readFile(const string& filename) {
    cout << "Attempting to read '" << filename << "'..." << endl;
    if (filename == "nonexistent.txt") {
        throw FileNotFoundException(filename);
    } else if (filename == "secret.txt") {
        throw PermissionDeniedException(filename);
    } else if (filename == "another_error.txt") {
       
         throw FileException("FileException - Unknown file issue.");
    } else {
        cout << "Successfully read '" << filename << "'." << endl;
    }
}

int main() {
    string files[] = {"mydata.txt", "secret.txt", "nonexistent.txt", "another_error.txt"};

    for (const string& file : files) {
        try {
            readFile(file);
        } catch (const FileNotFoundException& e) {
            cerr << "Caught Specific Error: " << e.what() << endl;
        } catch (const PermissionDeniedException& e) {
            cerr << "Reading '" << file << "': " << e.what() << endl; 
        } catch (const FileException& e) { 
            cerr << "Caught Base File Error: " << e.what() << endl;
        } catch (const exception& e) {
            cerr << "Caught Standard Exception: " << e.what() << endl;
        }
         cout << "--------------------" << endl;
    }

    return 0;
}
