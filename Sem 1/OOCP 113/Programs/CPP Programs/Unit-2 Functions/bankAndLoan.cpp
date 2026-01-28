#include <iostream>
#include <string>
using namespace std;

class Loan; // forward declaration

class Bank
{
private:
    string name;
    float amount;

public:
    void input()
    {
        cout << "Enter Customer Name: ";
        cin >> name;
        cout << "Enter Bank Balance: ";
        cin >> amount;
    }

    void display()
    {
        cout << "Customer Name: " << name << endl;
        cout << "Bank Balance: " << amount << endl;
    }

    // declare friend function
    friend void checkEligibility(Bank b, Loan l);
};

class Loan
{
private:
    float requirement;

public:
    void inputRequirement()
    {
        cout << "Enter Loan Requirement: ";
        cin >> requirement;
    }

    // declare friend function
    friend void checkEligibility(Bank b, Loan l);
};

// 🔹 Friend function (can access private members of both classes)
void checkEligibility(Bank b, Loan l)
{
    float eligibleAmount = b.amount * 2;
    cout << "\nEligible Loan Amount = " << eligibleAmount << endl;

    if (l.requirement <= eligibleAmount)
    {
        cout << "✅ Loan Approved!" << endl;
    }
    else
    {
        cout << "❌ Loan Denied. Requirement exceeds eligibility." << endl;
    }
}

int main()
{
    Bank customer;
    customer.input();
    customer.display();

    Loan l;
    l.inputRequirement();

    // use friend function
    checkEligibility(customer, l);

    return 0;
}
