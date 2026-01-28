//  Overload * operator
#include <iostream>
using namespace std;

class BankAccount
{
public:
    int accountNo;
    int customerId;
    double balance;

    // Constructor
    BankAccount(int accNo = 0, int custId = 0, double bal = 0)
    {
        accountNo = accNo;
        customerId = custId;
        balance = bal;
    }

    void display()
    {
        cout << "CustomerID: " << customerId
             << " | AccountNo: " << accountNo
             << " | Balance: " << balance << endl;
    }

    // Overload * operator to multiply balance by an int
    BankAccount operator*(int factor)
    {
        BankAccount temp;
        temp.accountNo = accountNo;
        temp.customerId = customerId;
        temp.balance = balance * factor;
        return temp;
    }
};

int main()
{
    BankAccount b1(101, 1, 5000);

    cout << "Original Account: \n";
    b1.display();

    int factor = 3;
    BankAccount b2 = b1 * factor; // use overloaded * operator

    cout << "\nAfter multiplying balance by " << factor << ":\n";
    b2.display();

    return 0;
}
