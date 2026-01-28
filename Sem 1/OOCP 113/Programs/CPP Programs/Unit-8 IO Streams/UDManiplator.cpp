#include <iostream>
using namespace std;

ostream &starline(ostream &output)
{
    output << "******************************" << endl;
    return output;
}

ostream &tab(ostream &output)
{
    output << "\t";
    return output;
}

int main()
{
    cout << starline;
    cout << "Name" << tab << "Subject" << tab << "Marks" << endl;
    cout << starline;
    cout << "Darshan" << tab << "OOCP" << tab << "95" << endl;
    cout << "Meet" << tab << "DS" << tab << "89" << endl;
    cout << starline;
    return 0;
}
