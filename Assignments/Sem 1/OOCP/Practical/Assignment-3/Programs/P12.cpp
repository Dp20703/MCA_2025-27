// FILES
// 12) Write a Program to perform following operation on text file :
// 11.1) write content in a text file
// 11.2) read content from file
// 11.3) count no of word and no of lines in a file
// 11.4) copy contents of one file to another file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string fname1, fname2, line;

    cout << "Enter filename to write: ";
    cin >> fname1;
    cin.ignore();

    // Writing file
    ofstream out(fname1);
    cout << "Enter text (enter a single . to stop):\n";
    while (true)
    {
        getline(cin, line);
        if (line == ".")
            break;
        out << line << "\n";
    }
    out.close();

    cout << "Data written.\n\n";

    // Reading file
    cout << "Reading file: " << fname1 << "\n";
    ifstream in(fname1);

    while (getline(in, line))
    {
        cout << line << "\n";
    }
    in.close();
    cout << "\n";

    // count lines and words
    in.open(fname1);

    int lines = 0, words = 0;
    string word;

    while (getline(in, line))
    {
        lines++;
        for (int i = 0; i < line.length(); i++)
        {
            if ((i == 0 || line[i - 1] == ' ') && line[i] != ' ')
                words++;
        }
    }
    in.close();

    cout << "Total lines: " << lines << "\n";
    cout << "Total words: " << words << "\n\n";

    cout << "Enter destination filename to copy: ";
    cin >> fname2;

    ifstream src(fname1);
    ofstream dest(fname2);

    while (getline(src, line))
    {
        dest << line << "\n";
    }

    src.close();
    dest.close();

    cout << "File copied to " << fname2 << "\n";

    return 0;
}
// output:
// Enter filename to write: student.txt
// Enter text (enter a single . to stop):
// hello world by student
// .
// Data written.

// Reading file: student.txt
// hello world by student

// Total lines: 1
// Total words: 4

// Enter destination filename to copy: std.txt
// File copied to std.txt