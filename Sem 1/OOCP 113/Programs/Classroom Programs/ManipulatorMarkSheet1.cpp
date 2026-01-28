//ManipulatorMarksheet1.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout<<setw(15)<< setiosflags(ios::left)<<setiosflags(ios::fixed)<<setprecision(2)<<setiosflags(ios::showpoint);
	cout << "Roll Number"<<setw(15)<< "Name"<<setw(10)<<setprecision(2)<< "Marks"<<endl;
	cout << setw(15)<< 1 << setw(15)<< "Lara"<< setw(10)<< setprecision(2)<< 355.50<<endl;
	cout << setw(15)<< 2 << setw(15)<< "Beckham" << setw(10)<< setprecision(2) << 275.00<<endl;
	cout << setw(15)<< 3 << setw(15)<< "Steffi" << setw(10)<< setprecision(2) << 290.75<<endl;
	cout << setw(15)<< 4 << setw(15)<< "Jaspal"<< setw(10)<< setprecision(2)<< 295.0<<endl;
	cout << setw(15)<< 5 << setw(15)<< "Rantunga"<< setw(10)<< setprecision(2)<< 200.60<<endl;
}
