// The following code implements the solution of the Tower of
// Hanoi problem.

#include <stdio.h>
void move(int, char, char, char);
int main()
{
    int n;
    printf("\n Enter the numbe of rings: ");
    scanf("%d", &n);
    move(n, 'A', 'C', 'B');
}
void move(int n, char source, char dest, char spare)
{
    if (n == 1)
    {
        printf("\n Moved from %c to %c ", source, dest);
    }
    else
    {
        move(n - 1, source, spare, dest);
        move(1, source, dest, spare);
        move(n - 1, spare, dest, source);
    }
}
// output
//  Moved from A to C
//  Moved from A to B
//  Moved from C to B
//  Moved from A to C
//  Moved from B to A
//  Moved from B to C
//  Moved from A to C