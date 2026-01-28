// 9. Define a class to represent a bank account. Include the following members :
// DATA MEMBERS              MEMBER FUNCTIONS
// ------------------------ ------------------------------
// Name of depositor         (1) To assign initial values
// Account Number            (2) To Deposit the amount
// Type of Account           (3) To withdraw an amount after checking the
// Balance amount in account (4) To display name and balance

// Write C++ program to handle 10 customers.

#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    string name;
    int accNo;
    string type;
    double balance;

public:
    // (1) To assign initial values
    BankAccount(string n = "", int a = 0, string t = "", double b = 0.0)
    {
        name = n;
        accNo = a;
        type = t;
        balance = b;
    }
    // input from user
    void input()
    {
        cout << "Enter your name:";
        cin >> name;
        cout << "Enter your account number:";
        cin >> accNo;
        cout << "What is acc type? ";
        cin >> type;
        cout << "Enter your account balance:";
        cin >> balance;
    }
    // (2) To Deposit the amount
    void deposit(double amt)
    {
        balance += amt;
        cout << "\tDeposited:" << amt << "\tTotal balance:" << balance << endl;
        display();
    }
    // (3) To withdraw an amount after checking the
    void withdraw(double amt)
    {
        if (amt > balance)
        {
            cout << "Insuffient balance...";
            return;
        }
        else
        {
            balance -= amt;
            cout << "\tWithdrawal:" << amt << "\tTotal balance:" << balance << endl;
            display();
        }
    }
    // (4) To display name and balance
    void display()
    {
        cout << "\t Name:" << name << "\tAccount no:" << accNo << "\t Type of ac:" << type << "\tBalance:" << balance << endl;
    }
};
int main()
{
    int n = 10;
    BankAccount *cust = new BankAccount[n];
    cout << "Enter Details of Customers:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Customer: " << i + 1 << "\n";
        cust[i].input();
    }
    cout << "\n Details of Customers:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Customer: " << i + 1;
        cust[i].display();
    }
    cout << "\n";

    // deposit
    cust[0]
        .deposit(500);

    cout << "\n";
    // withdraw
    cust[1].withdraw(1000);

    delete[] cust;

    return 0;
}
// output:

// Enter Details of Customers:
// Customer: 1
// Enter your name:dp
// Enter your account number:101
// What is acc type? saving
// Enter your account balance:1200
// Customer: 2
// Enter your name:kp
// Enter your account number:1200
// What is acc type? current
// Enter your account balance:1250
// Customer: 3
// Enter your name:Garv
// Enter your account number:781
// What is acc type? current
// Enter your account balance:8999
// Customer: 4
// Enter your name:happy
// Enter your account number:1250
// What is acc type? current
// Enter your account balance:78000
// Customer: 5
// Enter your name:Taksh
// Enter your account number:878
// What is acc type? current
// Enter your account balance:125421
// Customer: 6
// Enter your name:Rahul
// Enter your account number:450
// What is acc type? current
// Enter your account balance:1212100
// Customer: 7
// Enter your name:umang
// Enter your account number:878
// What is acc type? Saving
// Enter your account balance:78200
// Customer: 8
// Enter your name:Yash
// Enter your account number:787
// What is acc type? Current
// Enter your account balance:1250
// Customer: 9
// Enter your name:Harsh
// Enter your account number:787
// What is acc type? Saving
// Enter your account balance:1200
// Customer: 10
// Enter your name:Dp
// Enter your account number:411
// What is acc type? Saving
// Enter your account balance:120000

//  Details of Customers:
// Customer: 1      Name:dp        Account no:101   Type of ac:saving      Balance:1200
// Customer: 2      Name:kp        Account no:1200  Type of ac:current     Balance:1250
// Customer: 3      Name:Garv      Account no:781   Type of ac:current     Balance:8999
// Customer: 4      Name:happy     Account no:1250  Type of ac:current     Balance:78000
// Customer: 5      Name:Taksh     Account no:878   Type of ac:current     Balance:125421
// Customer: 6      Name:Rahul     Account no:450   Type of ac:current     Balance:1.2121e+006
// Customer: 7      Name:umang     Account no:878   Type of ac:Saving      Balance:78200
// Customer: 8      Name:Yash      Account no:787   Type of ac:Current     Balance:1250
// Customer: 9      Name:Harsh     Account no:787   Type of ac:Saving      Balance:1200
// Customer: 10     Name:Dp        Account no:411   Type of ac:Saving      Balance:120000

//         Deposited:500   Total balance:1700
//          Name:dp        Account no:101   Type of ac:saving      Balance:1700

//         Withdrawal:1000 Total balance:250
//          Name:kp        Account no:1200  Type of ac:current     Balance:250