#include <stdio.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

int isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int daysInMonth(int month, int year)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
        return 29;

    return days[month - 1];
}

int isValidDate(Date date)
{
    if (date.year < 1 || date.month < 1 || date.month > 12 || date.day < 1 || date.day > daysInMonth(date.month, date.year))
        return 0;

    return 1;
}

int calculateDaysBetween(Date start, Date end)
{
    int totalDays = 0;
    while (start.year < end.year || (start.year == end.year && start.month < end.month) || (start.year == end.year && start.month == end.month && start.day < end.day))
    {
        start.day++;
        if (start.day > daysInMonth(start.month, start.year))
        {
            start.day = 1;
            start.month++;
            if (start.month > 12)
            {
                start.month = 1;
                start.year++;
            }
        }
        totalDays++;
    }
    return totalDays;
}

int dayOfWeek(Date date)
{
    int m = date.month;
    int y = date.year;
    if (m < 3)
    {
        m += 12;
        y--;
    }
    int k = y % 100;
    int j = y / 100;
    return (date.day + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
}

int main()
{
    Date firstDate, secondDate;

    printf("Enter first date (day month year): ");
    scanf("%d %d %d", &firstDate.day, &firstDate.month, &firstDate.year);

    printf("Enter second date (day month year): ");
    scanf("%d %d %d", &secondDate.day, &secondDate.month, &secondDate.year);

    if (!isValidDate(firstDate) || !isValidDate(secondDate))
    {
        printf("One of the dates is invalid.\n");
        return 0;
    }

    printf("Days between: %d\n", calculateDaysBetween(firstDate, secondDate));
    printf("Day of the week for the first date: %d\n", dayOfWeek(firstDate));
    printf("Day of the week for the second date: %d\n", dayOfWeek(secondDate));

    return 0;
}
