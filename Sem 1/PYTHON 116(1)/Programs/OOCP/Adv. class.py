class Student:
    def __init__(self, rollno, name):
        self._rollno = rollno      # Using _variable to indicate "protected"
        self._name = name

    # Getter for rollno
    def get_rollno(self):
        return self._rollno

    # Setter for rollno
    def set_rollno(self, rollno):
        self._rollno = rollno

    # Getter for name
    def get_name(self):
        return self._name

    # Setter for name
    def set_name(self, name):
        self._name = name


# Using the Student class
s1 = Student(101, "Dp")

print("Roll No:", s1.get_rollno())
print("Name:", s1.get_name())

# Updating values using setters
s1.set_rollno(102)
s1.set_name("Darshan")

print("\nAfter Updating:")
print("Roll No:", s1.get_rollno())
print("Name:", s1.get_name())
