# Rules for Operator Overloading

## General Rules
1. Operator overloading allows user-defined types to behave like built-in types with respect to operators.
2. Only existing operators can be overloaded; new operators cannot be created.
3. Operator functions can be member functions or non-member functions (usually declared as `friend`).
4. At least one operand must be a user-defined type.
5. Some operators (such as `::`, `.`, `.*`, and `?:`) cannot be overloaded.
6. Overloading should preserve the original meaning of the operator as much as possible.

## Rules for Using Friend Function Overloading
1. Friend functions are used when the left operand is not an object of the class (e.g., `operator<<` for streams).
2. Friend operator functions have access to private and protected members of the class.
3. Friend operator functions are declared with the `friend` keyword inside the class.
4. Friend operator functions are defined outside the class scope.
5. The first parameter of a friend operator function is usually the left operand, and the second is the right operand.
6. Friend functions cannot be called using member function syntax (i.e., `obj.operator+(other)`).

## Operators That Can Be Overloaded Using Friend Functions

- Arithmetic operators: `+`, `-`, `*`, `/`, `%`
- Relational operators: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Assignment operator: `=`
- Bitwise operators: `&`, `|`, `^`, `~`, `<<`, `>>`
- Increment and decrement: `++`, `--`
- Logical operators: `&&`, `||`, `!`
- Stream insertion and extraction: `<<`, `>>`
- Subscript operator: `[]`
- Function call operator: `()`
- Comma operator: `,`
- Pointer-to-member operator: `->*`