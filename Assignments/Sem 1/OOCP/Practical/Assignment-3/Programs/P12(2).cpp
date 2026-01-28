#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeToFile(string fname1)
{
    ofstream out(fname1);
    string line;
    cout << "Enter line by line ( type . to stop ) \n";

    cin.ignore(); // to clear buffer after cin >>

    while (true)
    {
        getline(cin, line);
        if (line == ".")
            break;
        out << line << "\n";
    }

    out.close();
    cout << "Data written to file: " << fname1 << endl;
}

void readFromFile(string fname1)
{
    cout << "\nReading file: " << fname1 << "\n";
    ifstream in(fname1);
    string line;

    while (getline(in, line))
    {
        cout << line << "\n";
    }

    in.close();
}

void CountWordsLines(string fname1)
{
    cout << "\nCounting words and lines in: " << fname1 << "\n";

    ifstream in(fname1);
    string line;
    int words = 0, lines = 0;

    while (getline(in, line))
    {
        lines++;

        for (int i = 0; i < line.length(); i++)
        {
            if ((i == 0 || line[i - 1] == ' ') && line[i] != ' ')
            {
                words++;
            }
        }
    }

    in.close();
    cout << "Total lines: " << lines << "\n";
    cout << "Total words: " << words << "\n\n";
}

void CopyFile(string fname1, string fname2)
{
    ifstream src(fname1);
    ofstream dest(fname2);

    string line;

    while (getline(src, line))
    {
        dest << line << "\n";
    }

    src.close();
    dest.close();

    cout << "File copied to: " << fname2 << "\n";
}

int main()
{
    string fname1, fname2;
    int choice;

    cout << "Enter the main filename: ";
    cin >> fname1;

    while (true)
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Write into file\n";
        cout << "2. Read from file\n";
        cout << "3. Count words and lines\n";
        cout << "4. Copy file to another file\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            writeToFile(fname1);
        }
        else if (choice == 2)
        {
            readFromFile(fname1);
        }
        else if (choice == 3)
        {
            CountWordsLines(fname1);
        }
        else if (choice == 4)
        {
            cout << "Enter destination filename: ";
            cin >> fname2;
            CopyFile(fname1, fname2);
        }
        else if (choice == 5)
        {
            cout << "Exiting program...\n";
            break;
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
