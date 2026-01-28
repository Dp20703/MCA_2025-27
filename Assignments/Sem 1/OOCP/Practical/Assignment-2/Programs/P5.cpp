// 5) WAP to define a matrix class and overload the * operator to multiply a number
// with matrix (Example: 5*Matrix should be possible).

#include <iostream>
using namespace std;

class matrix
{
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

    // Overloading '*' operator for matrix * scalar
    matrix operator*(int multiplier)
    {
        matrix result;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.mat[i][j] = mat[i][j] * multiplier;
            }
        }
        return result;
    }

    // Overloading '*' operator for scalar * matrix
    friend matrix operator*(int multiplier, matrix &obj);

    // Overloading '<<' operator to display matrix
    friend ostream &operator<<(ostream &out, const matrix &obj)
    {
        out << "Matrix values:" << endl;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                out << obj.mat[i][j] << "\t";
            }
            out << endl;
        }
        return out;
    }
};

// Definition of scalar * matrix
matrix operator*(int multiplier, matrix &obj)
{
    matrix result;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result.mat[i][j] = obj.mat[i][j] * multiplier;
        }
    }
    return result;
}

int main()
{
    matrix m1(2, 4, 8, 10), m2;

    cout << "Original matrix m1:" << endl;
    cout << m1;

    // matrix * scalar
    m2 = m1 * 5;
    cout << "After multiplying by 5:" << endl;
    cout << m2;

    // scalar * matrix
    m2 = 10 * m1;
    cout << "After multiplying by 10:" << endl;
    cout << m2;

    return 0;
}

// output:

// Original matrix m1:
// Matrix values:
// 2	4
// 8	10
// After multiplying by 5:
// Matrix values:
// 10	20
// 40	50
// After multiplying by 10:
// Matrix values:
// 20	40
// 80	100
