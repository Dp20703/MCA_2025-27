// The member initialization list
#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    // Using MIL
    BankAccount(int no, string name, double bal) : accountNumber(no), accountHolder(name), balance(bal)
    {
        cout << "Constructor with Member Initializer List called" << endl;
    }

    void display()
    {
        cout << "Account Number: " << accountNumber
             << " | Holder: " << accountHolder
             << " | Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount b1(101, "Darshan", 5000.75);
    b1.display();
    return 0;
}
