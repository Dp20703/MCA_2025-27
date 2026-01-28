// 18. In a small company there are five salesmen. Each salesman is supposed to sell three products.
// Write a program using a 2D array to print
// (i) the total sales by each salesman
// and (ii) total sales of each item.
#include <stdio.h>
int main()
{
    int sales[5][3], i, j, total_sales = 0;

    // Input data
    printf("\nEnter sales data:\n");
    for (i = 0; i < 5; i++)
    {
        printf("\nSalesman %d:\n", i + 1);
        for (j = 0; j < 3; j++)
        {
            printf("  Product %d: ", j + 1);
            scanf("%d", &sales[i][j]);
        }
    }

    // (i) Total sales by each salesman
    printf("\n--- Total Sales by Each Salesman ---\n");
    for (i = 0; i < 5; i++)
    {
        total_sales = 0;
        for (j = 0; j < 3; j++)
        {
            total_sales += sales[i][j];
        }
        printf("Salesman %d = %d\n", i + 1, total_sales);
    }

    // (ii) Total sales of each product
    printf("\n--- Total Sales of Each Product ---\n");
    for (j = 0; j < 3; j++) // products
    {
        total_sales = 0;
        for (i = 0; i < 5; i++) // salesmen
        {
            total_sales += sales[i][j];
        }
        printf("Product %d = %d\n", j + 1, total_sales);
    }

    return 0;
}
