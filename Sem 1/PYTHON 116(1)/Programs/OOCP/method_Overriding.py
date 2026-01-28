# Parent class
class Animal:
    def sound(self):
        print("Animal makes a sound")

# Child class overriding the method of the parent
class Dog(Animal):
    def sound(self):   # Method overriding
        print("Dog barks")

# Another child class
class Cat(Animal):
    def sound(self):   # Method overriding
        print("Cat meows")


# Creating objects
a = Animal()
d = Dog()
c = Cat()

# Calling methods
a.sound()   # Calls parent class method
d.sound()   # Calls overridden method in Dog
c.sound()   # Calls overridden method in Cat
