#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int emp_id;          // Employee ID
    string emp_name;     // Employee name
    double basic_salary; // Basic salary
    double hra;          // House Rent Allowance
    double da;           // Dearness Allowance
    double gross_salary; // Gross Salary

public:
    // Constructor
    Employee()
    {
        emp_id = 0;
        emp_name = "";
        basic_salary = hra = da = gross_salary = 0.0;
    }

    // Function declarations
    void input();          // Take input from user
    void calculateGross(); // Calculate gross salary
    void display();        // Display employee details
};

// Function definition: Input values
void Employee::input()
{
    cout << "Enter Employee ID: ";
    cin >> emp_id;
    cout << "Enter Employee Name: ";
    cin >> emp_name;
    cout << "Enter Basic Salary: ";
    cin >> basic_salary;
    cout << "Enter HRA: ";
    cin >> hra;
    cout << "Enter DA: ";
    cin >> da;

    // Calculate gross salary immediately after input
    calculateGross();
}

// Function definition: Calculate gross salary
void Employee::calculateGross()
{
    gross_salary = basic_salary + hra + da;
}

// Function definition: Display values
void Employee::display()
{
    cout << "\n--- Employee Details ---" << endl;
    cout << "Employee ID: " << emp_id << endl;
    cout << "Employee Name: " << emp_name << endl;
    cout << "Basic Salary: " << basic_salary << endl;
    cout << "HRA: " << hra << endl;
    cout << "DA: " << da << endl;
    cout << "Gross Salary: " << gross_salary << endl;
}

int main()
{
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    // Array of objects
    Employee emp[n];

    // Input details for each employee
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for Employee " << i + 1 << ":\n";
        emp[i].input();
    }

    // Display details for each employee
    for (int i = 0; i < n; i++)
    {
        emp[i].display();
    }

    return 0;
}
