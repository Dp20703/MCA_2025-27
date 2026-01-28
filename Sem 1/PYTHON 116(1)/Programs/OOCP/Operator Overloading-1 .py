class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Overloading the + operator
    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)

    # Overloading the == operator
    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    # For printing the object
    def __str__(self):
        return f"({self.x}, {self.y})"


# ---------------------------------
# Demonstration
# ---------------------------------

p1 = Point(2, 3)
p2 = Point(4, 1)
p3 = Point(2, 3)

print("Point 1:", p1)
print("Point 2:", p2)
print()

# Using overloaded +
result = p1 + p2
print("Addition (p1 + p2):", result)

# Using overloaded ==
print("Is p1 equal to p3?", p1 == p3)
print("Is p1 equal to p2?", p1 == p2)
