// 8.Create class STUDENT having rollno, name and age as data members, also
// take subject with three subjects and initialize their value with minimum
// passing marks. Using member function, modify marks of student with specific
// rollno which is given by user.

#include <iostream>
#include <string>
using namespace std;

class Student
{

public:
    int rollno;
    string name;
    int age;
    int sub[3];
    // initialize minimum passing marks
    Student()
    {
        for (int i = 0; i < 3; i++)
        {
            sub[i] = 35;
        }
    }

    void input()
    {
        cout << "Enter rollno:";
        cin >> rollno;
        cout << "Enter name:";
        cin >> name;
        cout << "Enter age:";
        cin >> age;
    }
    void display()
    {
        cout << "\t Rollno: " << rollno << "\t Name: " << name << "\t Age:" << age << "\t Marks:";
        for (int i = 0; i < 3; i++)
        {
            cout << sub[i] << " ";
        }
        cout << " " << endl;
    }
};
// modifymarks using [roll no , student array of objects and numbers of students]:
void modifyMarks(int rollno, Student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i].rollno == rollno)
        {
            cout << "Enter new marks for 3 subjects:\n ";
            {
                for (int j = 0; j < 3; j++)
                {
                    cin >> s[i].sub[j];
                }
                cout << "Marks updated successfully!\n";
                return;
            }
        }
    }
    cout << "Roll number not found!\n";
}

int main()
{
    int n;
    cout << "How many students you want to store:";
    cin >> n;
    Student s[n];
    // input for students
    for (int i = 0; i < n; i++)
    {
        s[i].input();
    }
    // modify marks
    int no;
    cout << "Enter roll no to be updated: ";
    cin >> no;
    modifyMarks(no, s, n);

    // display
    cout << "display details:\n";
    for (int i = 0; i < n; i++)
    {
        s[i].display();
    }

    return 0;
}

// output:
// How many students you want to store:2
// Enter rollno:101
// Enter name:Darshan
// Enter age:22
// Enter rollno:102
// Enter name:Kp
// Enter age:23
// Enter roll no to be updated: 102
// Enter new marks for 3 subjects:
//  78
// 87
// 89
// Marks updated successfully!
// display details:
//          Rollno: 101     Name: Darshan   Age:22  Marks:35 35 35
//          Rollno: 102     Name: Kp        Age:23  Marks:78 87 89