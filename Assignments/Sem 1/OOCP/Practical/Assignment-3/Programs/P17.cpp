// 17) Use an Employee Class to write records of employee to a file. Include a menu
// that will allow the user to select any of the following features
// a. Add a new record.
// b. Modify an existing record.
// c. Retrieve and display an entire record for a given name.
// d. Generate a complete list of all names, addresses and telephone numbers.
// e. End of the computation.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Employee
{
public:
    char name[30];
    char address[50];
    char phone[15];

    void readData()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Address: ";
        cin >> address;
        cout << "Enter Phone: ";
        cin >> phone;
    }

    void showData()
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "----------------------------\n";
    }
};

int main()
{
    Employee emp;
    fstream file;
    int choice;
    char searchName[30];

    while (true)
    {
        cout << "\n--- EMPLOYEE FILE MENU ---\n";
        cout << "1. Add New Record\n";
        cout << "2. Modify Existing Record\n";
        cout << "3. Display Record by Name\n";
        cout << "4. Display All Records\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 5)
            break;

        switch (choice)
        {

        case 1: // Add record
            file.open("employee.dat", ios::binary | ios::app);
            emp.readData();
            file.write((char *)&emp, sizeof(emp));
            file.close();
            break;

        case 2: // Modify record
            cout << "Enter name to modify: ";
            cin >> searchName;

            file.open("employee.dat", ios::binary | ios::in | ios::out);
            while (file.read((char *)&emp, sizeof(emp)))
            {
                if (strcmp(emp.name, searchName) == 0)
                {
                    cout << "Enter new details:\n";
                    emp.readData();
                    file.seekp(-sizeof(emp), ios::cur);
                    file.write((char *)&emp, sizeof(emp));
                    break;
                }
            }
            file.close();
            break;

        case 3: // Display specific record
            cout << "Enter name to search: ";
            cin >> searchName;

            file.open("employee.dat", ios::binary | ios::in);
            while (file.read((char *)&emp, sizeof(emp)))
            {
                if (strcmp(emp.name, searchName) == 0)
                {
                    emp.showData();
                    break;
                }
            }
            file.close();
            break;

        case 4: // Display all records
            file.open("employee.dat", ios::binary | ios::in);
            while (file.read((char *)&emp, sizeof(emp)))
            {
                emp.showData();
            }
            file.close();
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

// Output:

// --- EMPLOYEE FILE MENU ---
// 1. Add New Record
// 2. Modify Existing Record
// 3. Display Record by Name
// 4. Display All Records
// 5. Exit
// Enter choice: 1
// Enter Name: Khushi
// Enter Address: nikol
// Enter Phone: 8283

// --- EMPLOYEE FILE MENU ---
// 1. Add New Record
// 2. Modify Existing Record
// 3. Display Record by Name
// 4. Display All Records
// 5. Exit
// Enter choice: 4
// Name: Khushi
// Address: nikol
// Phone: 8283
// ----------------------------

// --- EMPLOYEE FILE MENU ---
// 1. Add New Record
// 2. Modify Existing Record
// 3. Display Record by Name
// 4. Display All Records
// 5. Exit
// Enter choice: 5