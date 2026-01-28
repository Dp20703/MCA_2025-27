# Method Overloading
  # Method Overloading with Class
class Calculator:
    # A method that behaves differently based on number of arguments
    def add(self, *args):
        if len(args) == 1:
            return args[0]
        elif len(args) == 2:
            return args[0] + args[1]
        elif len(args) == 3:
            return args[0] + args[1] + args[2]
        else:
            return "No matching method for given arguments"


# Using the Calculator class
c = Calculator()

print("Add 1 number:", c.add(10))
print("Add 2 numbers:", c.add(10, 20))
print("Add 3 numbers:", c.add(10, 20, 30))
