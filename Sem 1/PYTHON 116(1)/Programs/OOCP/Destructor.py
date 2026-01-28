class Student:
    # Constructor
    def __init__(self, student_id, student_name):
        self.student_id = student_id
        self.student_name = student_name
        print("Constructor called: Student object created.")

    # Method to display details
    def display(self):
        print("Student ID:", self.student_id)
        print("Student Name:", self.student_name)

    # Destructor
    def __del__(self):
        print("Destructor called: Student object destroyed.")


# Creating an object
s1 = Student(101, "Hardik")

# Displaying details
s1.display()

# Deleting the object manually (optional)
del s1
