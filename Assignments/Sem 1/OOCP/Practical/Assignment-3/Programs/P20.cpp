// 20) Define a class marksheet. The class should contain a function
// PrintMarkSheet such that it prints the marksheet of a given student with
// three subject names and five marks for each subject. Define manipulators for
// displaying headings and footnotes. The function should display marksheet
// with respective headings and class. The marks should be aligned under the
// headings (Use either ios functions or manipulators).

#include <iostream>
#include <iomanip>
using namespace std;

class MarkSheet
{
public:
    void PrintMarkSheet()
    {
        string name;
        string sub1, sub2, sub3;
        int m1[5], m2[5], m3[5];

        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter Subject 1 name: ";
        getline(cin, sub1);

        cout << "Enter 5 marks for " << sub1 << ": ";
        for (int i = 0; i < 5; i++)
            cin >> m1[i];

        cin.ignore();

        cout << "Enter Subject 2 name: ";
        getline(cin, sub2);

        cout << "Enter 5 marks for " << sub2 << ": ";
        for (int i = 0; i < 5; i++)
            cin >> m2[i];

        cin.ignore();
        cout << "Enter Subject 3 name: ";
        getline(cin, sub3);
        cout << "Enter 5 marks for " << sub3 << ": ";
        for (int i = 0; i < 5; i++)
            cin >> m3[i];

        cout << "\n\n========== MARKSHEET ==========\n";
        cout << left << setw(20) << "Student Name: " << name << endl;
        cout << "-------------------------------------------\n";

        // headings
        cout << left << setw(15) << "Subject"
             << setw(8) << "M1"
             << setw(8) << "M2"
             << setw(8) << "M3"
             << setw(8) << "M4"
             << setw(8) << "M5" << endl;

        cout << "-------------------------------------------\n";

        // subject 1 marks
        cout << left << setw(15) << sub1;
        for (int i = 0; i < 5; i++)
            cout << setw(8) << m1[i];
        cout << endl;

        // subject 2 marks
        cout << left << setw(15) << sub2;
        for (int i = 0; i < 5; i++)
            cout << setw(8) << m2[i];
        cout << endl;

        // subject 3 marks
        cout << left << setw(15) << sub3;
        for (int i = 0; i < 5; i++)
            cout << setw(8) << m3[i];
        cout << endl;

        cout << "-------------------------------------------\n";
        cout << "=============== END ===============\n";
    }
};

int main()
{
    MarkSheet m;
    m.PrintMarkSheet();
    return 0;
}
// Output:

// Enter student name: Moksh
// Enter Subject 1 name: Science
// Enter 5 marks for Science: 83
// 23 53 53 53
// Enter Subject 2 name: Maths
// Enter 5 marks for Maths: 82
// 93
// 53
// 85
// 35
// Enter Subject 3 name: English
// Enter 5 marks for English: 88
// 98
// 78
// 99
// 90

// ========== MARKSHEET ==========
// Student Name:       Moksh
// -------------------------------------------
// Subject        M1      M2      M3      M4      M5
// -------------------------------------------
// Science        83      23      53      53      53
// Maths          82      93      53      85     35
// English        88      98      78      99      90
// -------------------------------------------
// =============== END ===============