// A Vector using STL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student
{
private:
	int RollNumber;
	float TotalMarks;

public:
	Student(int TempRollNumber, float TempTotalMarks)
	{
		RollNumber = TempRollNumber;
		TotalMarks = TempTotalMarks;
	}

	void operator=(Student TempStud)
	{
		RollNumber = TempStud.RollNumber;
		TotalMarks = TempStud.TotalMarks;
	}

	bool operator<(Student TempStud)
	{
		return (TotalMarks < TempStud.TotalMarks);
	}

	friend ostream &operator<<(ostream &TempOut, Student &TempStud);
};

ostream &operator<<(ostream &TempOut, Student &TempStud)
{
	TempOut << "The mark of roll number " << TempStud.RollNumber << " is " << TempStud.TotalMarks;
	return TempOut;
}

int main()
{
	vector<Student> StudMarks;
	float TempMarks;

	int i = 0;

	for (;;)
	{
		cout << "Enter the mark for roll number " << i + 1 << " Enter -1 to stop: ";
		cin >> TempMarks;
		if (TempMarks == -1)
			break;

		StudMarks.push_back(Student(i + 1, TempMarks));
		++i;
	}

	cout << "The size of StudMarks is " << StudMarks.size() << endl;

	
	vector<Student>::iterator index;

	sort(StudMarks.begin(), StudMarks.end());

	for (index = StudMarks.begin(); index < StudMarks.end(); ++index)
		cout << *index << endl;

	return 0;
}
