// 4.Write a program to create class Date (int day, int month, int year). Read a
// value as day from user to display new date after adding the value to day in
// Date.

#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    void input()
    {
        cout << "Enter day:";
        cin >> day;

        cout << "Enter month:";
        cin >> month;

        cout << "Enter year:";
        cin >> year;
    }
    void addDays(int extra)
    {
        day += extra;
        // while (day > 30)
        // {
        //     day -= 30;
        //     month++;
        //     if (month > 12)
        //     {
        //         month = 1;
        //         year++;
        //     }
        // }
        // or //
        month += day / 30;
        day = day % 30;

        year += month / 12;
        month = month % 12;
        if (day == 0)
        {
            day = 30;
            month--;
            if (month == 0)
            {
                month = 12;
                year--;
            }
        }
    }
    void display()
    {
        cout << "\n";
        cout << "New Date: " << day << "/" << month << "/" << year << endl;
    }
};

int main()
{
    Date d;
    int extra;
    d.input();
    cout << "Enter extra days:";
    cin >> extra;
    d.addDays(extra);
    d.display();
    return 0;
}

// output:
// Enter day:5
// Enter month:12
// Enter year:1
// Enter extra days:25

// New Date: 30/12/1