def greet(name="Guest"):
    print(f"Hello, {name}!")


def add(*args):
    total = sum(args)
    print(f"Sum of {args} is {total}")


greet()          # No argument
greet("Hardik")  # With one argument

add(5, 10)           # Two arguments
add(1, 2, 3, 4, 5)   # Multiple arguments
