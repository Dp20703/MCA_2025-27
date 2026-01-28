// operator overloading for the subscript operator [].
#include <iostream>
using namespace std;
class SafeArray
{
    int Array[5];

public:
    int &operator[](int index)
    {
        if (index < 0 || index > 4)
        {
            cout << "Index out of bound...";
            exit(1);
        }
        return Array[index];
    }
    // void display()
    // {
    //     for (int i = 0; i < 5; i++)
    //     {
    //         cout << Array[i] << endl;
    //     }
    // }
};
int main()
{
    SafeArray sa, s1;
    sa[0] = 5;
    sa[1] = 5;
    sa[2] = 12;
    // sa.display();
    // sa[7] = 33;

    return 0;
}