#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name; // Data member: Student's name
    int age;     // Data member: Student's age

    // Static data member (shared by all objects of Student class)
    static int count;

public:
    // Constructor declaration
    Student();

    // Function declarations
    void input();             // Take input for one student
    void display();           // Display one student's details
    static void countValue(); // Static function to display count

    // --- EXTRA OPTION ---
    // If you want to access count directly outside, make it public
    // Uncomment below line if needed
    // static int count;
};

// Definition of static data member (must be outside class)
int Student::count = 0;

// Constructor definition
Student::Student()
{
    count++; // Increase count whenever an object is created
}

// Function definition: input student details
void Student::input()
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
}

// Function definition: display student details
void Student::display()
{
    cout << "Your name is " << name << endl;
    cout << "Your age is " << age << endl;
}

// Static function definition: display count value
void Student::countValue()
{
    cout << "Total count is " << count << endl;
}

int main()
{
    int n;
    cout << "Total students: ";
    cin >> n;

    // Create array of n students
    Student s1[n]; // Constructor runs n times → count increases automatically

    // Input details for each student
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        s1[i].input();
    }

    // Display details for each student
    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Student " << i + 1 << " ---\n";
        s1[i].display();
    }

    // Accessing static count using static function
    Student::countValue();

    // --- EXTRA OPTION ---
    // If you made count public, you can access it directly like this:
    // cout << "Direct access to count: " << Student::count << endl;

    return 0;
}
