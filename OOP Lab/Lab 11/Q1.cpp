#include <iostream>
#include <exception>
#include <string>

using namespace std;

class InvalidValueException : public exception {
public:
    const char* what() const noexcept override {
        return "InvalidValueException - Age cannot be negative or exceed 120.";
    }
};

void validateAge(int age) {
    if (age < 0 || age > 120) {
        throw InvalidValueException();
    }
}

int main() {
    int userAge;

    cout << "Enter age: ";
    cin >> userAge;

    try {
        validateAge(userAge);
        cout << "Age entered (" << userAge << ") is valid." << endl;
    } catch (const InvalidValueException& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "An unexpected standard error occurred: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown error occurred." << endl;
    }

    return 0;
}
