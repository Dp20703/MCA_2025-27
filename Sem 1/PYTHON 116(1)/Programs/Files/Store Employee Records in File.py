# Store Employee Records in File

# Writing employee records
with open("employee.txt", "w") as f:
    for i in range(3):
        name = input("Enter name: ")
        salary = input("Enter salary: ")
        f.write(name + "," + salary + "\n")

# Reading employee records
with open("employee.txt", "r") as f:
    print("Employee Records:")
    for line in f:
        name, salary = line.strip().split(",")
        print("Name:", name, "| Salary:", salary)

