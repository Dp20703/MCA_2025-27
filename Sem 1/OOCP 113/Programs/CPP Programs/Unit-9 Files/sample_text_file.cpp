#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // ...................WRITING.........
    string inputLine;                  // simple variable for input value storage
    ofstream entryFile("Student.txt"); // create/open file

    // input code:
    cout << "Input:-";
    while (getline(cin, inputLine))
    {
        if (inputLine == "End") // type End to exit input
            break;
        entryFile << inputLine << endl; // writing to entryFile
    }
    entryFile.close();

    // ...................READING.........
    // output code:
    cout << "Output:" << endl;
    ifstream DisplayFile("Student.txt"); // open/read file
    string outputLine;                   // Simple variable for output value storage

    // Display

    // read word by word
    // while (!DisplayFile.eof())
    // {
    //     DisplayFile >> outputLine;
    //     cout << outputLine << "\n";
    // }
    // DisplayFile.close();

    // read line by line
    while (getline(DisplayFile, outputLine))
    {
        cout << outputLine << endl;
    }
    DisplayFile.close();
    return 0;
}