#include <stdio.h>
int main()
{
    int arr[2][2] = {{1, 2}, {3, 4}};
    int i, (*parr)[2]; // pointer the first row of arr
    parr = arr;
    for (i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            // printf(" %d", arr[i][j]);
            printf("%d ", (*(parr + i))[j]);
    }
    return 0;
}

// ✅ Now this line inside the nested loops:
// printf("%d ", (*(parr + i))[j]);

// Let's explain it piece by piece.

// 1. (parr + i)

// parr points to arr[0] (i.e., the first row).

// Adding i means moving to the i-th row.

// So parr + i is a pointer to the i-th row of the array.

// For example:

// When i = 0, it's arr[0].

// When i = 1, it's arr[1].

// 2. *(parr + i)

// This dereferences the pointer, so it's the actual row i.

// So *(parr + i) is equivalent to arr[i], which is an array of 2 integers.

// For example:

// *(parr + 0) → arr[0] → {1, 2}

// *(parr + 1) → arr[1] → {3, 4}

// 3. (*(parr + i))[j]

// This accesses the j-th element of the i-th row.

// So this is equivalent to arr[i][j].

// For example:

// When i=0, j=0: (*(parr + 0))[0] → arr[0][0] → 1

// When i=0, j=1: (*(parr + 0))[1] → arr[0][1] → 2

// When i=1, j=0: (*(parr + 1))[0] → arr[1][0] → 3

// When i=1, j=1: (*(parr + 1))[1] → arr[1][1] → 4

// ✅ Final Conclusion

// This line:
// printf("%d ", (*(parr + i))[j]);

// is just printing each element of the 2D array row by row.

// It’s equivalent to:

// printf("%d ", arr[i][j]);

// The only difference is that here you're using pointer arithmetic (parr + i) and dereferencing it (*(parr + i)) to access the rows, instead of directly using the array name.