// template + operator overloading + inheritance

#include <iostream>
#include <string>
using namespace std;
// => base class:  account
// data members:{ name, balance },
// Methods: { dispaly() , OO+=, OO-=, constructor()}

// => derived class: saving account
// data members:{ interestRate },
// Methods: {constructor, dispaly() ,applyInterest()}

// => template class : transaction
// Methods: { deposit(), withdraw()}

// base class : Account
class Account
{
protected:
    string accountHolder;
    double balance;

public:
    // constructor
    Account(string name, double bal) : accountHolder(name), balance(bal) {}
    // display
    virtual void display() const
    {
        cout << "Account Holder: " << this->accountHolder << endl;
        cout << "Balance: " << this->balance << endl;
    }
    // OO +=
    Account &operator+=(double amount)
    {
        balance += amount;
        return *this;
    }
    // OO -=
    Account &operator-=(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient Balance.." << endl;
        }
        else
        {
            balance -= amount;
        }
        return *this;
    }
};

// derived class: Saving account
class SavingAcc : public Account
{
    double interestRate;

public:
    // constructor
    SavingAcc(string name, double bal, double ir) : Account(name, bal), interestRate(ir) {}

    // display
    void display() const override
    {
        cout << " Savings Account " << accountHolder;
        cout << " | Balance: Rs. " << balance;
        cout << " | Interest Rate: " << interestRate << "%" << endl;
    }

    // applyinterest
    void applyInterest()
    {
        balance += (balance * interestRate / 100);
    }
};

// template class : Transaction
template <typename T>
class Transaction
{
public:
    static void deposit(Account &acc, T amount)
    {
        acc += amount;
    }
    static void withdraw(Account &acc, T amount)
    {
        acc -= amount;
    }
};
int main()
{
    SavingAcc sa("Darshan", 22000.00, 5.0);
    sa.display();

    sa.applyInterest();
    sa.display();

    Transaction<int>::withdraw(sa, 11000);
    sa.display();

    Transaction<int>::deposit(sa, 5000.22);
    sa.display();

    Transaction<double>::deposit(sa, 1000.25);
    sa.display();
    return 0;
}