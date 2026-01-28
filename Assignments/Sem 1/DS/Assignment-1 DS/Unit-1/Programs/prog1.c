// 1. Write a program to perform linear search and binary search and report the number of
// 	comparisons in both the cases.

#include <stdio.h>
int linearSearch(int arr[], int n, int target, int *comp);
int binarySearch(int arr[], int n, int target, int *comp);
int main()
{
	int arr[] = {2, 4, 8, 13, 15, 19, 20, 24, 28};
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 19;
	int linComp = 0, binComp = 0;
	int linIndex = linearSearch(arr, n, target, &linComp);
	printf("Linear Search: Index = %d, Comparisons = %d\n", linIndex, linComp);

	int binIndex = binarySearch(arr, n, target, &binComp);
	printf("Binary Search: Index = %d, Comparisons = %d\n", binIndex, binComp);

	return 0;
}
int linearSearch(int arr[], int n, int target, int *comp)
{
	int i;
	for (i = 0; i < n; i++)
	{
		(*comp)++;
		if (arr[i] == target)
		{
			return i;
		}
	}
	return -1;
}
int binarySearch(int arr[], int n, int target, int *comp)
{
	int low = 0, high = n - 1;
	while (low <= high)
	{
		(*comp)++;
		int mid = (low + high) / 2;
		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] < target)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}
// output 
// Linear Search: Index = 5, Comparisons = 6
// Binary Search: Index = 5, Comparisons = 3