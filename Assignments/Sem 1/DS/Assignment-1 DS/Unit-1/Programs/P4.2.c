// 4. Write a program to merge two arrays when they are sorted and when they are not sorted.

//_____________________Merged Sorted array________________________________

#include <stdio.h>
#include <conio.h>
int main()
{
	int arr1[10], arr2[10], arr3[20];
	int i, n1, n2, m, first = 0, sec = 0, index = 0;

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
	while (first < n1 && sec < n2)
	{
		if (arr1[first] < arr2[sec])
		{
			arr3[index++] = arr1[first++];
		}
		else
		{
			arr3[index++] = arr2[sec++];
		}
	}

	while (first < n1)
	{
		arr3[index++] = arr1[first++];
	}
	while (sec < n2)
	{
		arr3[index++] = arr2[sec++];
	}

	printf("\n Printing merged sorted array:\n");
	for (i = 0; i < m; i++)
	{
		printf("\n arr3[%d]=%d", i, arr3[i]);
	}

	return 0;
}
// output

// Enter total elements in arr1:4

//  Enter values in arr1:

//  arr1[0]: 12

//  arr1[1]: 2

//  arr1[2]: 4

//  arr1[3]: 32

// Enter total elements in arr2:1

//  Enter values in arr2:

//  arr2[0]: 2

//  Printing merged sorted array:

//  arr3[0]=2
//  arr3[1]=12
//  arr3[2]=2
//  arr3[3]=4
//  arr3[4]=32