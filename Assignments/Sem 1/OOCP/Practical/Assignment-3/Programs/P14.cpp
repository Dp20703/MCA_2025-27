// 14) Define a class Result which contains the result of an MCA written test. It should take merit list from a file and display on the screen such that at a time only ten candidates information is printed on the screen. The headings should be displayed using a manipulator. All the information should be aligned with the headings.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    const string filename = "students.txt";
    ofstream ofs(filename);
    if (!ofs)
    {
        cerr << "Cannot create file.\n";
        return 1;
    }

    cout << "Enter name and marks for 5 students:\n";
    for (int i = 0; i < 5; ++i)
    {
        string name;
        int marks;
        cout << "Student " << i + 1 << " name: ";
        getline(cin, name);
        cout << "Student " << i + 1 << " marks: ";
        cin >> marks;
        cin.ignore();
        ofs << name << ',' << marks << '\n';
    }
    ofs.close();

    ifstream ifs(filename);
    if (!ifs)
    {
        cerr << "Cannot open file to read.\n";
        return 1;
    }

    cout << "\nSaved students:\n";
    string line;
    while (getline(ifs, line))
    {

        auto pos = line.find(',');
        if (pos != string::npos)
        {
            string name = line.substr(0, pos);
            string marks = line.substr(pos + 1);
            cout << "Name: " << name << "  Marks: " << marks << '\n';
        }
    }
    ifs.close();
    return 0;
}

// Output:

// Enter name and marks for 5 students:
// Student 1 name: Suresh
// Student 1 marks: 89
// Student 2 name: Mahesh
// Student 2 marks: 82
// Student 3 name: Khushi
// Student 3 marks: 82
// Student 4 name: Umang
// Student 4 marks: 98
// Student 5 name: Yash
// Student 5 marks: 78

// Saved students:
// Name: Suresh  Marks: 89
// Name: Mahesh  Marks: 82
// Name: Khushi  Marks: 82
// Name: Umang   Marks: 98
// Name: Yash   Marks: 78