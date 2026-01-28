# Writing student data
with open("students.txt", "w") as f:
    n = int(input("Enter number of students: "))
    for i in range(n):
        name = input("Enter name: ")
        marks = input("Enter marks: ")
        f.write(name + " " + marks + "\n")

# Reading student data
with open("students.txt", "r") as f:
    print("\nStudent Records:")
    for line in f:
        name, marks = line.split()
        print("Name:", name, "| Marks:", marks)
