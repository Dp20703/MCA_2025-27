// 18) Write a program that stores and displays the records of the customer from a
// file the following information for account of the customer is to be stored.
// Account no, account type, name, old balance, new balance, last payment,
// date of last payment. Also display the current account status by comparing
// current payment and previous balance. Also calculate the current balance by
// subtracting the current payment from the previous balance.

#include <iostream>
#include <fstream>
using namespace std;

struct Customer
{
    int accNo;
    char accType[10];
    char name[20];
    float oldBalance;
    float lastPayment;
    float newBalance;
    char lastPayDate[15];
};

int main()
{
    Customer c;

    // -------- WRITE RECORD --------
    ofstream fout("customer.txt");
    if (!fout)
    {
        cout << "Error opening file!";
        return 0;
    }

    cout << "Enter Account No: ";
    cin >> c.accNo;

    cout << "Enter Account Type: ";
    cin >> c.accType;

    cout << "Enter Name: ";
    cin >> c.name;

    cout << "Enter Old Balance: ";
    cin >> c.oldBalance;

    cout << "Enter Last Payment: ";
    cin >> c.lastPayment;

    cout << "Enter Date of Last Payment: ";
    cin >> c.lastPayDate;

    // Calculate new balance
    c.newBalance = c.oldBalance - c.lastPayment;

    // Write to file
    fout << c.accNo << " "
         << c.accType << " "
         << c.name << " "
         << c.oldBalance << " "
         << c.lastPayment << " "
         << c.newBalance << " "
         << c.lastPayDate;

    fout.close();

    // -------- READ & DISPLAY --------
    ifstream fin("customer.txt");
    if (!fin)
    {
        cout << "Error reading file!";
        return 0;
    }

    fin >> c.accNo >> c.accType >> c.name >> c.oldBalance >> c.lastPayment >> c.newBalance >> c.lastPayDate;

    fin.close();

    cout << "\n---- CUSTOMER DETAILS ----\n";
    cout << "Account No: " << c.accNo << endl;
    cout << "Account Type: " << c.accType << endl;
    cout << "Name: " << c.name << endl;
    cout << "Old Balance: " << c.oldBalance << endl;
    cout << "Last Payment: " << c.lastPayment << endl;
    cout << "Date of Last Payment: " << c.lastPayDate << endl;
    cout << "New Balance: " << c.newBalance << endl;

    // -------- STATUS CHECK --------
    if (c.lastPayment >= c.oldBalance)
        cout << "Account Status: CLEAR\n";
    else
        cout << "Account Status: PENDING\n";

    return 0;
}

// Output:
// Enter Account No: 833
// Enter Account Type: Saving
// Enter Name: Manoj
// Enter Old Balance: 80000
// Enter Last Payment: 823
// Enter Date of Last Payment: 20th may

// ---- CUSTOMER DETAILS ----
// Account No: 833
// Account Type: Saving
// Name: Manoj
// Old Balance: 80000
// Last Payment: 823
// Date of Last Payment: 20th
// New Balance: 79177
// Account Status: PENDING