/*
Define a class named BankAccount that includes the following attributes and functionalities:
Attributes: The BankAccount class has three private member variables: accountNumber, 
accountHolderName, and balance.
Constructor: The class includes a constructor that initializes the account details 
(accountNumber, accountHolderName, and balance).
Member Functions:
• deposit(double amount): Increases the balance by the specified amount.
• withdraw(double amount): Decreases the balance by the specified amount, if sufficient funds are available.
• display(): Shows the account details, including the account number, account holder name, and balance.
In the main() function, create an array named accounts consisting of BankAccount objects. 
The array should contain three elements, each for a different bank account.
Initialize each BankAccount object with specific account details such as account number, 
holder name, and initial balance.
Perform the following operations:
• Loop through each account in the accounts array.
• For each account, use the display() function to show the account details.
• Execute Two Transactions:
• Deposit 500.0 rupees into the account.
• Withdraw 200.0 rupees from the account.
• After each transaction, display the updated account details, including the new balance.
*/

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
