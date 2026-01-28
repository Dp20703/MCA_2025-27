from abc import ABC, abstractmethod

# ---------------------------------------
# Abstract Class
# ---------------------------------------
class Shape(ABC):

    @abstractmethod
    def area(self):
        pass

    @abstractmethod
    def perimeter(self):
        pass


# ---------------------------------------
# Concrete Class 1
# ---------------------------------------
class Rectangle(Shape):
    def __init__(self, length, width):
        self.length = length
        self.width = width

    def area(self):
        return self.length * self.width

    def perimeter(self):
        return 2 * (self.length + self.width)


# ---------------------------------------
# Concrete Class 2
# ---------------------------------------
class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return 3.14 * self.radius * self.radius

    def perimeter(self):
        return 2 * 3.14 * self.radius


# ---------------------------------------
# Usage
# ---------------------------------------
r = Rectangle(10, 5)
c = Circle(7)

print("Rectangle Area:", r.area())
print("Rectangle Perimeter:", r.perimeter())
print()
print("Circle Area:", c.area())
print("Circle Perimeter:", c.perimeter())
