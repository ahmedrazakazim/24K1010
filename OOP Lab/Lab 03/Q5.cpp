#include <iostream>

using namespace std;

class Calendar
{
private:
    string *monthTasks[12];

    bool isValidDate(int day, int month)
    {
        if (month < 1 || month > 12)
        {
            return false;
        }

        int daysInCurrentMonth;

        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            daysInCurrentMonth = 31;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            daysInCurrentMonth = 30;
        }
        else
        {
            daysInCurrentMonth = 28;
        }

        if (day < 1 || day > daysInCurrentMonth)
        {
            return false;
        }

        return true;
    }

public:
    Calendar()
    {
        for (int i = 0; i < 12; i++)
        {
            int daysInCurrentMonth;

            if (i == 1) // February
            {
                daysInCurrentMonth = 28;
            }
            else if (i == 3 || i == 5 || i == 8 || i == 10) // Months with 30 days
            {
                daysInCurrentMonth = 30;
            }
            else // Months with 31 days
            {
                daysInCurrentMonth = 31;
            }

            monthTasks[i] = new string[daysInCurrentMonth];
        }
    }

    void addEvent(string details, int day, int month)
    {
        if (!isValidDate(day, month))
            return;

        monthTasks[month - 1][day - 1] = details;
        cout << "Added event: " << details << endl;
    }

    void removeEvent(int day, int month)
    {
        if (!isValidDate(day, month))
            return;

        monthTasks[month - 1][day - 1] = "";
        cout << "Removed event on Month " << month << ", Day " << day << endl;
    }

    void displayEvents()
    {
        for (int i = 0; i < 12; i++)
        {
            int daysInCurrentMonth = (i == 1) ? 28 : (i == 3 || i == 5 || i == 8 || i == 10) ? 30 : 31;
            for (int j = 0; j < daysInCurrentMonth; j++)
            {
                if (!monthTasks[i][j].empty())
                {
                    cout << "Month " << i + 1 << ", Day " << j + 1 << ": " << monthTasks[i][j] << endl;
                }
            }
        }
    }
};

int main()
{
    Calendar myCalendar;

    myCalendar.addEvent("Doctor's appointment", 10, 2);
    myCalendar.addEvent("Birthday party", 15, 12);
    myCalendar.addEvent("Project deadline", 30, 4);
    myCalendar.addEvent("Yoga class", 5, 4);
    myCalendar.addEvent("Grocery shopping", 12, 3);

    cout << endl;

    myCalendar.displayEvents();

    cout << endl;

    myCalendar.removeEvent(15, 12);

    cout << endl;
    myCalendar.displayEvents();
}
