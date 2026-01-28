// 4) WAP to define an object m1 of matrix class, use m1<<cout.
#include <iostream>
using namespace std;

class matrix
{
private:
    int mat[2][2];

public:
    // Constructor to initialize matrix elements
    matrix(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        mat[0][0] = a;
        mat[0][1] = b;
        mat[1][0] = c;
        mat[1][1] = d;
    }

    // Friend function to overload << operator
    friend ostream &operator<<(ostream &out, const matrix &m);
};

// Definition of overloaded << operator
ostream &operator<<(ostream &out, const matrix &m)
{
    out << m.mat[0][0] << " " << m.mat[0][1] << endl;
    out << m.mat[1][0] << " " << m.mat[1][1] << endl;
    return out;
}

int main()
{
    matrix m1(1, 2, 3, 4);

    cout << "The matrix m1 is:" << endl;
    cout << m1;

    return 0;
}

// output:
// The matrix m1 is:
// 1 2
// 3 4