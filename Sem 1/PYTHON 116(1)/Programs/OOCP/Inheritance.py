# Parent class
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def display_person(self):
        print("Name:", self.name)
        print("Age:", self.age)

# Child class inheriting from Person
class Student(Person):
    def __init__(self, name, age, rollno):
        super().__init__(name, age)   # Call parent class constructor
        self.rollno = rollno

    def display_student(self):
        self.display_person()  # Calling method from parent class
        print("Roll No:", self.rollno)


# Creating object of Student class
s1 = Student("Darshan", 22, 101)

# Display details
s1.display_student()
