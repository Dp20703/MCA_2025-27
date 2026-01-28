// 14) Write a generic function that will sort a character string, integer and float
// value. Create a menu with appropriate options and accept the values from the
// user.
#include <iostream>
using namespace std;

// Template function to sort array or string
template <typename T>
void sortValues(T arr[], int n)
{
    // bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display the array or string
template <typename T>
void displayValues(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice;
    do
    {
        cout << "\n--- Sorting Menu ---\n";
        cout << "1. Sort a character string\n";
        cout << "2. Sort integer values\n";
        cout << "3. Sort float values\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            char str[100];
            cout << "Enter a string: ";
            cin >> str;
            int n = 0;
            while (str[n] != '\0')
                n++;
            sortValues(str, n);
            cout << "Sorted string: ";
            displayValues(str, n);
        }
        else if (choice == 2)
        {
            int n;
            cout << "Enter number of integers: ";
            cin >> n;
            int arr[100];
            cout << "Enter integers:\n";
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            sortValues(arr, n);
            cout << "Sorted integers: ";
            displayValues(arr, n);
        }
        else if (choice == 3)
        {
            int n;
            cout << "Enter number of floats: ";
            cin >> n;
            float arr[100];
            cout << "Enter floats:\n";
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            sortValues(arr, n);
            cout << "Sorted floats: ";
            displayValues(arr, n);
        }
        else if (choice == 0)
        {
            cout << "Exiting...\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}

// output

// --- Sorting Menu ---
// 1. Sort a character string
// 2. Sort integer values
// 3. Sort float values
// 0. Exit
// Enter your choice: 1
// Enter a string: xzyacb
// Sorted string: a b c x y z 

// --- Sorting Menu ---
// 1. Sort a character string
// 2. Sort integer values
// 3. Sort float values
// 0. Exit
// Enter your choice: 2
// Enter number of integers: 4
// Enter integers:
// 23
// 6
// 3
// 2
// Sorted integers: 2 3 6 23 

// --- Sorting Menu ---
// 1. Sort a character string
// 2. Sort integer values
// 3. Sort float values
// 0. Exit
// Enter your choice: 3
// Enter number of floats: 3
// Enter floats:
// 1.2 
// 2.3
// 0.2
// Sorted floats: 0.2 1.2 2.3 

// --- Sorting Menu ---
// 1. Sort a character string
// 2. Sort integer values
// 3. Sort float values
// 0. Exit
// Enter your choice: 0
// Exiting..