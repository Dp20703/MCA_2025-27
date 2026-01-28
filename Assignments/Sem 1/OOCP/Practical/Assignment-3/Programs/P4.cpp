// 4) An educational institution wishes to maintain a database of its employees.
// The database is divided into a number of classes whose hierarchical
// relationships are shown in fig-1. The figure also shows the minimum
// information required for each class. Specify all the classes and define function
// to create the database and retrieve individual information as and when
// required. Write parameterized constructor for each class in the hierarchy.

#include <iostream>
using namespace std;

// Base class: Staff
class Staff
{
    int code;
    string name;

public:
    Staff(int c, string n) : code(c), name(n)
    {
        cout << "\n[Staff Constructor Called...]";
    }
    virtual ~Staff()
    {
        cout << "\n[Staff Destructor Called...]";
    }
    virtual void DisplayData()
    {
        cout << "\n\n-- Details of Staff ---";
        cout << "\nCode of Staff: " << code;
        cout << "\nName of Staff: " << name;
    }
};

// Derived class: Teacher
class Teacher : public Staff
{
    string subject, publication;

public:
    Teacher(int c, string n, string s, string p)
        : Staff(c, n), subject(s), publication(p)
    {
        cout << "\n[Teacher Constructor Called...]";
    }
    ~Teacher()
    {
        cout << "\n[Teacher Destructor Called...]";
    }
    void DisplayData() override
    {
        Staff::DisplayData();
        cout << "\n-- Details of Teacher ---";
        cout << "\nSubject: " << subject;
        cout << "\nPublication: " << publication;
    }
};

// Derived class: Typist
class Typist : public Staff
{
protected:
    float speed;

public:
    Typist(int c, string n, float s) : Staff(c, n), speed(s)
    {
        cout << "\n[Typist Constructor Called...]";
    }
    ~Typist()
    {
        cout << "\n[Typist Destructor Called...]";
    }
    void DisplayData() override
    {
        Staff::DisplayData();
        cout << "\n-- Details of Typist ---";
        cout << "\nSpeed: " << speed;
    }
};

// Derived class: Officer
class Officer : public Staff
{
    char grade;

public:
    Officer(int c, string n, char g) : Staff(c, n), grade(g)
    {
        cout << "\n[Officer Constructor Called...]";
    }
    ~Officer()
    {
        cout << "\n[Officer Destructor Called...]";
    }
    void DisplayData() override
    {
        Staff::DisplayData();
        cout << "\n-- Details of Officer ---";
        cout << "\nGrade: " << grade;
    }
};

// Derived class: Regular (from Typist)
class Regular : public Typist
{
public:
    Regular(int c, string n, float s) : Typist(c, n, s)
    {
        cout << "\n[Regular Constructor Called...]";
    }
    ~Regular()
    {
        cout << "\n[Regular Destructor Called...]";
    }
    void DisplayData() override
    {
        Typist::DisplayData();
        cout << "\n-- Details of Regular Typist ---";
    }
};

// Derived class: Casual (from Typist)
class Casual : public Typist
{
    int dailywage;

public:
    Casual(int c, string n, float s, int da) : Typist(c, n, s), dailywage(da)
    {
        cout << "\n[Casual Constructor Called...]";
    }
    ~Casual()
    {
        cout << "\n[Casual Destructor Called...]";
    }
    void DisplayData() override
    {
        Typist::DisplayData();
        cout << "\n-- Details of Casual Typist ---";
        cout << "\nDaily Wage: " << dailywage;
    }
};

int main()
{
    cout << "\n========== Staff Database ==========\n";

    Staff s1(101, "Darshan");
    s1.DisplayData();

    Teacher t1(102, "Riya", "Maths", "Pearson");
    t1.DisplayData();

    Typist t2(103, "Anil", 85);
    t2.DisplayData();

    Officer o1(104, "Kavita", 'A');
    o1.DisplayData();

    Regular r1(105, "Rahul", 90);
    r1.DisplayData();

    Casual c1(106, "Priya", 75, 600);
    c1.DisplayData();

    cout << "\n\n====================================\n";
    return 0;
}

// output:
// ========== Staff Database ==========

// [Staff Constructor Called...]

// -- Details of Staff ---
// Code of Staff: 101
// Name of Staff: Darshan
// [Staff Constructor Called...]
// [Teacher Constructor Called...]

// -- Details of Staff ---
// Code of Staff: 102
// Name of Staff: Riya
// -- Details of Teacher ---
// Subject: Maths
// Publication: Pearson
// [Staff Constructor Called...]
// [Typist Constructor Called...]

// -- Details of Staff ---
// Code of Staff: 103
// Name of Staff: Anil
// -- Details of Typist ---
// Speed: 85
// [Staff Constructor Called...]
// [Officer Constructor Called...]

// -- Details of Staff ---
// Code of Staff: 104
// Name of Staff: Kavita
// -- Details of Officer ---
// Grade: A
// [Staff Constructor Called...]
// [Typist Constructor Called...]
// [Regular Constructor Called...]

// -- Details of Staff ---
// Code of Staff: 105
// Name of Staff: Rahul
// -- Details of Typist ---
// Speed: 90
// -- Details of Regular Typist ---
// [Staff Constructor Called...]
// [Typist Constructor Called...]
// [Casual Constructor Called...]

// -- Details of Staff ---
// Code of Staff: 106
// Name of Staff: Priya
// -- Details of Typist ---
// Speed: 75
// -- Details of Casual Typist ---
// Daily Wage: 600

// ====================================

// [Casual Destructor Called...]
// [Typist Destructor Called...]
// [Staff Destructor Called...]
// [Regular Destructor Called...]
// [Typist Destructor Called...]
// [Staff Destructor Called...]
// [Officer Destructor Called...]
// [Staff Destructor Called...]
// [Typist Destructor Called...]
// [Staff Destructor Called...]
// [Teacher Destructor Called...]
// [Staff Destructor Called...]
// [Staff Destructor Called...]