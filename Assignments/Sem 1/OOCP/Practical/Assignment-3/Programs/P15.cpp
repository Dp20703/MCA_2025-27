// 15) Write a C++ program that displays a student object read from a file
// backwards.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream fin("student.txt");
    string name;
    int marks;

    vector<string> data;

    while (fin >> name >> marks)
    {
        data.push_back(name + " " + to_string(marks));
    }
    fin.close();

    cout << "\n--- Displaying students backwards ---\n";
    for (int i = data.size() - 1; i >= 0; i--)
    {
        cout << data[i] << endl;
    }

    return 0;
}

// Output:

// --- Displaying students backwards ---
// Khushi 83
// Usha 83
// Nilesh 33
// Mukesh 87
// Meera 78
