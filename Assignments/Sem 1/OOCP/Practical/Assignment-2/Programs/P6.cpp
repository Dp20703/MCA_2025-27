// 6) WAP to define a class Date with properties int month; int day; int year;
// overload the following operators.
// 5.1) + operator [a+b] (a is of date type and b is an integer),
//  use the assumption that all years have 360 days and
// months 30 days.
// 5.2) – operator [a-b(same as above)]
// 5.3) = operator
// 5.4) <,<=,>,>=
// 5.5) ++,--[post and pre both]

#include <iostream>
using namespace std;

class Date
{
    int month;
    int day;
    int year;

public:
    // constructor
    Date(int d = 1, int m = 1, int y = 1) : day(d), month(m), year(y) {};

    // normalize the date
    void normalize()
    {
        while (day > 30)
        {
            day -= 30;
            month++;
        }

        while (day <= 0)
        {
            day += 30;
            month--;
        }
        while (month > 12)
        {
            month -= 12;
            year++;
        }

        while (month <= 0)
        {
            month += 12;
            year--;
        }
    }

    // Overload '+' operator (Date + int days)
    Date operator+(int days)
    {
        Date temp = *this;
        temp.day += days;
        temp.normalize();
        return temp;
    }

    // Overload '-' operator (Date + int days)
    Date operator-(int days)
    {
        Date temp = *this;
        temp.day -= days;
        temp.normalize();
        return temp;
    }

    // Overload '=' operator (assignment)
    Date &operator=(const Date &other)
    {
        if (this != &other)
        {
            this->day = other.day;
            this->month = other.month;
            this->year = other.year;
        }
        return *this;
    }

    // convert date into totalDays
    int totalDays() const
    {
        return year * 360 + (month - 1) * 30 + (day - 1);
    }

    // overload <,<=,>,>= operators
    // overload ' < '
    bool operator<(const Date &other)
    {
        return totalDays() < other.totalDays();
    }
    // overload ' <= '
    bool operator<=(const Date &other)
    {
        return totalDays() <= other.totalDays();
    }
    // overload ' > '
    bool operator>(const Date &other)
    {
        return totalDays() > other.totalDays();
    }
    // overload ' >= '
    bool operator>=(const Date &other)
    {
        return totalDays() >= other.totalDays();
    }

    // overload ++,--[post and pre both] operators
    // Pre-increment (++date)
    Date &operator++()
    {
        day++;
        normalize();
        return *this;
    }
    // Post-increment (date++)
    Date operator++(int)
    {
        Date temp = *this;
        day++;
        normalize();
        return temp;
    }
    // Pre-decrement (--date)
    Date &operator--()
    {
        day--;
        normalize();
        return *this;
    }
    // Post-decrement (date--)
    Date operator--(int)
    {
        Date temp = *this;
        day--;
        normalize();
        return temp;
    }

    // display
    void display()
    {
        cout << "\tDay: " << day << "\t Month: " << month << "\tYear: " << year << endl;
    }
};
int main()
{
    Date a(12, 30, 2023);
    Date b;

    cout << "Original date a: ";
    a.display();

    // Adding 45 days
    b = a + 45;
    cout << "After adding 45 days: ";
    b.display();

    // Subtracting 40 days
    b = a - 40;
    cout << "After subtracting 40 days: ";
    b.display();

    // Assignment
    b = a;
    cout << "After assignment, b = ";
    b.display();

    // Comparison
    Date c(1, 1, 2024);
    cout << "Comparing a and c:" << endl;
    cout << "a < c: " << (a < c) << endl;
    cout << "a <= c: " << (a <= c) << endl;
    cout << "a > c: " << (a > c) << endl;
    cout << "a >= c: " << (a >= c) << endl;

    // Pre-increment
    ++a;
    cout << "After pre-increment ++a: ";
    a.display();

    // Post-increment
    a++;
    cout << "After post-increment a++: ";
    a.display();

    // Pre-decrement
    --a;
    cout << "After pre-decrement --a: ";
    a.display();

    // Post-decrement
    a--;
    cout << "After post-decrement a--: ";
    a.display();

    return 0;
}

// output

// Original date a:        Day: 12  Month: 30      Year: 2023
// After adding 45 days:   Day: 27  Month: 7       Year: 2025
// After subtracting 40 days:      Day: 2   Month: 5       Year: 2025
// After assignment, b =   Day: 12  Month: 30      Year: 2023
// Comparing a and c:
// a < c: 0
// a <= c: 0
// a > c: 1
// a >= c: 1
// After pre-increment ++a:        Day: 13  Month: 6       Year: 2025
// After post-increment a++:       Day: 14  Month: 6       Year: 2025
// After pre-decrement --a:        Day: 13  Month: 6       Year: 2025
// After post-decrement a--:       Day: 12  Month: 6       Year: 2025