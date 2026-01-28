// 1. Write a program to create class Student with student’s rollno, name and
// marks of three subjects (OOCP, AI and MF) and display the details of student
// with total marks of all subjects along with the percentage in proper
// format.(Output should be in descending order of percentage.

#include <iostream>
#include <string>
using namespace std;

class Student
{
	int rollno;
	string name;
	int marks_oocp;
	int marks_ai;
	int marks_mf;
	int total;

public:
	float percentage;
	// Take input of student's Details:
	void input()
	{
		cout << "Enter roll no :";
		cin >> rollno;
		cout << "Enter name :";
		cin >> name;
		cout << "Enter marks of OOCP :";
		cin >> marks_oocp;

		cout << "Enter marks of AI :";
		cin >> marks_ai;
		cout << "Enter marks of MF :";
		cin >> marks_mf;
		cal();
	}

	// Calculate the total&percentage
	void cal()
	{
		total = marks_ai + marks_oocp + marks_mf;
		percentage = total / 3.0;
	}

	// display details of students in descending order by percentage
	void display()
	{
		cout << "\n";
		cout << "Your name is " << name << endl;
		cout << "Your rollno is " << rollno << endl;
		cout << "Your marks\n";
		cout << "OOCP:" << marks_oocp << endl;
		cout << "AI:" << marks_ai << endl;
		cout << "MF:" << marks_mf << endl;
		cout << "Total marks:" << total << endl;
		cout << "Percentage:" << percentage << "%" << endl;
	}
};

// function to sort students based on their percentage
void sortStudents(Student s[], int n)
{

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (s[j].percentage < s[j + 1].percentage)
			{
				Student temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int n;
	cout << "Enter total students:";
	cin >> n;
	Student *s = new Student[n];

	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter details for student: " << i + 1 << "\n";
		s[i].input();
	}
	sortStudents(s, n);

	cout << "\nPrinting Students in descending order of percentage " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "\nDetails of student: " << i + 1;
		s[i].display();
	}
	return 0;
}

// output:

// Enter details for student: 1
// Enter roll no :101
// Enter name :Darshan
// Enter marks of OOCP :45
// Enter marks of AI :65
// Enter marks of MF :89

// Enter details for student: 2
// Enter roll no :102
// Enter name :Meet
// Enter marks of OOCP :78
// Enter marks of AI :89
// Enter marks of MF :98

// Enter details for student: 3
// Enter roll no :103
// Enter name :Malav
// Enter marks of OOCP :89
// Enter marks of AI :74
// Enter marks of MF :56

// Printing Students in descending order of percentage

// Details of student: 1
// Your name is Meet
// Your rollno is 102
// Your marks
// OOCP:78
// AI:89
// MF:98
// Total marks:265
// Percentage:88.3333%

// Details of student: 2
// Your name is Malav
// Your rollno is 103
// Your marks
// OOCP:89
// AI:74
// MF:56
// Total marks:219
// Percentage:73%

// Details of student: 3
// Your name is Darshan
// Your rollno is 101
// Your marks
// OOCP:45
// AI:65
// MF:89
// Total marks:199
// Percentage:66.3333%