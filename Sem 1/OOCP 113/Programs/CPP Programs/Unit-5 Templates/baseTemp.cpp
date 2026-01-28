#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

template <class T>
class Employee
{
protected:
    T empId;
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

    void displayEmployee()
    {
        cout << left << setw(15) << "Employee ID:" << empId << endl;
        cout << left << setw(15) << "Name:" << name << endl;
    }

    T getId() { return empId; }
    string getName() { return name; }
};

template <class T>
class Salary : public Employee<T>
{
    float basic, hra, da, total;

public:
    void inputSalary()
    {
        this->inputEmployee();
        cout << "Enter Basic Salary: ";
        cin >> basic;
        cout << "Enter HRA: ";
        cin >> hra;
        cout << "Enter DA: ";
        cin >> da;
        total = basic + hra + da;
    }

    void displaySalary()
    {
        this->displayEmployee();
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
        fout << left << setw(10) << this->empId
             << left << setw(15) << this->name
             << right << setw(10) << fixed << setprecision(2) << basic
             << right << setw(10) << hra
             << right << setw(10) << da
             << right << setw(10) << total << endl;
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
        cout << left << setw(10) << "ID"
             << left << setw(15) << "Name"
             << right << setw(10) << "Basic"
             << right << setw(10) << "HRA"
             << right << setw(10) << "DA"
             << right << setw(10) << "Total" << endl;
        cout << string(70, '-') << endl;

        string id, nm;
        float b, h, d, t;
        while (fin >> id >> nm >> b >> h >> d >> t)
        {
            cout << left << setw(10) << id
                 << left << setw(15) << nm
                 << right << setw(10) << fixed << setprecision(2) << b
                 << right << setw(10) << h
                 << right << setw(10) << d
                 << right << setw(10) << t << endl;
        }
        cout << string(70, '=') << endl;
        fin.close();
    }
};

int main()
{
    int choice;
    cout << "Choose ID Type:\n1. Integer ID\n2. String ID\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        Salary<int> s;
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
    }
    else if (choice == 2)
    {
        Salary<string> s;
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
    }
    else
    {
        cout << "Invalid selection.\n";
    }

    return 0;
}
