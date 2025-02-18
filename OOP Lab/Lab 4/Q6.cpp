#include <iostream>
using namespace std;

class Bank {
private:
    int accountID;
    string accountHolder;
    double funds;

public:
    Bank() : accountID(0), accountHolder(""), funds(0.0) {}

    Bank(int id, string holder, double initialFunds = 0.0) {
        this->accountID = id;
        this->accountHolder = holder;
        this->funds = initialFunds;
    }

    void addFunds(double amount) {
        if (amount > 0) {
            funds += amount;
            cout << "Successfully deposited $" << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdrawFunds(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        } else if (amount > funds) {
            cout << "Sorry! Cannot withdraw amount. Insufficient funds." << endl;
        } else {
            funds -= amount;
            cout << "Transaction Successful! You have withdrawn $" << amount << ". Your remaining balance is $" << funds << endl;
        }
    }

    void showAccountInfo() {
        cout << "Account Number: " << this->accountID << endl;
        cout << "Owner Name: " << this->accountHolder << endl;
        cout << "Available Balance: $" << funds << endl;
        cout << "-----------------------" << endl << endl;
    }
};

int main() {
    Bank client1(1020, "Hassan", 100000.0);
    Bank client2(205, "Simal");

    client1.showAccountInfo();
    client2.showAccountInfo();

    client1.addFunds(15000);
    client2.addFunds(2500); // Adding funds to client2

    client1.withdrawFunds(1500);
    client2.withdrawFunds(3000); // Attempting to withdraw more than available balance

    cout << "After Transactions: " << endl;
    client1.showAccountInfo();
    client2.showAccountInfo();

    return 0;
}
