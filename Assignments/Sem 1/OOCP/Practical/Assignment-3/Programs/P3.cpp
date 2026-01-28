// 3) WAP to create Class Person, Employee and Department and Apply respective
// functionalities using inheritance.

#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person()
    {
        cout << "\n[Person Constructor Called]" << endl;
    }

    virtual ~Person()
    {
        cout << "[Person Destructor Called]" << endl;
    }
    void getPersonaData()
    {
        cout << "Enter name:-";
        cin >> name;
        cout << "Enter age:-";
        cin >> age;
    }
    void displayPersonData()
    {
        cout << "\n --- Person Details --- \n";
        cout << "Name: " << name << "\n Age:" << age << endl;
    }
};

class Employee : public Person
{
protected:
    int empId;
    float salary;

public:
    Employee()
    {
        cout << "[Employee Constructor Called]" << endl;
    }

    ~Employee()
    {
        cout << "[Employee Destructor Called]" << endl;
    }
    void getEmployeeData()
    {
        getPersonaData();
        cout << "Enter Employee ID: ";
        cin >> empId;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayEmployeeData()
    {
        displayPersonData();
        cout << "\n--- Employee Details ---" << endl;
        cout << "Employee ID: " << empId << "\nSalary: " << salary << endl;
    }
};

class Department : public Employee
{
private:
    string deptName;
    string designation;

public:
    Department()
    {
        cout << "[Department Constructor Called]" << endl;
    }

    ~Department()
    {
        cout << "[Department Destructor Called]" << endl;
    }

    void getDepartmentData()
    {
        getEmployeeData();
        cout << "Enter Department Name: ";
        cin >> deptName;
        cout << "Enter Designation: ";
        cin >> designation;
    }

    void displayDepartmentData()
    {
        displayEmployeeData();
        cout << "\n--- Department Details ---" << endl;
        cout << "Department: " << deptName << "\nDesignation: " << designation << endl;
    }
};

int main()
{
    Department d1;

    cout << "\n Enter Department Employee Details:\n";
    d1.getDepartmentData();

    cout << "\n Display Details: \n";
    d1.displayDepartmentData();

    return 0;
}

// Output:
// [Person Constructor Called]
// [Employee Constructor Called]
// [Department Constructor Called]

//  Enter Department Employee Details:
// Enter name:-Darshan
// Enter age:-82
// Enter Employee ID: 101
// Enter Salary: 82300
// Enter Department Name: IT
// Enter Designation: senior web devloper

//  Display Details:

//  --- Person Details ---
// Name: Darshan
//  Age:82

// --- Employee Details ---
// Employee ID: 101
// Salary: 82300

// --- Department Details ---
// Department: IT
// Designation: senior
// [Department Destructor Called]
// [Employee Destructor Called]
// [Person Destructor Called]
