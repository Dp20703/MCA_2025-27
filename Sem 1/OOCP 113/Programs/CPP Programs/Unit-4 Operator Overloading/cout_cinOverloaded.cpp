// cout and cin overloaded
#include <iostream>
using namespace std;

class BankAccount
{
public:
    int accountNo;
    int customerId;
    double balance;

    // Overload >> for input
    friend istream &operator>>(istream &in, BankAccount &obj)
    {
        cout << "Enter CustomerID: ";
        in >> obj.customerId;
        cout << "Enter Account No: ";
        in >> obj.accountNo;
        cout << "Enter Balance: ";
        in >> obj.balance;
        return in;
    }

    // Overload << for output
    friend ostream &operator<<(ostream &out, const BankAccount &obj)
    {
        out << "CustomerID: " << obj.customerId
            << " | AccountNo: " << obj.accountNo
            << " | Balance: " << obj.balance << endl;
        return out;
    }
};

int main()
{
    BankAccount b;

    cin >> b;  // uses overloaded >>
    cout << b; // uses overloaded <<

    return 0;
}
