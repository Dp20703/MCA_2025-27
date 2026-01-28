// 21) WAP to create namespace having function for total_marks. Show its use in
// class ‘marks’ of students, display total marks of subjects using namespace.

#include <iostream>
using namespace std;

namespace studentNS
{
    int total_marks(int a, int b, int c)
    {
        return a + b + c;
    }
}

class Marks
{
public:
    int s1, s2, s3;

    void input()
    {
        cout << "Enter marks of 3 subjects: ";
        cin >> s1 >> s2 >> s3;
    }

    void showTotal()
    {
        cout << "Total Marks = "
             << studentNS::total_marks(s1, s2, s3);
    }
};

int main()
{
    Marks m;
    m.input();
    m.showTotal();
    return 0;
}
// Output: 
// Enter marks of 3 subjects: 83 83 89
// Total Marks = 255