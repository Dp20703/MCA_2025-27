// 10. Write a program to create class ‘Search’ having data members (int a[ ], x) and
// define member functions as void input(), void output(), void search(int position),
// void add(int value) to display result

#include <iostream>
using namespace std;
class Search
{
    int a[100];
    int n;
    int x;

public:
    void input();
    void output();
    void search(int position);
    void add(int value);
};

// input
void Search::input()
{
    cout << "Enter size of array:";
    cin >> n;

    cout << "\nEnter values of array element:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter element to be search:";
    cin >> x;
}

// output
void Search::output()
{
    cout << "\nvalues of array element:\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

// add
void Search::add(int value)
{
    a[n] = value;
    n++;
}
// search
void Search::search(int position)
{
    if (a[position] == x)
    {
        cout << "Element " << x << " is found at position " << position;
    }
    else
    {
        cout << "Element " << x << " not found! at position " << position;
    }
}
int main()
{
    Search s;
    s.input();
    s.output();
    s.add(50);
    cout << "\nAfter adding new element \n";
    s.output();
    int pos;
    cout << "\nEnter pos : ";
    cin >> pos;
    s.search(pos);
    return 0;
}
// output:

// Enter size of array:5

// Enter values of array element:
// 25
// 23
// 63
// 45
// 8
// Enter element to be search:8

// values of array element:
// 25 23 63 45 8
// After adding new element

// values of array element:
// 25 23 63 45 8 50
// Enter pos : 4
// Element 8 is found at position 4