# Constructor Overloading
class Student:
    def __init__(self, *args):
        if len(args) == 0:
            self.rollno = None
            self.name = None
        elif len(args) == 1:
            self.rollno = args[0]
            self.name = "Unknown"
        elif len(args) == 2:
            self.rollno = args[0]
            self.name = args[1]
        else:
            print("Invalid number of arguments!")

    def display(self):
        print("Roll No:", self.rollno)
        print("Name:", self.name)


# Different constructor calls
s1 = Student()
s2 = Student(101)
s3 = Student(102, "Darshan")

print("Student 1:")
s1.display()

print("\nStudent 2:")
s2.display()

print("\nStudent 3:")
s3.display()
