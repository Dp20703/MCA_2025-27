// 2. Write a program to find the memory address of any element in the array.

#include <stdio.h>

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int idx;

	printf("Enter index to get the memory address: ");
	scanf("%d", &idx);

	if (idx >= 0 && idx < 5)
	{
		printf("Address of arr[%d] = %p\n", idx, (void *)&arr[idx]);
	}
	else
	{
		printf("Invalid index!\n");
	}

	return 0;
}

// output
// Enter index to get the memory address: 1
// Address of arr[1] = 0061FF10
