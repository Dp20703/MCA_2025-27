// 13) Write an object-oriented program to implement a generic Stack. Incorporate
// all the possible operation on Stack in the program.

#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    T *arr;
    int top;
    int capacity;

public:
    Stack(int size = 10)
    {
        capacity = size;
        cout << "Stack created of size " << capacity << endl;
        arr = new T[capacity];
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
        cout << "Stack destroyed\n";
    }

    void push(T value)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow! Cannot pop" << endl;
            cout << "Returning default value of T: " << T() << endl;
            return T();
        }
        return arr[top--];
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty !" << endl;
            return T();
        }
        return arr[top];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty !" << endl;
            return;
        }
        cout << "\nStack elements:\n";
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top >= capacity - 1;
    }
};

int main()
{
    Stack<char> s3(5);

    s3.display();
    cout << "Popped: " << s3.pop() << endl;

    s3.push('c');
    s3.push('a');
    s3.push('m');
    s3.push('p');
    s3.push('l');
    s3.push('x');

    s3.display();

    cout << "Top element: " << s3.peek() << endl;

    cout << "Popped: " << s3.pop() << endl;

    s3.display();

    return 0;
}
// output:
// Stack created of size 5
// Stack is empty !
// Stack underflow! Cannot pop
// Returning default value of T:
// Popped:
// Stack Overflow! Cannot push x

// Stack elements:
// c a m p l
// Top element: l
// Popped: l

// Stack elements:
// c a m p
// Stack destroyed