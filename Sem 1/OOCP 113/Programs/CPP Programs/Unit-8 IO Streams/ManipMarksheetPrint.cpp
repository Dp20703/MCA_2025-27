// ManipMarksheetPrint.cpp
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// ostream & PrintHeading(ostream & TempOut, string & Name)// our first manipulator
//{
//	TempOut<<setw(80)<< setiosflags(ios::left);
//	TempOut << Name <<endl
//		<<setw(80)<< "Standard 12th"<<endl;
//	return TempOut << Name;
// }
//  Wrapper object for heading manipulator
struct PrintHeading
{
	string name;
	PrintHeading(const string &n) : name(n) {}
};

// First manipulator (with wrapper)
ostream &operator<<(ostream &TempOut, const PrintHeading &h)
{
	TempOut << setw(80) << setiosflags(ios::left);
	TempOut << h.name << endl
			<< setw(80) << "Standard 12th" << endl;
	return TempOut;
}
ostream &PrintMarksheetHeading(ostream &TempOut) // our second manipulator
{
	TempOut << setw(15) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2) << setiosflags(ios::showpoint);
	TempOut << "Roll Number" << setw(15) << "Name" << setw(10) << setprecision(2) << "Marks" << endl;
	return TempOut;
}

ostream &PrintLine(ostream &TempOut) // our third manipulator
{
	TempOut << "-------------------------------------------";
	TempOut << endl;
	return TempOut;
}
int main()
{
	cout << PrintLine;
	cout << PrintHeading("GB Higher Secondary") << PrintLine << PrintMarksheetHeading;
	cout << PrintLine;
	cout << setw(15) << 1 << setw(15) << "Lara" << setw(10) << setprecision(2) << 355.50 << endl;
	cout << setw(15) << 2 << setw(15) << "Beckham" << setw(10) << setprecision(2) << 275.00 << endl;
	cout << setw(15) << 3 << setw(15) << "Steffi" << setw(10) << setprecision(2) << 290.75 << endl;
	cout << setw(15) << 4 << setw(15) << "Jaspal" << setw(10) << setprecision(2) << 295.0 << endl;
	cout << setw(15) << 5 << setw(15) << "Rantunga" << setw(10) << setprecision(2) << 200.60 << endl;
	cout << PrintLine;
}
