
#include <iostream>
using namespace std;

class Account {
protected:
    string accNumber;
    double accBalance;
    string accHolderName;
    string accType;

public:
    Account(string num, double bal, string name, string type = "") 
        : accNumber(num), accBalance(bal), accHolderName(name), accType(type) {}

    virtual void deposit(double amt) {
        if (amt > 0) {
            accBalance += amt;
            cout << "The amount $" << amt << " has been deposited into your account." << endl;
            cout << "Remaining balance: $" << accBalance << endl;
        } else {
            cout << "Invalid amount entered." << endl;
        }
    }

    virtual void withdraw(double amt) {
        if (amt <= accBalance) {
            accBalance -= amt;
            cout << "The amount $" << amt << " has been withdrawn from your account." << endl;
            cout << "Remaining balance: $" << accBalance << endl;
        } else {
            cout << "Amount $" << amt << " exceeds your account balance." << endl;
        }
    }

    virtual double calculateInterest() { return 0.0; }

    virtual void printStatement() {}

    virtual void getAccountInfo() {
        cout << endl << "Displaying account information below" << endl;
        cout << "Account Number: " << accNumber << endl;
        cout << "Account Balance: $" << accBalance << endl;
        cout << "Account Holder Name: " << accHolderName << endl;
        cout << "Account Type: " << ((accType != "") ? accType : "-") << endl;
    }
};

class SavingsAccount : public Account {
    const double intRate;
    double minBalance;

public:
    SavingsAccount(double rate, double minBal, string num, double bal, string name, string type = "Savings Account") 
        : intRate(rate), minBalance(minBal), Account(num, bal, name, type) {
        if (accBalance < minBalance) {
            do {
                cout << "The entered balance ($" << accBalance << ") is less than the minimum balance ($" << minBalance << "). Enter account balance again: ";
                cin >> accBalance; 
            } while (accBalance < minBalance);
        }
    }

    double calculateInterest() override {
        return (accBalance * intRate);
    }

    void withdraw(double amt) override {
        if (accBalance - amt >= minBalance) {
            accBalance -= amt;
            cout << "The amount $" << amt << " has been withdrawn from your account." << endl;
            cout << "Remaining balance: $" << accBalance << endl;
        } else if (amt > accBalance) {
            cout << "Amount $" << amt << " exceeds your account balance." << endl;
        } else {
            cout << "Cannot withdraw. Minimum balance of $" << minBalance << " is required for savings account." << endl;
        }
    }

    void printStatement() override {
        cout << endl << "--------- Savings Account Menu ---------" << endl;
        cout << "Enter 1 to deposit money." << endl;
        cout << "Enter 2 to withdraw money." << endl;
        cout << "Enter 3 to calculate interest." << endl;
        cout << "Enter 4 to get account information." << endl;
        cout << "Enter 5 to exit." << endl;

        int choice;
        do {
            cout << endl << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1: {
                    double amt;
                    cout << "Enter amount to deposit: ";
                    cin >> amt;
                    deposit(amt);
                    break;
                }

                case 2: {
                    double amt;
                    cout << "Enter amount to withdraw: ";
                    cin >> amt;
                    withdraw(amt);
                    break;
                }

                case 3:
                    cout << "The interest rate of Savings Account is " << intRate << " (" << (100 * intRate) << "%)" << endl;
                    cout << "Interest Amount is: $" << calculateInterest() << endl;
                    break;

                case 4:
                    getAccountInfo();
                    break;

                case 5:
                    cout << "Exiting Savings Account..." << endl;
                    break;
                
                default:
                    cout << "Invalid input, try again!" << endl;
            }
        } while (choice != 5);
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(string num, double bal, string name, string type = "Checking Account") 
        : Account(num, bal, name, type) {}

