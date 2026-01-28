// 2) WAP to create student having data members (rollno, name, stream) as base
// class. Derive class subject with marks of 5 subjects and apply respective
// functionality. Calculate final result and display details of each student from
// derived class. (multilevel inheritance).

#include <iostream>
using namespace std;

class Student
{
    int rollno;
    string name;
    string stream;

public:
    Student()
    {
        cout << "Base constructor called ..." << endl;
    }
    virtual ~Student()
    {
        cout << "Base Destructor called" << endl;
    }
    void getData()
    {
        cout << "\nEnter Roll No: ";
        cin >> rollno;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Stream: ";
        cin >> stream;
    }
    void displayData()
    {
        cout << "\n--- Student Details ---" << endl;
        cout << "Roll No: " << rollno << "\nName: " << name << "\nStream: " << stream << endl;
    }
};

class Subject : public Student
{
protected:
    int marks[5];

public:
    Subject()
    {
        cout << "Subject class constructor called ..." << endl;
    }
    ~Subject()
    {
        cout << "Subject class Destructor called ..." << endl;
    }
    void getData()
    {
        Student::getData();
        cout << "\nEnter marks of 5 subjects:" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }
    void displayData()
    {
        Student::displayData();
        cout << "\n--- Marks Details ---" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i + 1 << ": " << marks[i] << endl;
        }
    }
};

class Result : public Subject
{
    int total = 0;
    float percentage;

public:
    Result()
    {
        cout << "Result class constructor called ..." << endl;
    }
    ~Result()
    {
        cout << "Result class destructor called ..." << endl;
    }
    void calResult()
    {
        total = 0;
        for (int i = 0; i < 5; i++)
        {
            total += marks[i];
        }
        percentage = (static_cast<float>(total) / 500) * 100;
    }
    void displayData()
    {
        calResult();
        Subject::displayData();
        cout << "\n--- Final Result ---" << endl;
        cout << "Total Marks: " << total << "/500" << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main()
{
    Result s1;
    s1.getData();
    s1.displayData();
    return 0;
}

// output:

// Base constructor called ...
// Subject class constructor called ...
// Result class constructor called ...

// Enter Roll No: 101
// Enter Name: dp
// Enter Stream: commerce

// Enter marks of 5 subjects:
// Subject 1: 83
// Subject 2: 32
// Subject 3: 83
// Subject 4: 23
// Subject 5: 33

// --- Student Details ---
// Roll No: 101
// Name: dp
// Stream: commerce

// --- Marks Details ---
// Subject 1: 83
// Subject 2: 32
// Subject 3: 83
// Subject 4: 23
// Subject 5: 33

// --- Final Result ---
// Total Marks: 254/500
// Percentage: 50.8%
// Result class destructor called ...
// Subject class Destructor called ...
// Base Destructor called