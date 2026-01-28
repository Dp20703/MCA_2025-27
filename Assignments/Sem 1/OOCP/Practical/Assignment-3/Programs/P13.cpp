// 13) Write a program to create a file student to store name and marks of 5
// students and then display them.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout("student.txt");

    string name;
    int marks;

    // Write data of 5 students
    cout << "Enter name and marks of 5 students:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << i + 1 << " Name: ";
        cin >> name;
        cout << "Marks: ";
        cin >> marks;

        fout << name << " " << marks << endl;
    }

    fout.close();

    // Read and display
    ifstream fin("student.txt");

    cout << "\n--- Student Details from File ---\n";
    while (fin >> name >> marks)
    {
        cout << "Name: " << name << ", Marks: " << marks << endl;
    }

    fin.close();
    return 0;
}

// Output:

// Enter name and marks of 5 students:
// Student 1 Name: Meera
// Marks: 78
// Student 2 Name: Mukesh
// Marks: 87
// Student 3 Name: Nilesh
// Marks: 33
// Student 4 Name: Usha
// Marks: 83
// Student 5 Name: Khushi
// Marks: 83

// --- Student Details from File ---
// Name: Meera, Marks: 78
// Name: Mukesh, Marks: 87
// Name: Nilesh, Marks: 33
// Name: Usha, Marks: 83
// Name: Khushi, Marks: 83