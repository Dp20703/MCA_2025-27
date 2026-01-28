// A — Array representation (manual storage)

/* array_tree.c
   Represent a binary tree in an array (heap-style indexing):
   root at index 0, left child = 2*i + 1, right child = 2*i + 2
   We use -1 to indicate empty slot.
*/

#include <stdio.h>
#define MAX 32

// print array
void print_array(int arr[], int n)
{
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
            printf("_, ");
        else
            printf("%d, ", arr[i]);
    }

    printf("]\n");
}

int main()
{
    int arr[MAX];
    for (int i = 0; i < MAX; i++)
        arr[i] = -1;

    /* Example 1: Left-skewed tree
     with values 1->2->3->4
      Use left child repeatedly: indices 0,1,3,7
   */
    arr[0] = 1;
    arr[1] = 2; // left of 1  //2 * i + 1= 2 * 0 + 1 = 1
    arr[3] = 3; // left of 2  //2 * i + 1= 2 * 1 + 1 = 3
    arr[7] = 4; // left of 3  //2 * i + 1= 2 * 3 + 1 = 7
                //             1
                //         2
                //     3
                // 4

    printf("Left-skewed tree (array):\n");
    print_array(arr, 12);

    /* Reset and Example 2: Right-skewed tree
    with values 10->20->30
      indices 0,2,6
   */
    for (int i = 0; i < MAX; i++)
        arr[i] = -1;
    arr[0] = 10;
    arr[2] = 20; // right of 10 // 2 * i + 2= 2 * 0 + 2 = 2
    arr[6] = 30; // right of 20  // 2 * i + 2= 2 * 2 + 2 = 6
    printf("\nRight-skewed tree (array):\n");
    print_array(arr, 12);

    /* Reset and Example 3: Complete binary tree (level order)
       indices: 0..6 filled
    */
    for (int i = 0; i < MAX; i++)
        arr[i] = -1;
    int vals[] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 7; i++)
    {
        arr[i] = vals[i];
    }
    printf("\nComplete binary tree (array):\n");
    print_array(arr, 12);
    return 0;
}