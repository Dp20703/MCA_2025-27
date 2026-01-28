// 22) WAP to define a vector and use it for student class to store and display
// information about student (Use STL).

#include <iostream>
#include <vector>
using namespace std;

class Student
{
    string name;
    int age;

public:
    void read()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age : ";
        cin >> age;
    }
    void show()
    {
        cout << name << "\t" << age << endl;
    }
};

int main()
{
    vector<Student> v;
    int n;

    cout << "How many students? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Student s;
        s.read();
        v.push_back(s);
    }

    cout << "\n--- Student Details ---\n";
    for (auto &x : v)
        x.show();

    return 0;
}
// Output:
// How many students? 2
// Enter name: Moksh
// Enter age : 25
// Enter name: Umang
// Enter age : 48

// --- Student Details ---
// Moksh   25
// Umang   48