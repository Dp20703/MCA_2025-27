//FinalMarksheet.cpp
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
ostream & PrintHeading(ostream & TempOut)// our first manipulator
{
	TempOut<<setw(80)<< setiosflags(ios::left);
	TempOut << "GLS Higher Secondary" <<endl
		<<setw(80)<< "Standard 12th"<<endl;
	return TempOut ;
}
ostream & PrintMarksheetHeading(ostream & TempOut)// our second manipulator
{
	TempOut<<setw(15)<< setiosflags(ios::left)<<setiosflags(ios::fixed)<<setprecision(2)<<setiosflags(ios::showpoint);
	TempOut << "Roll Number"<<setw(15)<< "Name"<<setw(10)<<setprecision(2)<< "Marks"<<endl;
	return TempOut;
}
ostream & PrintLine(ostream & TempOut)// our third manipulator
{
	TempOut << "-------------------------------------------";
	TempOut << endl;
	return TempOut;
}
void FormatPrint(int TempRollNo, string TempName, float TempMarks);
int main()
{
	cout << PrintLine;
	cout <<  PrintHeading << PrintLine << PrintMarksheetHeading;
	cout << PrintLine;
	FormatPrint(1,"RamChandra", 275.0);
	FormatPrint(2,"Beckham", 275.0);
	FormatPrint(3,"Steffi", 290.75);
	FormatPrint(4,"Jaspal", 295.0);
	FormatPrint(5,"Rantunga", 200.60);
	
}
void FormatPrint(int TempRollNo, string TempName, float TempMarks)
{
cout << setw(15)<< TempRollNo << setw(15)<< TempName<< setw(10)<< setprecision(2)<< TempMarks<<endl;
}
