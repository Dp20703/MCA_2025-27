#include <iostream>
#include <string>
using namespace std;
class Emp
{
private:
    int emp_id;
    string emp_name;
    double basic_salary;
    double hra;
    double da;
    double gross_salary;
    static int count;

public:
    Emp()
    {
        count++;
        gross_salary = basic_salary = hra = da = 0.0;
    };
    void calculateGS();
    void input();
    void display();
    static void counts();
};

int Emp::count = 0;

void Emp::input()
{
    cout << "Enter emp_id:";
    cin >> emp_id;
    cout << "Enter emp_name:";
    cin >> emp_name;
    cout << "Enter basic_salary:";
    cin >> basic_salary;
    cout << "Enter hra:";
    cin >> hra;
    cout << "Enter da:";
    cin >> da;
    calculateGS();
}

void Emp::calculateGS()
{
    gross_salary = basic_salary + hra + da;
}

void Emp::display()
{
    cout << "Emp_id:" << emp_id << endl;
    cout << "emp_name:" << emp_name << endl;
    cout << "basic_salary:" << basic_salary << endl;
    cout << "hra:" << hra << endl;
    cout << "da:" << da << endl;
    cout << "gross_salary:" << gross_salary << endl;
}

void Emp ::counts()
{
    cout << "Total count:" << count;
}

int main()
{
    int n;

    cout << "Enter emp:";
    cin >> n;

    Emp emp[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value for emp " << i + 1 << endl;
        emp[i].input();
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Details for emp " << i + 1 << endl;
        emp[i].display();
    }

    Emp::counts();

    return 0;
}
