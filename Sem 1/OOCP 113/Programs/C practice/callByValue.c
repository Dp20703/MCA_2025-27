// 1. Call by Value

// 📌 In Call by Value,
// the function gets a copy of the variable.Changes made inside the function do not affect the original variable.

// Example
#include <stdio.h>

void changeValue(int x)
{
    x = 100; // Only local copy is changed
}

int main()
{
    int a = 10;

    printf("Before function call: %d\n", a);
    changeValue(a);
    printf("After function call: %d\n", a); // No change

    return 0;
}

// Output :
// Before function call : 10
// After function call : 10

//     Why?
// a’s value is copied into x.Changing x does not affect a.