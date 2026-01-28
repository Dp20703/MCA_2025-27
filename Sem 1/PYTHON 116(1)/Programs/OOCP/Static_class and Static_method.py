class Student:
    # -----------------------------
    # Static (Class) Variable
    # -----------------------------
    school_name = "ABC International School"

    def __init__(self, name, rollno):
        self.name = name
        self.rollno = rollno

    # -----------------------------
    # Static Method
    # -----------------------------
    @staticmethod
    def welcome_message():
        print("Welcome to the Student Portal!")
        print("This is a static method - no need for object.")

    # -----------------------------
    # Instance Method
    # -----------------------------
    def show_details(self):
        print(f"Name: {self.name}")
        print(f"Roll No: {self.rollno}")
        print(f"School: {Student.school_name}")  # access static variable


# --------------------------------------
# Testing the class
# --------------------------------------

# Access static variable using class
print("School Name:", Student.school_name)

# Call static method using class
Student.welcome_message()

# Create objects
s1 = Student("Darshan", 101)
s2 = Student("Dp", 102)

# Show details
s1.show_details()
s2.show_details()

# Modify static variable (affects all objects)
Student.school_name = "XYZ Public School"

print("\nAfter Changing Static Variable:")
s1.show_details()
s2.show_details()
