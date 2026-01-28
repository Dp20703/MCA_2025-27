#include <iostream>
using namespace std;

template <typename T>
class container
{
protected:
    T arr[100];
    int size;

public:
    container() { size = 0; }

    void addItem(const T &item)
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

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getSize()
    {
        return size;
    }
};

template <typename T>
class Stack : public container<T>
{
public:

    void push(const T &item)
    {
        this->addItem(item);
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
    cout << "Current size: " << s.getSize() << endl;
    s.display();
    s.top();

    s.pop();
    s.display();
    s.top();
    return 0;
}