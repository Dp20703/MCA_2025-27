class Student:
    _name='Darshan'
    _rollno=24

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


# Using the Student class (no constructor)
s1 = Student()

print("Roll No:", s1.get_rollno())
print("Name:", s1.get_name())

s1.set_rollno(101)
s1.set_name("Dp")

print("Roll No:", s1.get_rollno())
print("Name:", s1.get_name())
