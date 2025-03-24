#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    Account(string number, string holder, double bal)
        : accountNumber(number), accountHolder(holder), balance(bal) {}

    Account operator+(const Account& other) {
        double totalBalance = this->balance + other.balance;
        return Account("Total", "Combined", totalBalance);
    }

    Account& operator=(double amount) {
        this->balance -= amount;
        return *this;
    }

    bool operator>(const Account& other) {
        return this->balance > other.balance;
    }

    friend ostream& operator<<(ostream& os, const Account& acc) {
        os << "Account Number: " << acc.accountNumber 
           << " | Holder: " << acc.accountHolder 
           << " | Balance: $" << acc.balance;
        return os;
    }

    double getBalance() const {
        return balance;
    }

    void setBalance(double bal) {
        balance = bal;
    }
};

int main() {
    Account acc1("101", "Ahmed", 3000);
    Account acc2("102", "Malik", 1000);

    Account total = acc1 + acc2;
    cout << "Total Balance (After Addition): " << total.getBalance() << endl;

    acc1 = 2000;
    acc2.setBalance(acc2.getBalance() + 2000);

    cout << "After Transfer:" << endl;
    cout << "Ahmed's New Balance: " << acc1.getBalance() << endl;
    cout << "Malik's New Balance: " << acc2.getBalance() << endl;

    if (acc1 > acc2) {
        cout << "Ahmed has more balance than Malik." << endl;
    } else {
        cout << "Ahmed has less balance than Malik." << endl;
    }

    cout << "Final Account Details:" << endl;
    cout << acc1 << endl;
    cout << acc2 << endl;

    return 0;
}
