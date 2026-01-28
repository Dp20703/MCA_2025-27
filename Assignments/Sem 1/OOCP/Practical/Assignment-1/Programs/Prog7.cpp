// 7. Demonstrate the use of static variables in a class by using it to count the
// number of times the value is being inputted in the program.

#include <iostream>
using namespace std;
class Counter
{
    int val;
    static int count;

public:
    void input()
    {
        count++;
        cout << "Enter value :";
        cin >> val;
    }
    void display()
    {
        cout << "value :" << val << endl;
    }
    static void countValue()
    {
        cout << "Function is called " << count << " Times";
    }
};
// intialized variable
int Counter::count = 0;
int main()
{
    int n;
    cout << "How many values you want to enter? ";
    cin >> n;
    Counter c[n];
    for (int i = 0; i < n; i++)
    {
        c[i].input();
        c[i].display();
    }

    Counter::countValue();

    return 0;
}
// output:
// How many values you want to enter? 5
// Enter value :12
// value :12
// Enter value :52
// value :52
// Enter value :14
// value :14
// Enter value :25
// value :25
// Enter value :12
// value :12
// Function is called 5 Times