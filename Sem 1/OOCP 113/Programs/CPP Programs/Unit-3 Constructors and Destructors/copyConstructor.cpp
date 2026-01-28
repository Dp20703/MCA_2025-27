#include <iostream>
#include <string>
using namespace std;

class BankAcc
{
private:
    int accountNumber;
    string accountHolder; // std::string handles deep copy
    double balance;

public:
    BankAcc(int no, string name, double bal)
    {
        accountNumber = no;
        accountHolder = name;
        balance = bal;
    }

    // Copy Constructor (we don’t even need this, but showing explicitly)
    BankAcc(const BankAcc &old_obj)
    {
        accountNumber = old_obj.accountNumber;
        accountHolder = old_obj.accountHolder; // deep copy done internally
        balance = old_obj.balance;
        cout << "copy constructor called " << endl;
    }

    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAcc b1(411, "dp", 10000.75);
    b1.display();

    BankAcc b2 = b1; // deep copy handled by std::string
    b2.display();
    // BankAcc b3(b1); // deep copy handled by std::string
    // b3.display();

    return 0;
}
