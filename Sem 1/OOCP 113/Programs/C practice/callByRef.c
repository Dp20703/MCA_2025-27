// 2. Call by Reference

// 📌 In Call by Reference, we pass the address of the variable.
// The function can modify the actual variable.

// Example
#include <stdio.h>

// void changeValue(int *x) {
//     *x = 100;  // Change the value at the address
// }

// int main() {
//     int a = 10;

//     printf("Before function call: %d\n", a);
//     changeValue(&a); // Pass address of a
//     printf("After function call: %d\n", a); // Changed

//     return 0;
// }

// Output:

// Before function call: 10
// After function call: 100

// Why?
// &a (address of a) is sent to the function. Inside, *x accesses and changes the actual value in memory.