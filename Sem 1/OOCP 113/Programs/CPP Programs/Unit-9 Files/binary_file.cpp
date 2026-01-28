#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

// class student
class Student
{
    int rollno;
    char name[30];
    char address[40];

public:
    void input();
    void display();
};

// input
void Student::input()
{
    cout << "Enter your rollno:- ";
    cin >> rollno;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover '\n'

    cout << "Enter your name:- ";
    cin.getline(name, 30);

    cout << "Enter your address:- ";
    cin.getline(address, 40);

    cout << "\n";
}

// display
void Student::display()
{
    cout << "Your rollno: " << rollno << endl;
    cout << "Your name:- " << name << endl;
    cout << "Your address:- " << address << endl;
}

int main()
{
    Student stud_obj;

    // --- WRITE BINARY FILE ---
    ofstream file_obj("student.dat", ios::out | ios::binary | ios::trunc);
    if (!file_obj.is_open())
    {
        cout << "File cannot be opened for writing!\n";
        return 1;
    }

    char cont = 'y';
    do
    {
        stud_obj.input();
        file_obj.write((char *)&stud_obj, sizeof(stud_obj));

        if (file_obj.fail())
            cout << "File write failed!\n";

        cout << "Do you want to continue? (y/n):- ";
        cin >> cont;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
    } while (cont != 'n');

    file_obj.close();

    // --- READ BINARY FILE ---
    ifstream file_obj_read("student.dat", ios::in | ios::binary);
    if (!file_obj_read.is_open())
    {
        cout << "File cannot be opened for reading!\n";
        return 1;
    }

    cout << "\nReading records from file:\n\n";

    while (file_obj_read.read((char *)&stud_obj, sizeof(stud_obj)))
    {
        stud_obj.display();
        cout << endl;
    }

    if (!file_obj_read.eof())
        cout << "File read failed before EOF!\n";

    file_obj_read.close();
    return 0;
}
