#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    char ch;

    // write in file
    ofstream file("info2.txt");
    cout << "input : ";
    while (true)
    {
        ch = cin.get();
        if (ch == '$')
            break;
        file << ch;
    }
    file.close();

    // read file
    ifstream displayfile("info2.txt");
    cout << "Reading the file .." << endl;

    displayfile >> noskipws;
    while (displayfile.get(ch))
    {
        cout.put(ch);
    }
    displayfile.close();
    return 0;
}