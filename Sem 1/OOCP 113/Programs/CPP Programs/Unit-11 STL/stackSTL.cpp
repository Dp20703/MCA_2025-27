#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Stack elements (Top to Bottom):" << endl;

    while (!s.empty()) {
        cout << s.top() << " ";  
        s.pop();                 
    }

    cout << endl;

    if (s.empty())
        cout << "Stack is now empty!" << endl;
    else
        cout << "Stack still has elements." << endl;

    return 0;
}

