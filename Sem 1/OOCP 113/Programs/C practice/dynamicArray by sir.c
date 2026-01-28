#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n,i;
    int new_size;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("You entered: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
	    
	printf("Enter new size: ");
	scanf("%d", &new_size);

	arr = (int*) realloc(arr, new_size * sizeof(int));
	
	if (arr == NULL) {
	    printf("Memory reallocation failed!\n");
	    return 1;
	}

	for (i = n; i < new_size; i++) {
	    printf("Enter element %d: ", i+1);
	    scanf("%d", &arr[i]);
	}

	printf("Updated array: ");
	for (i = 0; i < new_size; i++) {
	    printf("%d ", arr[i]);
	}

    free(arr);
    return 0;
}

