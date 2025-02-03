#include <iostream>
#include <iomanip>
using namespace std;

class Angle
{
private:
    int deg;
    float min;
    char dir;

public:
    Angle(int degrees, float minutes, char direction) : deg(degrees), min(minutes), dir(direction) {}

    void inputAngle()
    {
        cout << "Enter degrees: ";
        cin >> deg;
        cout << "Enter minutes: ";
        cin >> min;
        cout << "Enter direction (N, S, E, W): ";
        cin >> dir;
    }

    void showAngle() const
    {
        cout << deg << "\xF8" << fixed << setprecision(1) << min << "' " << dir << endl;
    }
};

int main()
{
    Angle myAngle(149, 34.8, 'W');

    myAngle.showAngle();

    while (true)
    {
        myAngle.inputAngle();
        myAngle.showAngle();
    }

    return 0;
}
