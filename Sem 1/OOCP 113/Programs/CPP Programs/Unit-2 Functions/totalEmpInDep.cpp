#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int id;
    string name;
    string department;

public:
    // function to input employee details
    void input()
    {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Department: ";
        cin >> department;
    }

    // function to check if employee belongs to a given department
    bool isInDepartment(string dept)
    {
        return department == dept;
    }

    // optional: function to display details
    void display()
    {
        cout << "ID: " << id << ", Name: " << name << ", Department: " << department << endl;
    }
};

// 🔹 Function to count employees in a department
int countByDepartment(Employee empArr[], int n, string dept)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (empArr[i].isInDepartment(dept))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee employees[n];

    // Input employee details
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Employee " << i + 1 << ":\n";
        employees[i].input();
    }

    string dept;
    cout << "\nEnter department to search: ";
    cin >> dept;

    int total = countByDepartment(employees, n, dept);

    cout << "Total employees in " << dept << " department = " << total << endl;

    return 0;
}
