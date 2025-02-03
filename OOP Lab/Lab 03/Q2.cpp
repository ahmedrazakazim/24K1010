#include <iostream>
#include <conio.h>

using namespace std;

class TollBooth
{
private:
    unsigned int carCount;
    double totalAmount;

public:
    TollBooth()
    {
        carCount = 0;
        totalAmount = 0;
    }

    void processPayingCar()
    {
        carCount++;
        totalAmount += 0.50;
    }

    void processNoPayCar()
    {
        carCount++;
    }

    void showDetails()
    {
        cout << "Total Cars: " << carCount << endl;
        cout << "Total Amount: " << totalAmount << endl;
    }
};

int main()
{
    TollBooth booth;
    while (true)
    {
        cout << "Enter (P for Pay | N for No Pay): ";
        char inputChar = _getch();

        if (inputChar == 27)
            break;

        if (inputChar == 'P' || inputChar == 'p')
        {
            booth.processPayingCar();
            cout << "Paid";
        }
        else if (inputChar == 'N' || inputChar == 'n')
        {
            booth.processNoPayCar();
            cout << "Not Paid";
        }

        cout << endl;
    }

    cout << endl;
    booth.showDetails();
}
