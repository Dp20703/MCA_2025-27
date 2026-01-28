#include <iostream>
using namespace std;

int &getElement(int arr[], int index)
{
    return arr[index]; // return reference
}

int main()
{
    int numbers[3] = {10, 20, 30};

    // Get reference to element
    getElement(numbers, 1) = 100; // modify original array

    cout << "Array after modification: ";
    for (int i = 0; i < 3; i++)
        cout << numbers[i] << " ";
    return 0;
}
