#include <iostream>
using namespace std;
int main()
{
    // int i = 1234;
    // char str[10] = "Hello";
    int i;
    char str[10];

    // cin.width(7);
    // cin >> i;
    // cin.width(7);
    // cin >> str;
    // cout << i << str;
    cout.width(9);  
    cout.fill('-');
    cout<<1234; 
    cout.width(7);
    cout<<"hello";
    cout.width(8);
    cout.precision(5);
    cout<<1234.57;
    return 0;
}