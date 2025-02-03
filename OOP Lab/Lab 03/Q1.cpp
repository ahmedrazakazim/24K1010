#include <iostream>

using namespace std;

class Time
{
private:
    int hrs, mins, secs;

public:
    Time()
    {
        hrs = 0;
        mins = 0;
        secs = 0;
    }

    Time(int h, int m, int s)
    {
        hrs = h;
        mins = m;
        secs = s;
    }

    void show()
    {
        cout << hrs << ":" << mins << ":" << secs;
    }

    Time combine(Time tA, Time tB)
    {
        int totalSecs = tA.secs + tB.secs;
        int totalMins = tA.mins + tB.mins + (totalSecs / 60);
        int totalHrs = tA.hrs + tB.hrs + (totalMins / 60);

        totalSecs %= 60;
        totalMins %= 60;
        totalHrs %= 24;

        return Time(totalHrs, totalMins, totalSecs);
    }
};

int main()
{
    Time firstTime(1, 50, 30);
    Time secondTime(2, 20, 40);
    Time resultTime;

    resultTime = resultTime.combine(firstTime, secondTime);
    resultTime.show();

    return 0;
}
