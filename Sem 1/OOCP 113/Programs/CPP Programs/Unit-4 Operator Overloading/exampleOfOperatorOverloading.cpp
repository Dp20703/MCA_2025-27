// Q. write a program to represent bank accounts of different customers with available balance use of concept overloading to calculate total available balance among all the accounts for same customerID.
#include <iostream>
using namespace std;

class BankAccount
{

public:
    int accountNo;
    double balance;
    int customerId;

    BankAccount(int accNo = 0, int custId = 0, double bal = 0)
    {
        accountNo = accNo;
        customerId = custId;
        balance = bal;
    }
   
    void input()
    {
        cout << "\nEnter CustomerID: ";
        cin >> customerId;
        cout << "Enter Account number: ";
        cin >> accountNo;
        cout << "Enter Account Balance: ";
        cin >> balance;
    }

    void display()
    {
        cout << "Customer Id: " << customerId
             << " | Account No: " << accountNo
             << " | Balance: " << balance << endl;
    }

    BankAccount operator+(BankAccount cust)
    {
        BankAccount temp;
        if (this->customerId == cust.customerId)
        {
            temp.customerId = this->customerId;
            temp.balance = this->balance + cust.balance;
        }
        return temp;
    }
    
    friend void checkCustomerId(BankAccount cust[], int n);
};

void checkCustomerId(BankAccount cust[], int n)
{
    bool visited[50] = {false}; // mark processed customers

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue; // skip if already counted

        BankAccount total = cust[i];
        for (int j = i + 1; j < n; j++)
        {
            if (cust[i].customerId == cust[j].customerId)
            {
                total = total + cust[j]; // use operator overloading
                visited[j] = true;       // mark as processed
            }
        }

        cout << "\nTotal balance for CustomerID "
             << cust[i].customerId
             << " = " << total.balance << endl;
    }
}

int main()
{
    int n = 3;
    BankAccount obj[n];

    cout << "Enter details of Customers:\n";
    for (int i = 0; i < n; i++)
    {
        obj[i].input();
    }

    cout << "\n--- Customer Details ---\n";
    for (int i = 0; i < n; i++)
    {
        obj[i].display();
    }

    checkCustomerId(obj, n);

    return 0;
}