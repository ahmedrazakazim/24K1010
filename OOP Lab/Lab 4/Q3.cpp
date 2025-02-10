#include <iostream>

using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account() {
        balance = 0.0;
    }

    Account(string an, string ahn, double b) {
        accountNumber = an;
        accountHolderName = ahn;
        balance = b;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance" << endl;
        } else if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;
        }
    }

    void checkBalance() const {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    Account acc1("43415", "Batool", 30415.0);
    Account acc2("45678", "Shabeer", 4235.0);

    cout << "Account 1 - Initial Balance: ";
    acc1.checkBalance();

    cout << "Account 2 - Initial Balance: ";
    acc2.checkBalance();

    acc1.deposit(200.0);
    acc1.withdraw(100.0);

    acc2.deposit(500.0);
    acc2.withdraw(1600.0);

    cout << "Account 1 - Final Balance: ";
    acc1.checkBalance();

    cout << "Account 2 - Final Balance: ";
    acc2.checkBalance();

    return 0;
}
