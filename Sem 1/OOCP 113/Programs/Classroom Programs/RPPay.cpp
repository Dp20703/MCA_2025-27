// RPPay.cpp
#include <iostream>
#include <string>
using namespace std;

class Payment
{
public:
    virtual void pay(double amount)
    {
        cout << "Generic payment of " << amount << endl;
    }
    virtual ~Payment() {}
};
class CreditCardPayment : public Payment
{
    string cardNumber;

public:
    CreditCardPayment(string number) : cardNumber(number) {}

    void pay(double amount) override
    {
        cout << "Processing Credit Card payment of Rs. " << amount
             << " using Card Number: " << cardNumber << endl;
    }
};

class PayPalPayment : public Payment
{
    string email;

public:
    PayPalPayment(string mail) : email(mail) {}

    void pay(double amount) override
    {
        cout << "Processing PayPal payment of Rs. " << amount
             << " using Email: " << email << endl;
    }
};

class UpiPayment : public Payment
{
    string upiId;

public:
    UpiPayment(string id) : upiId(id) {}

    void pay(double amount) override
    {
        cout << "Processing UPI payment of Rs. " << amount
             << " using UPI ID: " << upiId << endl;
    }
};

int main()
{

    Payment *paymentMethod = NULL;

    int choice;
    double amount = 250.0;

    cout << "Choose Payment Method:\n";
    cout << "1. Credit Card\n";
    cout << "2. PayPal\n";
    cout << "3. UPI\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        paymentMethod = new CreditCardPayment("1234-5678-9876-5432");
        break;
    case 2:
        paymentMethod = new PayPalPayment("user@email.com");
        break;
    case 3:
        paymentMethod = new UpiPayment("user@upi");
        break;
    default:
        cout << "Invalid Choice!" << endl;
        return 0;
    }

    paymentMethod->pay(amount);

    delete paymentMethod;
    return 0;
}
