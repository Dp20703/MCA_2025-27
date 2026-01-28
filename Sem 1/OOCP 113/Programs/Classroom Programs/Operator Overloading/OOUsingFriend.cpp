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

	friend Matrix operator*(Matrix, int);
	friend Matrix operator*(int, Matrix);
};
Matrix operator*(Matrix TempMatrix, int Multiplier)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			TempMatrix.Element[i][j] = Multiplier * TempMatrix.Element[i][j];
	return Matrix(TempMatrix.Element);
}
Matrix operator*(int Multiplier, Matrix TempMatrix)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			TempMatrix.Element[i][j] = Multiplier * TempMatrix.Element[i][j];
	return Matrix(TempMatrix.Element);
}
int main()
{
	int ArrayOfInt1[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int ArrayOfInt2[][3] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
	Matrix M1(ArrayOfInt1);
	Matrix M2(ArrayOfInt2);
	Matrix M3, M4;

	M1.Display();
	M3 = M1 * 5;
	M3.Display();

	M2.Display();
	M4 = 5 * M2;
	M4.Display();
}
