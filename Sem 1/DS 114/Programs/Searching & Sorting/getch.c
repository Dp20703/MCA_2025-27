// getch() is a function in C/C++ (declared in <conio.h> in Turbo C/old compilers) that is mainly used to get a single character input from the keyboard without waiting for the Enter key and without displaying it on the screen.

// Key points about getch()
// 1.Takes one character input
// => It reads exactly one character from the keyboard.
// => You don’t need to press Enter — as soon as you press a key, it’s read.

// 2. No echo on screen
// The key you press is not shown in the console window.

// 3. Mostly used in old DOS-based programs
// => It’s not part of the C standard library — only in old compilers like Turbo C, Borland C, etc.

// ex.1
// #include <stdio.h>
// #include <conio.h>

// int main()
// {
//     printf("Hello, World!");
//     getch(); // Waits for a key press before closing
//     return 0;
// }

//ex.2
// #include <stdio.h>
// #include <conio.h> // works only in old Turbo C or MS-DOS style compilers

// int main()
// {
//     char ch;
//     printf("Press any key: ");
//     ch = getch(); // waits for a key press, no Enter needed, doesn't display key
//     printf("\nYou pressed: %c\n", ch);
//     return 0;
// }

// 2. getChar()

// Behavior:
// You type a key(e.g., A)
// and press Enter.
// The key you type is shown in the console before the program prints it.
//  getchar() reads that character from the input buffer.

// #include <stdio.h>

// int main() {
//     char ch;
//     printf("Press any key: ");
//     ch = getchar(); // waits until you press Enter
//     printf("You pressed: %c\n", ch);
//     return 0;
// }
