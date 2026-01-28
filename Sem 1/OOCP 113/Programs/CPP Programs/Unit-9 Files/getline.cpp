#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    char inputLine[80], outLine[80];
    ofstream entryFile("data.txt");
    cout << "input: - ";
    while (true)
    {
        cin.getline(inputLine, 80);
        if (!strcmp(inputLine, "End"))
            break;
        entryFile << inputLine;
    }
    entryFile.close();

    // reading
    ifstream displayFile("data.txt");
    while (!displayFile.eof())
    {
        displayFile.getline(outLine, 80);
        cout << outLine << endl;
    }
    displayFile.close();
    return 0;
}