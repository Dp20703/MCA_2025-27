class Student:
    def __init__(self, name, rollno):
        self.name = name
        self.rollno = rollno

    def display(self):
        print("Student Name:", self.name)
        print("Roll No:", self.rollno)


class Course:
    def __init__(self, course_name, student):
        self.course_name = course_name
        self.student = student   # Object of Student class

    def show_course_details(self):
        print("Course Name:", self.course_name)
        print("Enrolled Student:")
        self.student.display()


# Creating objects
s1 = Student("Darshan", 24)
c1 = Course("Python Programming", s1)

# Display details
c1.show_course_details()

