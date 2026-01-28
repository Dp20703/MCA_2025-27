// 9) WAP to Overload the New and Delete for Stack Class.

#include <iostream>
#include <cstdlib> // for malloc and free
using namespace std;

class Stack
{
    int top;
    int capacity;
    int *arr;

public:
    // Constructor
    Stack(int size = 10)
    {
        capacity = size;
        top = -1;
        arr = new int[capacity];
        cout << "Stack created with capacity " << capacity << endl;
    }

    // Destructor
    ~Stack()
    {
        delete[] arr;
        cout << "Stack destroyed\n";
    }

    // Push operation
    void push(int value)
    {
        if (top >= capacity - 1)
        {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = value;
    }

    // Pop operation
    int pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow!\n";
            return -1;
        }
        return arr[top--];
    }

    // Display the stack
    void display()
    {
        if (top < 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Overloading new operator
    void *operator new(size_t size)
    {
        cout << "Overloading new for Stack, size = " << size << endl;
        void *ptr = malloc(size);
        if (!ptr)
        {
            throw bad_alloc();
        }
        return ptr;
    }

    // Overloading delete operator
    void operator delete(void *ptr)
    {
        cout << "Overloading delete for Stack\n";
        free(ptr);
    }
};

int main()
{
    // Using overloaded new and delete
    Stack *s = new Stack(5);

    s->push(10);
    s->push(20);
    s->push(30);
    s->display();

    cout << "Popped: " << s->pop() << endl;
    s->display();

    delete s; // Calls overloaded delete

    return 0;
}

// Output:

// Overloading new for Stack, size = 12
// Stack created with capacity 5
// Stack elements: 10 20 30
// Popped: 30
// Stack elements: 10 20
// Stack destroyed
// Overloading delete for Stack