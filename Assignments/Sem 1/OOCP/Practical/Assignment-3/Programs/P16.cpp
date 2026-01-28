
// 16) A file contains name and phone numbers. Name contains only one word and
// names and telephone numbers are separated by white spaces. Write a
// program which will include a menu driven functionality for the above file
// (a) Display 2 column output with names left justified and phone numbers
// right justified.
// Name Phone
// Ram 56789125
// Shyam 34565432
// Rahim 23456789
// Joseph 67213148
// (b) Determine the telephone number of a person.
// (c) Determine the name if the telephone number is known.
// (d) Update the telephone number.
// (e) Prefix all the telephone numbers by 2.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void display()
{
    ifstream fin("data.txt");
    if (!fin)
    {
        cout << "File not found!\n";
        return;
    }

    string name, phone;

    cout << left << setw(15) << "Name" << right << setw(15) << "Phone" << endl;
    cout << "----------------------------------------\n";

    while (fin >> name >> phone)
    {
        cout << left << setw(15) << name << right << setw(15) << phone << endl;
    }

    fin.close();
}

void searchPhoneByName()
{
    ifstream fin("data.txt");
    string name, phone, key;

    cout << "Enter name: ";
    cin >> key;

    bool found = false;

    while (fin >> name >> phone)
    {
        if (name == key)
        {
            cout << "Phone Number: " << phone << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Name not found.\n";
    fin.close();
}

void searchNameByPhone()
{
    ifstream fin("data.txt");
    string name, phone, key;

    cout << "Enter phone number: ";
    cin >> key;

    bool found = false;

    while (fin >> name >> phone)
    {
        if (phone == key)
        {
            cout << "Name: " << name << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Phone not found.\n";
    fin.close();
}

void updatePhone()
{
    ifstream fin("data.txt");
    ofstream fout("temp.txt");

    string name, phone, key, newPhone;
    cout << "Enter name to update phone: ";
    cin >> key;

    bool updated = false;

    while (fin >> name >> phone)
    {
        if (name == key)
        {
            cout << "Enter new phone: ";
            cin >> newPhone;
            fout << name << " " << newPhone << endl;
            updated = true;
        }
        else
        {
            fout << name << " " << phone << endl;
        }
    }

    fin.close();
    fout.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (updated)
        cout << "Updated successfully!\n";
    else
        cout << "Name not found!\n";
}

void prefixPhone()
{
    ifstream fin("data.txt");
    ofstream fout("temp.txt");

    string name, phone;

    while (fin >> name >> phone)
    {
        fout << name << " " << "2" + phone << endl;
    }

    fin.close();
    fout.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");

    cout << "All phone numbers prefixed with '2'.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- PHONE DIRECTORY MENU ---\n";
        cout << "1. Display (Names left, Phones right)\n";
        cout << "2. Search Phone by Name\n";
        cout << "3. Search Name by Phone\n";
        cout << "4. Update Phone Number\n";
        cout << "5. Prefix all Phone Numbers with 2\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            searchPhoneByName();
            break;
        case 3:
            searchNameByPhone();
            break;
        case 4:
            updatePhone();
            break;
        case 5:
            prefixPhone();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}

// Output:

// --- PHONE DIRECTORY MENU ---
// 1. Display (Names left, Phones right)
// 2. Search Phone by Name
// 3. Search Name by Phone
// 4. Update Phone Number
// 5. Prefix all Phone Numbers with 2
// 6. Exit
// Enter your choice: 1
// Name                     Phone
// ----------------------------------------
// Name                     Phone
// Ram                   56789125
// Shyam                 34565432
// Rahim                 23456789
// Joseph                67213148

// --- PHONE DIRECTORY MENU ---
// 1. Display (Names left, Phones right)
// 2. Search Phone by Name
// 3. Search Name by Phone
// 4. Update Phone Number
// 5. Prefix all Phone Numbers with 2
// 6. Exit
// Enter your choice: 2 Ram
// Enter name: Phone Number: 56789125

// --- PHONE DIRECTORY MENU ---
// 1. Display (Names left, Phones right)
// 2. Search Phone by Name
// 3. Search Name by Phone
// 4. Update Phone Number
// 5. Prefix all Phone Numbers with 2
// 6. Exit
// Enter your choice: 6
// Exiting...