// 23. Write a program to enter a number and break it into n number of digits.

#include <stdio.h>

int main()
{
    int num, temp, digits[20], count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    // Extract digits from last to first
    while (temp > 0)
    {
        digits[count] = temp % 10; // store last digit
        temp = temp / 10;          // remove last digit
        count++;
    }

    printf("\nDigits of %d are: ", num);
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%d ", digits[i]); // print in correct order
    }

    printf("\nTotal number of digits: %d\n", count);

    return 0;
}
// output
//  Enter a number: 123

// Digits of 123 are: 1 2 3
// Total number of digits: 3