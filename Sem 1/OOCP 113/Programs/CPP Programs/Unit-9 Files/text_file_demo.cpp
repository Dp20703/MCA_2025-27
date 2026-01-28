#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Employee
{
protected:
    int empId;
    string name;

public:
    void inputEmployee()
    {
        cout << "Enter Employee ID: ";
        cin >> empId;
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, name);
    }

    void displayEmployee() const
    {
        cout << left << setw(15) << "Employee ID:" << empId << endl;
        cout << left << setw(15) << "Name:" << name << endl;
    }
};

class Salary : public Employee
{
    float basic, hra, da, total;

public:
    void inputSalary()
    {
        inputEmployee();
        cout << "Enter Basic Salary: ";
        cin >> basic;
        cout << "Enter HRA: ";
        cin >> hra;
        cout << "Enter DA: ";
        cin >> da;
        total = basic + hra + da;
    }

    void displaySalary() const
    {
        displayEmployee();
        cout << fixed << setprecision(2);
        cout << left << setw(15) << "Basic Salary:" << basic << endl;
        cout << left << setw(15) << "HRA:" << hra << endl;
        cout << left << setw(15) << "DA:" << da << endl;
        cout << left << setw(15) << "Total Salary:" << total << endl;
        cout << string(40, '-') << endl;
    }

    void writeToFile()
    {
        ofstream fout("salary.txt", ios::app);
        if (!fout)
        {
            cout << "Error opening file!\n";
            return;
        }

        fout << left << setw(10) << empId;
        fout << left << setw(15) << name;
        fout << right << setw(10) << fixed << setprecision(2) << basic;
        fout << right << setw(10) << hra;
        fout << right << setw(10) << da;
        fout << right << setw(10) << total << endl;
        fout.close();
        cout << "Record written to file successfully.\n";
    }

    void readFromFile()
    {
        ifstream fin("salary.txt");
        if (!fin)
        {
            cout << "File not found.\n";
            return;
        }

        cout << "\n"
             << string(70, '=') << endl;
        cout << left << setw(10) << "ID";
        cout << left << setw(15) << "Name";
        cout << right << setw(10) << "Basic";
        cout << right << setw(10) << "HRA";
        cout << right << setw(10) << "DA";
        cout << right << setw(10) << "Total" << endl;
        cout << string(70, '-') << endl;

        int id;
        string nm;
        float b, h, d, t;
        while (fin >> id >> nm >> b >> h >> d >> t)
        {
            cout << left << setw(10) << id;
            cout << left << setw(15) << nm;
            cout << right << setw(10) << fixed << setprecision(2) << b;
            cout << right << setw(10) << h;
            cout << right << setw(10) << d;
            cout << right << setw(10) << t << endl;
        }
        cout << string(70, '=') << endl;
        fin.close();
    }
};

int main()
{
    Salary s;
    int choice;

    while (true)
    {
        cout << "\n1. Add Employee Record";
        cout << "\n2. Display Records from File";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.inputSalary();
            s.writeToFile();
            break;
        case 2:
            s.readFromFile();
            break;
        case 3:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
