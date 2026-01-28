# A function that we will pass as argument
def square(x):
    return x * x

def cube(x):
    return x * x * x

# A function that accepts another function as argument
def apply_function(func, value):
    return func(value)   # Calls the function passed as argument

# Test
num = 5
print(f"Square of {num}: {apply_function(square, num)}")
print(f"Cube of {num}: {apply_function(cube, num)}")
