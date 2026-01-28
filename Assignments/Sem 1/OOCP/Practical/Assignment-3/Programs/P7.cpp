// 7) Define a class Student. Inherit this class into MCAStudent and
// NonMCAStudent. Also inherit it into Local and NonLocal students. Multiple
// inherit LocalMCAStudent from Local and MCAStudent. Define five instances
// of LocalMCAStudent with a constructor, assuming that all classes have a
// constructor.

// student=>local nonlocal mca nonmca
// local mca=> localMcaStudent

#include <iostream>
#include <string>
using namespace std;

// Base class
class Student
{
protected:
    string name;
    int rollNo;

public:
    Student(string n, int r)
    {
        name = n;
        rollNo = r;
        cout << "Student constructor called for " << name << endl;
    }

    void displayStudent()
    {
        cout << "Name: " << name << ", Roll No: " << rollNo << endl;
    }

    ~Student()
    {
        cout << "Student destructor called for " << name << endl;
    }
};

// Derived from Student
class MCAStudent : virtual public Student
{
protected:
    string specialization;

public:
    MCAStudent(string n, int r, string spec) : Student(n, r)
    {
        specialization = spec;
        cout << "MCAStudent constructor called for " << name << endl;
    }

    void displayMCA()
    {
        cout << "Specialization: " << specialization << endl;
    }

    ~MCAStudent()
    {
        cout << "MCAStudent destructor called for " << name << endl;
    }
};

// Derived from Student
class NonMCAStudent : public Student
{
protected:
    string courseName;

public:
    NonMCAStudent(string n, int r, string course) : Student(n, r)
    {
        courseName = course;
        cout << "NonMCAStudent constructor called for " << name << endl;
    }

    void displayNonMCA()
    {
        cout << "Course Name: " << courseName << endl;
    }

    ~NonMCAStudent()
    {
        cout << "NonMCAStudent destructor called for " << name << endl;
    }
};

// Another derived class from Student
class Local : virtual public Student
{
protected:
    string city;

public:
    Local(string n, int r, string c) : Student(n, r)
    {
        city = c;
        cout << "Local constructor called for " << name << endl;
    }

    void displayLocal()
    {
        cout << "City: " << city << endl;
    }

    ~Local()
    {
        cout << "Local destructor called for " << name << endl;
    }
};

// Another derived class from Student
class NonLocal : public Student
{
protected:
    string hostelName;

public:
    NonLocal(string n, int r, string hostel) : Student(n, r)
    {
        hostelName = hostel;
        cout << "NonLocal constructor called for " << name << endl;
    }

    void displayNonLocal()
    {
        cout << "Hostel: " << hostelName << endl;
    }

    ~NonLocal()
    {
        cout << "NonLocal destructor called for " << name << endl;
    }
};

// Multiple Inheritance
class LocalMCAStudent : public Local, public MCAStudent
{
public:
    LocalMCAStudent(string n, int r, string c, string spec)
        : Student(n, r), Local(n, r, c), MCAStudent(n, r, spec)
    {
        cout << "LocalMCAStudent constructor called for " << n << endl;
    }

    void display()
    {
        cout << "\n--- Local MCA Student Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "City: " << city << endl;
        cout << "Specialization: " << specialization << endl;
    }

    ~LocalMCAStudent()
    {
        cout << "LocalMCAStudent destructor called for " << name << endl;
    }
};

// Main function
int main()
{
    cout << "Creating Local MCA Students...\n";

    LocalMCAStudent s1("Darshan", 101, "Ahmedabad", "AI-ML");
    LocalMCAStudent s2("Raj", 102, "Vadodara", "Data Science");
    LocalMCAStudent s3("Priya", 103, "Surat", "Cyber Security");
    LocalMCAStudent s4("Karan", 104, "Rajkot", "Web Development");
    LocalMCAStudent s5("Neha", 105, "Bhavnagar", "Cloud Computing");

    cout << "\nDisplaying all students:\n";
    s1.display();
    s2.display();
    s3.display();
    s4.display();
    s5.display();

    cout << "\nProgram Ended...\n";
    return 0;
}

// // output:

// Creating Local MCA Students...
// Student constructor called for Darshan
// Local constructor called for Darshan
// MCAStudent constructor called for Darshan
// LocalMCAStudent constructor called for Darshan
// Student constructor called for Raj
// Local constructor called for Raj
// MCAStudent constructor called for Raj
// LocalMCAStudent constructor called for Raj
// Student constructor called for Priya
// Local constructor called for Priya
// MCAStudent constructor called for Priya
// LocalMCAStudent constructor called for Priya
// Student constructor called for Karan
// Local constructor called for Karan
// MCAStudent constructor called for Karan
// LocalMCAStudent constructor called for Karan
// Student constructor called for Neha
// Local constructor called for Neha
// MCAStudent constructor called for Neha
// LocalMCAStudent constructor called for Neha

// Displaying all students:

// --- Local MCA Student Details ---
// Name: Darshan
// Roll No: 101
// City: Ahmedabad
// Specialization: AI-ML

// --- Local MCA Student Details ---
// Name: Raj
// Roll No: 102
// City: Vadodara
// Specialization: Data Science

// --- Local MCA Student Details ---
// Name: Priya
// Roll No: 103
// City: Surat
// Specialization: Cyber Security

// --- Local MCA Student Details ---
// Name: Karan
// Roll No: 104
// City: Rajkot
// Specialization: Web Development

// --- Local MCA Student Details ---
// Name: Neha
// Roll No: 105
// City: Bhavnagar
// Specialization: Cloud Computing

// Program Ended...
// LocalMCAStudent destructor called for Neha
// MCAStudent destructor called for Neha
// Local destructor called for Neha
// Student destructor called for Neha
// LocalMCAStudent destructor called for Karan
// MCAStudent destructor called for Karan
// Local destructor called for Karan
// Student destructor called for Karan
// LocalMCAStudent destructor called for Priya
// MCAStudent destructor called for Priya
// Local destructor called for Priya
// Student destructor called for Priya
// LocalMCAStudent destructor called for Raj
// MCAStudent destructor called for Raj
// Local destructor called for Raj
// Student destructor called for Raj
// LocalMCAStudent destructor called for Darshan
// MCAStudent destructor called for Darshan
// Local destructor called for Darshan
// Student destructor called for Darshan