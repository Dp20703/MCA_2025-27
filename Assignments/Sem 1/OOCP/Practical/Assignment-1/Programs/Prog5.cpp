// 5.Write a program to create class employee with employee’s id, name and basic
//  salary. Calculate gross salary for each employee(HRA 20%, DA 30%, OA 10%).

#include <iostream>
#include <string>
using namespace std;
class Emp
{
    int id;
    string name;
    float basic_salary;
    float HRA = 0.20;
    float DA = 0.30;
    float OA = 0.10;

public:
    void input();
    void display();
};
void Emp ::input()
{
    cout << "Enter emp id:";
    cin >> id;
    cout << "Enter emp name:";
    cin >> name;
    cout << "Enter basic_salary:";
    cin >> basic_salary;
}
void Emp::display()
{
    float hra = basic_salary * HRA;
    float da = basic_salary * DA;
    float oa = basic_salary * OA;
    float gross_salary = basic_salary + hra + da + oa;

    cout << "\nEmployee ID: " << id;
    cout << "\nEmployee Name: " << name;
    cout << "\nBasic Salary: " << basic_salary;
    cout << "\nHRA: " << hra;
    cout << "\nDA: " << da;
    cout << "\nOA: " << oa;
    cout << "\nGross Salary: " << gross_salary << endl;
}
int main()
{
    Emp e;
    e.input();
    e.display();
    return 0;
}

// output:
//  Enter emp id:101
//  Enter emp name:Darshan
//  Enter basic_salary:20000

// Employee ID: 101
// Employee Name: Darshan
// Basic Salary: 20000
// HRA: 4000
// DA: 6000
// OA: 2000
// Gross Salary: 32000
