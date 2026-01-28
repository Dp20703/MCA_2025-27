// 15) Write a template function called find(). This function searches an array for an
// object. It returns either the index of the matching object (if one is found) or
// -1 if no match is found.

#include <iostream>
#include <string>
using namespace std;

// Template function to find an element in the array
template <typename T>
int find(T arr[], int n, T target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// User-defined class Person
class Person
{
public:
    string name;
    int age;

    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {}

    // Overload equality operator to compare Person objects
    bool operator==(const Person &other) const
    {
        return (name == other.name && age == other.age);
    }
};

int main()
{
    cout << "Searching in arrays of different types:" << endl;

    // Integer array
    int intArr[] = {10, 20, 30, 40};
    int intSize = 4;
    int intTarget = 30;
    cout << "\nSearching for " << intTarget << " in integer array...\n";
    int index = find(intArr, intSize, intTarget);
    if (index != -1)
        cout << "Found at index " << index << endl;
    else
        cout << "Not found" << endl;

    // Float array
    float floatArr[] = {1.1, 2.2, 3.3, 4.4};
    int floatSize = 4;
    float floatTarget = 3.3;
    cout << "\nSearching for " << floatTarget << " in float array...\n";
    index = find(floatArr, floatSize, floatTarget);
    if (index != -1)
        cout << "Found at index " << index << endl;
    else
        cout << "Not found" << endl;

    // Character array
    char charArr[] = {'x', 'y', 'z'};
    int charSize = 3;
    char charTarget = 'y';
    cout << "\nSearching for '" << charTarget << "' in character array...\n";
    index = find(charArr, charSize, charTarget);
    if (index != -1)
        cout << "Found at index " << index << endl;
    else
        cout << "Not found" << endl;

    // Array of objects
    Person people[] = {
        Person("Darshan", 25),
        Person("dp", 30),
        Person("kp", 35)};
    int peopleSize = 3;
    Person target("dp", 30);
    cout << "\nSearching for Person (dp, 30) in Person array...\n";
    index = find(people, peopleSize, target);
    if (index != -1)
        cout << "Found at index " << index << endl;
    else
        cout << "Not found" << endl;

    return 0;
}

// output:

// Searching in arrays of different types:

// Searching for 30 in integer array...
// Found at index 2

// Searching for 3.3 in float array...
// Found at index 2

// Searching for 'y' in character array...
// Found at index 1

// Searching for Person (dp, 30) in Person array...
// Found at index 1