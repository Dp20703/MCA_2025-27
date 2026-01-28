// StackTemplateInheritance.cpp
#include <iostream>
using namespace std;

template <typename T>
class Container
{
protected:
    T arr[100];
    int size;

public:
    Container() : size(0) {}

    void add(const T &item)
    {
        if (size < 100)
        {
            arr[size++] = item;
        }
        else
        {
            cout << "Container is full" << endl;
        }
    }

    void display() const
    {
        cout << "Container items: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int getSize() const { return size; }
};

template <typename T>
class Stack : public Container<T>
{
public:
    void push(const T &item)
    {
        this->add(item);
    }

    void pop()
    {
        if (this->size > 0)
        {
            this->size--;
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }

    void top() const
    {
        if (this->size > 0)
        {
            cout << "Top: " << this->arr[this->size - 1] << endl;
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }
};

int main()
{
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();
    s.top();

    s.pop();
    s.display();
    s.top();

    return 0;
}