// 3. Write a program to create class Time (int h, int m). Read a value as minutes
// from user to display new time after adding the value to minutes in Time.

#include <iostream>
using namespace std;

class Time
{
    int h;
    int m;

public:
    void input()
    {
        cout << "Enter hours:";
        cin >> h;
        cout << "Enter minutes:";
        cin >> m;
    }
    void addMinutes(int extra)
    {
        m += extra;  // total minutes = minutes+ extra
        h += m / 60; // total minutes/60 = add to hours
        m = m % 60;  // remining minutes
    }
    void display()
    {
        cout << "Total hours:" << h << "\n";
        cout << "Total minutes:" << m << "\n";
    }
};

int main()
{
    Time t;
    int extra;
    t.input();
    cout << "Enter extra minutes:";
    cin >> extra;
    t.addMinutes(extra);
    t.display();
    return 0;
}

// output:

// Enter hours:5
// Enter minutes:25
// Enter extra minutes:95
// Total hours:7
// Total minutes:0