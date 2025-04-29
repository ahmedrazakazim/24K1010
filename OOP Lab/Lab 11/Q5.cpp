#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <iomanip> // For setprecision

using namespace std;

class InsufficientFundsException : public exception {
private:
    string message;

public:
    InsufficientFundsException(double deficitAmount) noexcept {
        stringstream ss;
        ss << fixed << setprecision(2); // Format deficit to 2 decimal places
        ss << "InsufficientFundsException - Deficit: $" << deficitAmount;
        message = ss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }

    // Add a virtual destructor
    virtual ~InsufficientFundsException() noexcept {}
};


template <typename T>
class BankAccount {
private:
    T balance;

public:
    BankAccount(T initialBalance) : balance(initialBalance) {}

    T getBalance() const {
        return balance;
    }

    void deposit(T amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(T amount) {
        if (amount <= 0) {
            // Optional: Handle invalid withdrawal amount (e.g., throw different exception or ignore)
             cout << "Withdrawal amount must be positive." << endl;
             return;
        }
        if (amount > balance) {
            double deficit = static_cast<double>(amount - balance);
            throw InsufficientFundsException(deficit);
        }
        balance -= amount;
        cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << balance << endl;
    }
};


int main() {
    BankAccount<double> myAccount(500.00);

    cout << fixed << setprecision(2); // Set output precision for currency
    cout << "Balance: $" << myAccount.getBalance() << endl << endl;

    double withdrawalAmount = 600.00;
    cout << "Attempting to withdraw $" << withdrawalAmount << "..." << endl;

    try {
        myAccount.withdraw(withdrawalAmount);
     
        cout << "Withdrawal should not have succeeded." << endl;
    } catch (const InsufficientFundsException& e) {
         cout << "Withdraw $" << withdrawalAmount << ": " << e.what() << endl; 
    } catch (const exception& e) {
        cerr << "An unexpected error occurred: " << e.what() << endl;
    }


    cout << "\nAttempting to withdraw $150.00..." << endl;
     try {
        myAccount.withdraw(150.00);
    } catch (const InsufficientFundsException& e) {
         cerr << "Error: " << e.what() << endl;
    }

    cout << "\nFinal Balance: $" << myAccount.getBalance() << endl;


    return 0;
}
