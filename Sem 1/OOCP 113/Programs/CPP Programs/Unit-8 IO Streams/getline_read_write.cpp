#include <iostream>
using namespace std;

int main()
{
    char msg[100];
    cin.getline(msg, 100);
    cout.write(msg, 50);
    cout << endl;
    return 0;
}