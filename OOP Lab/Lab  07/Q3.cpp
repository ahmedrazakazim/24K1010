#include <iostream>
using namespace std;

class Currency {
protected:
    double amt;
    string code;
    string symbol;
    double rate;

public:
    Currency(double a, string currencyCode, string currencySymbol, double exchangeRate = 0.10) 
        : amt(a), code(currencyCode), symbol(currencySymbol), rate(exchangeRate) {}

    virtual void convertToBase() = 0;
    virtual double convertTo(Currency& targetCurrency) = 0;
    virtual void displayCurrency() = 0;

    double getExchangeRate() const { return rate; }
    string getCurrencySymbol() const { return symbol; }
};

class Dollar : public Currency {
public:
    Dollar(double amount, double exchangeRate = 1.0) 
        : Currency(amount, "USD", "$", exchangeRate) {}

    void convertToBase() override {
        amt /= rate;
    }

    double convertTo(Currency& targetCurrency) override {
        double baseAmount = amt / rate;
        return baseAmount * targetCurrency.getExchangeRate();
    }

    void displayCurrency() override {
        cout << "Amount: " << symbol << amt << " (" << code << ")" << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amount, double exchangeRate = 0.92) 
        : Currency(amount, "EUR", "€", exchangeRate) {}

    void convertToBase() override {
        amt /= rate;
    }

    double convertTo(Currency& targetCurrency) override {
        double baseAmount = amt / rate;
        return baseAmount * targetCurrency.getExchangeRate();
    }

    void displayCurrency() override {
        cout << "Amount: " << symbol << amt << " (" << code << ")" << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amount, double exchangeRate = 278.50) 
        : Currency(amount, "PKR", "Rs", exchangeRate) {}

    void convertToBase() override {
        amt /= rate;
    }

    double convertTo(Currency& targetCurrency) override {
        double baseAmount = amt / rate;
        return baseAmount * targetCurrency.getExchangeRate();
    }

    void displayCurrency() override {
        cout << "Amount: " << symbol << amt << " (" << code << ")" << endl;
    }
};

int main() {
    Currency* currencies[3];
    currencies[0] = new Dollar(200);
    currencies[1] = new Euro(500);
    currencies[2] = new Rupee(1000);

    for (int i = 0; i < 3; i++) {
        double convertedAmt;
        int j;
        if (i < 2) {
            convertedAmt = currencies[i]->convertTo(*currencies[i + 1]);
            j = i + 1;
        } else {
            convertedAmt = currencies[i]->convertTo(*currencies[0]);
            j = 0;
        }

        currencies[i]->displayCurrency();
        cout << "Converted amount: " << currencies[j]->getCurrencySymbol() << convertedAmt << endl;
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete currencies[i];
    }
    return 0;
}
