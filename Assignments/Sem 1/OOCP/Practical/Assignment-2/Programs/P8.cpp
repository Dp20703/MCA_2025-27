// 8) Write a menu driven program that can perform the following functions on
// strings. (Use overloaded operators where possible).(Do not use predefined
// string function or class.)
// 1. Compare two strings for equality (== operator)
// 2. Check whether first string is smaller than the second (<= operator)
// 3. Copy the string to another
// 4. Extract a character from the string (Overload [])
// 5. Reverse the string
// 6. Concatenate two strings (+ operator)

#include <iostream>
using namespace std;

class MyString
{
    int length;
    char str[100];

public:
    // Default constructor
    MyString()
    {
        length = 0;
        str[0] = '\0';
    }

    // Constructor to initialize from char array
    MyString(const char s[])
    {
        length = 0;
        while (s[length] != '\0')
        {
            str[length] = s[length];
            length++;
        }
        str[length] = '\0';
    }

    // display string
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << str[i];
        }
        cout << endl;
    }

    //  1. Compare two strings for equality (== operator)
    // Overload '==' to compare two strings
    bool operator==(const MyString &other)
    {
        if (length != other.length)
            return false;
        for (int i = 0; i < length; i++)
        {
            if (str[i] != other.str[i])
                return false;
        }
        return true;
    }

    // 2. Check whether first string is smaller than the second (<= operator)
    // Overload '<=' to check if first string is smaller or equal lexicographically
    bool operator<=(const MyString &other)
    {
        int minLen = (length < other.length) ? length : other.length;
        for (int i = 0; i < minLen; i++)
        {
            if (str[i] < other.str[i])
                return true;
            else if (str[i] > other.str[i])
                return false;
        }
        return length <= other.length;
    }

    // 3. Copy the string to another
    // Overload '=' to copy one string to another
    MyString &operator=(const MyString &other)
    {
        length = other.length;
        for (int i = 0; i < length; i++)
        {
            str[i] = other.str[i];
        }
        str[length] = '\0';
        return *this;
    }

    // 4. Extract a character from the string (Overload [])
    // Overload '[]' to extract character at position
    char operator[](int index)
    {
        if (index >= 0 && index < length)
            return str[index];
        else
        {
            cout << "Index out of bounds!" << endl;
            return '\0';
        }
    }

    // 5. Reverse the string
    // Reverse the string
    void reverse()
    {
        for (int i = 0; i < length / 2; i++)
        {
            char temp = str[i];
            str[i] = str[length - i - 1];
            str[length - i - 1] = temp;
        }
    }

    // 6. Concatenate two strings (+ operator)
    // Overload '+' to concatenate two strings
    MyString operator+(const MyString &other)
    {
        MyString result;
        result.length = 0;
        // copy first string
        for (int i = 0; i < length; i++)
        {
            result.str[result.length++] = str[i];
        }
        // copy second string
        for (int i = 0; i < other.length; i++)
        {
            result.str[result.length++] = other.str[i];
        }
        // return concatenated string
        return result;
    }
};

int main()
{
    MyString s1, s2, s3;
    char temp[100];
    int choice;
    cout << "Enter string 1: ";
    cin >> temp;
    s1 = MyString(temp);

    cout << "Enter string 2: ";
    cin >> temp;
    s2 = MyString(temp);
    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Compare two strings (==)\n";
        cout << "2. Check if first string <= second string\n";
        cout << "3. Copy first string to another\n";
        cout << "4. Extract a character from first string ([])\n";
        cout << "5. Reverse the first string\n";
        cout << "6. Concatenate two strings (+)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (s1 == s2)
                cout << "Strings are equal.\n";
            else
                cout << "Strings are not equal.\n";
            break;
        case 2:
            if (s1 <= s2)
                cout << "First string is smaller or equal.\n";
            else
                cout << "First string is larger.\n";
            break;
        case 3:
            s3 = s1;
            cout << "After copying, new string is: ";
            s3.display();
            break;
        case 4:
            int index;
            cout << "Enter index to extract from first string: ";
            cin >> index;
            cout << "Character at index " << index << ": " << s1[index] << endl;
            break;
        case 5:
            s1.reverse();
            cout << "First string after reversing: ";
            s1.display();
            break;
        case 6:
            s3 = s1 + s2;
            cout << "After concatenation: ";
            s3.display();
            break;
        case 0:
            cout << "Exiting....\n";
            break;
        default:
            cout << "Invalid choice! \n";
        }
    }

    while (choice != 0);

    return 0;
}
// output:

// Enter string 1 : apple
// Enter string 2 : banana

//---Menu-- -
// 1. Compare two strings(==) 2. Check if first string <= second string
// 3. Copy first string to another
// 4. Extract a character from first string([]) 5. Reverse the first string
// 6. Concatenate two strings(+)
// 0. Exit
// Enter your choice : 1 Strings are not equal.

//---Menu-- -
// 1. Compare two strings(==) 2. Check if first string <= second string
// 3. Copy first string to another
// 4. Extract a character from first string([]) 5. Reverse the first string
// 6. Concatenate two strings(+)
// 0. Exit
// Enter your choice : 2 First string is smaller or equal.

//---Menu-- -
// 1. Compare two strings(==) 2. Check if first string <= second string
// 3. Copy first string to another
// 4. Extract a character from first string([]) 5. Reverse the first string
// 6. Concatenate two strings(+)
// 0. Exit
// Enter your choice : 3 After copying,
// new string is : apple

//---Menu-- -
// 1. Compare two strings(==) 2. Check if first string <= second string
// 3. Copy first string to another
// 4. Extract a character from first string([]) 5. Reverse the first string
// 6. Concatenate two strings(+)
// 0. Exit
// Enter your choice : 4
// Enter index to extract from first string : 3
// Character at index 3 : l

//---Menu-- -
// 1. Compare two strings(==) 2. Check if first string <= second string
// 3. Copy first string to another
// 4. Extract a character from first string([]) 5. Reverse the first string
// 6. Concatenate two strings(+)
// 0. Exit
//  your choice : 5 First string after reversing : elppa

//---Menu-- -
// 1. Compare two strings(==) 2. Check if first string <= second string
// 3. Copy first string to another
// 4. Extract a character from first string([]) 5. Reverse the first string
// 6. Concatenate two strings(+)
// 0. Exit
// Enter your choice : 6 After concatenation : elppabanana

//---Menu-- -
// 1. Compare two strings(==) 2. Check if first string <= second string
// 3. Copy first string to another
// 4. Extract a character from first string([]) 5. Reverse the first string
// 6. Concatenate two strings(+)
// 0. Exit
// Enter your choice : 0 Exiting....