// 7) WAP to define a class Time with properties int hour; int minute; int second;
//  overload the following operators.
//  6.1) + operator [a+b] (a is of time type and b is an integer)
//  6.2) – operator [a-b(same as above)]
//  6.3) = operator
//  6.4) <,<=,>,>=
//  6.5) ++,--[post and pre both]
#include <iostream>
using namespace std;
class Time
{
    int hour;
    int minute;
    int second;

public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {};

    // Normalize the time
    void normalize()
    {
        while (second >= 60)
        {
            second -= 60;
            minute++;
        }
        while (second < 0)
        {
            second += 60;
            minute--;
        }
        while (minute >= 60)
        {
            minute -= 60;
            hour++;
        }
        while (minute < 0)
        {
            minute += 60;
            hour--;
        }
        while (hour >= 24)
        {
            hour -= 24;
        }
        while (hour < 0)
        {
            hour += 24;
        }
    }

    // operator ' + '
    Time operator+(int secs)
    {
        Time temp = *this;
        temp.second += secs;
        temp.normalize();
        return temp;
    }
    // operator ' - '
    Time operator-(int secs)
    {
        Time temp = *this;
        temp.second -= secs;
        temp.normalize();
        return temp;
    }
    // operator ' = '
    Time &operator=(const Time &temp)
    {

        if (this != &temp)
        {
            this->hour = temp.hour;
            this->minute = temp.minute;
            this->second = temp.second;
        }
        return *this;
    }

    // Convert total time to seconds for comparison
    int totalSeconds() const
    {
        return hour * 3600 + minute * 60 + second;
    }

    // Comparison operators
    bool operator<(const Time &t) const { return totalSeconds() < t.totalSeconds(); }
    bool operator<=(const Time &t) const { return totalSeconds() <= t.totalSeconds(); }
    bool operator>(const Time &t) const { return totalSeconds() > t.totalSeconds(); }
    bool operator>=(const Time &t) const { return totalSeconds() >= t.totalSeconds(); }
    // Pre-increment (++t) adds 1 second
    Time &operator++()
    {
        second++;
        normalize();
        return *this;
    }

    // Post-increment (t++) adds 1 second
    Time operator++(int)
    {
        Time temp = *this;
        second++;
        normalize();
        return temp;
    }

    // Pre-decrement (--t) subtracts 1 second
    Time &operator--()
    {
        second--;
        normalize();
        return *this;
    }

    // Post-decrement (t--) subtracts 1 second
    Time operator--(int)
    {
        Time temp = *this;
        second--;
        normalize();
        return temp;
    }
    // display time
    void
    display()
    {
        cout << (hour < 10 ? "0" : "") << hour << ":"
             << (minute < 10 ? "0" : "") << minute << ":"
             << (second < 10 ? "0" : "") << second << endl;
    }
};

int main()
{
    Time t1(23, 59, 50), t2;
    cout << "Original time t1: ";
    t1.display();

    // +
    t2 = t1 + 15;
    cout << "After adding 15 seconds:";
    t2.display();

    // +
    t2 = t1 - 75;
    cout << "After subtracting 75 seconds:";
    t2.display();

    // =
    t2 = t1;
    cout << "After assignment, t2 = ";
    t2.display();

    // Comparison
    Time t3(22, 59, 59);
    cout << "t1 < t3: " << (t1 < t3) << endl;
    cout << "t1 <= t3: " << (t1 <= t3) << endl;
    cout << "t1 > t3: " << (t1 > t3) << endl;
    cout << "t1 >= t3: " << (t1 >= t3) << endl;

    // Pre-increment
    ++t1;
    cout << "After pre-increment ++t1: ";
    t1.display();

    // Post-increment
    t1++;
    cout << "After post-increment t1++: ";
    t1.display();

    // Pre-decrement
    --t1;
    cout << "After pre-decrement --t1: ";
    t1.display();

    // Post-decrement
    t1--;
    cout << "After post-decrement t1--: ";
    t1.display();
    return 0;
}

// output
// Original time t1: 23:59:50
// After adding 15 seconds:00:00:05
// After subtracting 75 seconds:23:58:35
// After assignment, t2 = 23:59:50
// t1 < t3: 0
// t1 <= t3: 0
// t1 > t3: 1
// t1 >= t3: 1
// After pre-increment ++t1: 23:59:51
// After post-increment t1++: 23:59:52
// After pre-decrement --t1: 23:59:51
// After post-decrement t1--: 23:59:50