#include <iostream>
using namespace std;

class BankAccount
{
public:
    int accountNo;
    int customerId;
    double balance;

    BankAccount(int accNo = 0, int custId = 0, double bal = 0)
        : accountNo(accNo), customerId(custId), balance(bal) {}

    void display()
    {
        cout << "CustomerID: " << customerId
             << " | AccountNo: " << accountNo
             << " | Balance: " << balance << endl;
    }

    // 1️⃣ Member function operator*
    // Overload * operator (safe version)
    BankAccount operator*(int factor)
    {
        return BankAccount(accountNo, customerId, balance * factor);
    }
    
    // 2️⃣ Friend function operator*
    friend BankAccount operator*(int factor, const BankAccount &obj)
    {
        return BankAccount(obj.accountNo, obj.customerId, obj.balance * factor);
    }
};

int main()
{
    BankAccount b(101, 1, 5000);
    BankAccount b1(102, 2, 1000);

    cout << "Original Account: \n";
    b.display();
    b1.display();

    int factor = 3;
    BankAccount b2 = b * factor;      // use overloaded * operator
    BankAccount b3 = factor * 2 * b1; // use friend overloaded * operator

    cout << "\nAfter multiplying balance by " << factor << ":\n";
    b2.display();
    cout << "\nAfter multiplying balance by " << factor * 2 << ":\n";
    b3.display();

    cout << "\nOriginal Account remains unchanged:\n";
    b.display();
    b1.display();

    return 0;
}
