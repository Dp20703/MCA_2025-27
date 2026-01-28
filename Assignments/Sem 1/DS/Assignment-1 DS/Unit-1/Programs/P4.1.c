// 4. Write a program to merge two arrays when they are sorted and when they are not sorted.

// _____________________Merged Unsorted array________________________________
#include <stdio.h>
#include <conio.h>
int main()
{
	int arr1[10], arr2[10], arr3[20];
	int i, n1, n2, m, index = 0;

	printf("\nEnter total elements in arr1:");
	scanf("%d", &n1);
	printf("\n Enter values in arr1:\n");
	for (i = 0; i < n1; i++)
	{
		printf("\n arr1[%d]: ", i);
		scanf("%d", &arr1[i]);
	}

	printf("\nEnter total elements in arr2:");
	scanf("%d", &n2);
	printf("\n Enter values in arr2:\n");
	for (i = 0; i < n2; i++)
	{
		printf("\n arr2[%d]: ", i);
		scanf("%d", &arr2[i]);
	}
	m = n1 + n2;
	for (i = 0; i < n1; i++)
	{
		arr3[index] = arr1[i];
		index++;
	}

	for (i = 0; i < n2; i++)
	{
		arr3[index] = arr2[i];
		index++;
	}

	printf("\n Printing merged unsorted array:\n");
	for (i = 0; i < m; i++)
	{
		printf("\n arr3[%d]=%d", i, arr3[i]);
	}

	return 0;
}

// output

// Enter total elements in arr1:5

//  Enter values in arr1:

//  arr1[0]: 1

//  arr1[1]: 2

//  arr1[2]: 3

//  arr1[3]: 4

//  arr1[4]: 5

// Enter total elements in arr2:4

//  Enter values in arr2:

//  arr2[0]: 20

//  arr2[1]: 30

//  arr2[2]: 40

//  arr2[3]: 50

//  Printing merged unsorted array:

//  arr3[0]=1
//  arr3[1]=2
//  arr3[2]=3
//  arr3[3]=4
//  arr3[4]=5
//  arr3[5]=20
//  arr3[6]=30
//  arr3[7]=40
//  arr3[8]=50