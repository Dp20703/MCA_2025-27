#include <iostream>
using namespace std;

class Matrix
{
	int Element[3][3];

public:
	Matrix() {};
	Matrix(int TempMatrix[3][3])
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Element[i][j] = TempMatrix[i][j];
	}
	void Read()
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				cin >> Element[i][j];
	}

	void operator-()
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Element[i][j] = -Element[i][j];
	}
	void Display()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << Element[i][j] << "  ";
			}
			cout << "\n";
		}
	}
};
int main()
{
	int ArrayOfInt[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	Matrix M1(ArrayOfInt);
	cout << "The First Matrix before negation is \n";
	M1.Display();
	cout << "1st Matrix after negation \n";
	-M1;
	M1.Display();
	Matrix M2;
	cout << "Enter Values for the second Matrix \n";
	M2.Read();
	cout << "2nd Matrix before negation \n";
	M2.Display();
	-M2;
	cout << "2nd Matrix after negation \n";
	M2.Display();

	M1.Display();
	return 0;
}
