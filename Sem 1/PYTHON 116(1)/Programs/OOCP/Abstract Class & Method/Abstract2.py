from abc import ABC, abstractmethod

# ---------------------------------------
# Interface (Pure Abstract Class)
# ---------------------------------------
class Animal(ABC):

    @abstractmethod
    def speak(self):
        pass

    @abstractmethod
    def move(self):
        pass


# ---------------------------------------
# Concrete Class 1
# ---------------------------------------
class Dog(Animal):
    def speak(self):
        return "Bark!"

    def move(self):
        return "Dog runs on 4 legs."


# ---------------------------------------
# Concrete Class 2
# ---------------------------------------
class Bird(Animal):
    def speak(self):
        return "Chirp!"

    def move(self):
        return "Bird flies using wings."


# ---------------------------------------
# Demonstration
# ---------------------------------------
a1 = Dog()
a2 = Bird()

print("Dog says:", a1.speak())
print("Dog moves:", a1.move())
print()
print("Bird says:", a2.speak())
print("Bird moves:", a2.move())
