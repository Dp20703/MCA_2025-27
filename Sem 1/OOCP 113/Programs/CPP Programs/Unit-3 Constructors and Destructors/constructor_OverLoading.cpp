#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    // 1. Default Constructor
    BankAccount()
    {
        accountNumber = 0;
        accountHolder = "Unknown";
        balance = 0.0;
        cout << "Default Constructor called" << endl;
    }

    // 2. Parameterized Constructor (2 arguments)
    BankAccount(int no, string name)
    {
        accountNumber = no;
        accountHolder = name;
        balance = 0.0; // default balance
        cout << "Parameterized Constructor (2 args) called" << endl;
    }

    // 3. Parameterized Constructor (3 arguments)
    BankAccount(int no, string name, double bal)
    {
        accountNumber = no;
        accountHolder = name;
        balance = bal;
        cout << "Parameterized Constructor (3 args) called" << endl;
    }

    // Display function
    void display()
    {
        cout << "Account Number: " << accountNumber
             << " | Holder: " << accountHolder
             << " | Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount b1; // Calls Default Constructor
    b1.display();
    BankAccount b2(101, "Darshan"); // Calls Constructor with 2 arguments
    b2.display();
    BankAccount b3(102, "DP", 5000.75); // Calls Constructor with 3 arguments
    b3.display();

    return 0;
}
