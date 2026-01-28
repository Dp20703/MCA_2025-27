#include <iostream>
using namespace std;

int main()
{
    char ch;
    char data1[100];
    char data2[100];
    // input
    for (int i = 0;; i++)
    {
        cin.get(ch);
        if (ch == '\n')
        {
            data1[i] = '\0';
            break;
        }

        data1[i] = ch;
    }

    // output
    for (int i = 0; ch = data1[i]; i++)
    {
        cout.put(ch);
    }

    cout.put('\n');

    // input
    for (int i = 0;; i++)
    {
        ch = cin.get();
        if (ch == '\n')
        {
            data2[i] = '\0';
            break;
        }
        data2[i] = ch;
    }

    // output
    for (int i = 0; ch = data2[i]; i++)
    {
        cout.put(ch);
    }
    cout.put('\n');

    return 0;
}