#include <iostream>
using namespace std;

template <typename T, int size>
class Array
{
    T arr[size]; // Fixed-size array

public:
    // Set value at a given index
    void setValue(int index, T value)
    {
        if (index >= 0 && index < size)
        {
            arr[index] = value;
        }
        else
        {
            cout << "Invalid index value" << endl;
        }
    }

    // Display all elements of the array
    void displayValue()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Array<int, 5> intArray;
    Array<string, 5> strArray;

    for (int i = 0; i < 5; i++)
    {
        intArray.setValue(i, i * 10);
    }
    for (int i = 0; i < 5; i++)
    {
        strArray.setValue(i, "hello");
    }

    intArray.displayValue();
    strArray.displayValue();

    return 0;
}
