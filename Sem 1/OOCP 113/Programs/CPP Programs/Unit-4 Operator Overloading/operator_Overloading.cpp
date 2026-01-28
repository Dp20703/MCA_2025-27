// 🔹 Example 1 : Overloading + Operator(Bank Balance Addition)

#include <iostream>
using namespace std;

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double bal = 0.0) : balance(bal) {}

    // Overload + operator
    BankAccount operator+(const BankAccount &obj)
    {
        BankAccount temp;
        temp.balance = this->balance + obj.balance;
        return temp;

        // return BankAccount(this->balance+obj.balance);
    }

    void display()
    {
        cout << "Balance: " << balance << endl;
    }
};

// int main()
// {
//     BankAccount b1(5000.50), b2(3000.25);

//     BankAccount b3 = b1 + b2; // calls overloaded operator+
//     BankAcc b3 = b1.operator+(b2)
//     b1.display();
//     b2.display();
//     cout << "After Adding Balances:" << endl;
//     b3.display();

//     return 0;
// }

// 🔹 Example 2 : Overloading == Operator

#include <iostream>
using namespace std;

class BankAcc
{
private:
    int accountNumber;

public:
    BankAcc(int acc) : accountNumber(acc) {}

    void showAcc()
    {
        cout << "Account Number: " << accountNumber << endl;
    }

    // operator overload
    bool operator==(const BankAcc &obj)
    {
        return this->accountNumber == obj.accountNumber;
    }
};

int main()
{
    BankAcc b1(101), b2(101), b3(102);

    b1.showAcc(); // ✅ object accessing public function
    b2.showAcc();

    // b1.operator==(b2)
    if (b1 == b2) // ✅ object accessing overloaded operator
        cout << "b1 and b2 are same accounts" << endl;

    if (b1 == b3)
        cout << "b1 and b3 are same accounts" << endl;
    else
        cout << "b1 and b3 are different accounts" << endl;
}