    void printStatement() override {
        cout << endl << "--------- Checking Account Menu ---------" << endl;
        cout << "Enter 1 to deposit money." << endl;
        cout << "Enter 2 to withdraw money." << endl;
        cout << "Enter 3 to get account information." << endl;
        cout << "Enter 4 to exit." << endl;

        int choice;
        do {
            cout << endl << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1: {
                    double amt;
                    cout << "Enter amount to deposit: ";
                    cin >> amt;
                    deposit(amt);
                    break;
                }

                case 2: {
                    double amt;
                    cout << "Enter amount to withdraw: ";
                    cin >> amt;
                    withdraw(amt);
                    break;
                }

                case 3:
                    getAccountInfo();
                    break;

                case 4:
                    cout << "Exiting Checking Account..." << endl;
                    break;
                
                default:
                    cout << "Invalid input, try again!" << endl;
            }
        } while (choice != 4);
    }
};

class FixedDepositAccount : public Account {
    string maturityDate;
    const double fixedIntRate;

public:
    FixedDepositAccount(string date, double rate, string num, double bal, string name, string type = "Fixed Deposit Account") 
        : maturityDate(date), fixedIntRate(rate), Account(num, bal, name, type) {}

    void withdraw(double amt) override {
        string currDate;
        cout << "Enter today's date: ";
        cin >> currDate;

        if (currDate == maturityDate) {
            Account::withdraw(amt);
        } else {
            cout << "Cannot withdraw amount before maturity date from a Fixed Deposit Account." << endl;
        }
    }

    double calculateInterest() override {
        return (accBalance * fixedIntRate);
    }

    void printStatement() override {
        cout << endl << "--------- Fixed Deposit Account Menu ---------" << endl;
        cout << "Enter 1 to deposit money." << endl;
        cout << "Enter 2 to withdraw money." << endl;
        cout << "Enter 3 to calculate interest." << endl;
        cout << "Enter 4 to get account information." << endl;
        cout << "Enter 5 to exit." << endl;

        int choice;
        do {
            cout << endl << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1: {
                    double amt;
                    cout << "Enter amount to deposit: ";
                    cin >> amt;
                    deposit(amt);
                    break;
                }

                case 2: {
                    double amt;
                    cout << "Enter amount to withdraw: ";
                    cin >> amt;
                    withdraw(amt);
                    break;
                }

                case 3:
                    cout << "The fixed interest rate of Fixed Deposit Account is " << fixedIntRate << " (" << (100 * fixedIntRate) << "%)" << endl;
                    cout << "Interest Amount is: $" << calculateInterest() << endl;
                    break;

                case 4:
                    getAccountInfo();
                    break;

                case 5:
                    cout << "Exiting Fixed Deposit Account..." << endl;
                    break;
                
                default:
                    cout << "Invalid input, try again!" << endl;
            }
        } while (choice != 5);
    }
};

int main() {
    Account* acc = nullptr;
    string holderName, accNumber;
    double balance;
    cout << "-------------- Welcome to Account System --------------" << endl;
    cout << "Enter your account number: ";
    getline(cin, accNumber);
    cout << "Enter your account holder name: ";
    getline(cin, holderName);
    cout << "Enter your account balance: ";
    cin >> balance;
    cin.ignore();
    
    char type;
    cout << "Enter your account type ('S' for Savings, 'C' for Checking, 'F' for Fixed Deposit): ";
    cin >> type;
    switch (type) {
        case 'S':
        case 's':
        {
            double minBal, rate;
            cout << "Enter the minimum balance of your Savings Account: ";
            cin >> minBal;
            cout << "Enter the interest rate of your Savings Account: ";
            cin >> rate;
            acc = new SavingsAccount(rate, minBal, accNumber, balance, holderName);
            break;
        }

        case 'C':
        case 'c':
            acc = new CheckingAccount(accNumber, balance, holderName);
            break;

        case 'F':
        case 'f':
        {
            double rate;
            string mDate;
            cout << "Enter the maturity date of your Fixed Deposit Account: ";
            cin >> mDate;
            cout << "Enter the fixed interest rate of your Fixed Deposit Account: ";
            cin >> rate;
            acc = new FixedDepositAccount(mDate, rate, accNumber, balance, holderName);
            break;
        }

        default:
            cout << "Invalid input, try again!" << endl;
    }

    if (acc != nullptr) {
        acc->printStatement();
    }
    delete acc;
    return 0;
}
