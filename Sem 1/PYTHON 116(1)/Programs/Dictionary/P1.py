# 1) Create a dictionary of employees and their salary, further write a program to increment salary by 10% and store in separate dictionary

# Dictionary of employees and their salaries
employees = {
    "Darshan": 30000,
    "Raj": 40000,
    "Meera": 50000
}

# New dictionary to store incremented salaries
incremented_salaries = {}

for name, salary in employees.items():
    incremented_salaries[name] = salary + (salary * 0.10)

print("Original Salaries:", employees)
print("Incremented Salaries:", incremented_salaries)

