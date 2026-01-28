# Recursive function

# Recursive function to calculate factorial
def factorial_recursive(n):
    if n == 0 or n == 1:  # Base case
        return 1
    else:
        return n * factorial_recursive(n - 1)  # Recursive call


# Iterative function to calculate factorial
def factorial_iterative(n):
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result


# Test both functions
num = 5
print(f"Factorial of {num} using recursion: {factorial_recursive(num)}")
print(f"Factorial of {num} using iteration: {factorial_iterative(num)}")
