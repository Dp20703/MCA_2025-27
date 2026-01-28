#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student
{
    int rollNumber;
    float totalMarks;

public:
    Student() {}

    Student(int rn, float tm)
    {
        rollNumber = rn;
        totalMarks = tm;
    }

    // =
    void operator=(Student TempStud)
    {
        rollNumber = TempStud.rollNumber;
        totalMarks = TempStud.totalMarks;
    }

    // <
    bool operator<(Student TempStud)
    {
        return (totalMarks < TempStud.totalMarks);
    }

    // <<
    friend ostream &operator<<(ostream &Tempout, Student TempStud);
};

ostream &operator<<(ostream &Tempout, Student TempStud) 
{
    Tempout << "\nRoll number: " << TempStud.rollNumber << " Total Marks:" << TempStud.totalMarks;
    return Tempout;
};

int main()
{
    vector <Student> StudMarks;
    float tempMarks;
    int i = 0;
    for (;;)
    {
        cout << "Enter marks for the rollno  " << i + 1 << " Enter -1 to stop:-";
        cin >> tempMarks;
        if (tempMarks == -1)
        {
            break;
        }
        StudMarks.push_back(Student(i + 1, tempMarks));
        ++i;
    }
    cout << "The size of StudMarks is:-" << StudMarks.size();

    vector<Student>::iterator index;
    sort(StudMarks.begin(), StudMarks.end());

    for (index = StudMarks.begin(); index < StudMarks.end(); ++index)
    {
        cout << *index;
    }

    return 0;
}