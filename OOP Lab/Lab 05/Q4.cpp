#include <iostream>
using namespace std;

class BankAccount
{
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount() : accountNumber(""), accountHolderName(""), balance(0.0) {}
    BankAccount(string accNum, string accName, double b) : accountNumber(accNum), accountHolderName(accName), balance(b) {}

    void deposit(double amount)
    {
        balance += amount;
        cout << endl << "Successfully deposited: $" << amount << endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Withdrawal of $" << amount << " failed due to insufficient funds." << endl;
            return;
        }

        balance -= amount;
        cout << endl << "Successfully withdrawn: $" << amount << endl;
    }

    void display()
    {
        cout << endl << "Account Details:" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main()
{
    BankAccount accounts[3] = {
        BankAccount("1234", "Ahmed Raza", 4000.45  ),
        BankAccount("5678", "Rafique Khan", 2310.35),
        BankAccount("9101", "Zain ul", 9403.70)
    };

    for (int i = 0; i < 3; i++)
    {
        cout << endl << "-------- Initial Details --------" << endl;
        accounts[i].display();

        accounts[i].deposit(500);
        cout << endl << "-------- Updated Details after Deposit --------" << endl;
        accounts[i].display();

        accounts[i].withdraw(200);
        cout << endl << "-------- Updated Details after Withdrawal --------" << endl;
        accounts[i].display();
    }
    return 0;
}
