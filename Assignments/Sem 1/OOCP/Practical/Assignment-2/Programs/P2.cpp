// 2) WAP to overload operator * which multiply a number to each element of an
// array within a class arrayContainer and display the result.
#include <iostream>
using namespace std;

class arrayContainer
{
private:
    int arr[7] = {1, 2, 3, 4, 5, 8, 10};

public:
    // Default constructor
    arrayContainer() {}

    // Overloading the '*' operator
    arrayContainer operator*(int num)
    {
        arrayContainer arr2;
        for (int i = 0; i < 7; i++)
        {
            arr2.arr[i] = arr[i] * num;
        }
        return arr2;
    }

    void display()
    {
        for (int i = 0; i < 7; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    arrayContainer a1, a2;

    cout << "Original array:" << endl;
    a1.display();

    a2 = a1 * 5; // Multiply each element by 5

    cout << "Array after multiplication:" << endl;
    a2.display();

    return 0;
}
// Output
// Original array:
// 1 2 3 4 5 8 10
// Array after multiplication:
// 5 10 15 20 25 40 50