#include <iostream>
#include <string>
using namespace std;
// For Objects
class Student
{
public:
    string name;
    Student(string n)
    {
        name = n;
    };
};

int main()
{
    // 🔹 Basic Example

    //  int *ptr = new int; // dynamically allocate memory for 1 integer
    //  *ptr = 50;          // assign value
    //  cout << "Value: " << *ptr << endl;

    // delete ptr; // free memory

    // Dynamic Array
    // int n;
    // cout << "Enter size of array: ";
    // cin >> n;

    // int *arr = new int[n]; // dynamic array

    // // input values
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // // print values
    // cout << "Array elements: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // delete[] arr; // free memory of array

    // For Objects (Classes)
    Student *s1 = new Student("Darshan");
    cout << "Student Name: " << s1->name << endl;

    delete s1; // free memory
    return 0;
}
