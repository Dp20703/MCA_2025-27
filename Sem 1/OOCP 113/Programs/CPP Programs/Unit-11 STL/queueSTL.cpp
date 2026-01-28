#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Queue elements (Front to Rear):" << endl;

    while (!q.empty()) {
        cout << q.front() << " ";  
        q.pop();                  
    }

    cout << endl;

    if (q.empty())
        cout << "Queue is now empty!" << endl;
    else
        cout << "Queue still has elements." << endl;

    return 0;
}

