// 2. Write a program to create class Num (int n1, int n2, int n3, int n4). Display
// total and average of n1, n2, n3 and n4.

#include <iostream>
using namespace std;
class Num
{
	int n1;
	int n2;
	int n3;
	int n4;
	int total;
	int average;

public:
	// input values of numbers:
	void input()
	{
		cout << "Enter values of 4 numbers:" << endl;
		cin >> n1 >> n2 >> n3 >> n4;
	}
	void calculate()
	{
		total = n1 + n2 + n3 + n4;
		average = (total) / 4.0;
	}
	// display total and percentage:
	void display()
	{
		cout << "Total:" << total << endl;
		cout << "Average:" << average;
	}
};

int main()
{
	Num n;
	n.input();
	n.calculate();
	n.display();
	return 0;
}
// output:
//  Enter values of 4 numbers:
//  42
//  12
//  52
//  68
//  Total:174
//  Average:43