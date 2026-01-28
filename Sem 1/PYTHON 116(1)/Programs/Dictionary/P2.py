# 2) Create a dictionary of students and their marks in 3 subjects, further calculate the total marks and percentage

# Dictionary of students and their marks in 3 subjects
students = {
    "Aman": [75, 80, 70],
    "Pooja": [88, 92, 85],
    "Darshan": [60, 70, 65]
}

# Calculate total and percentage
results = {}

for name, marks in students.items():
    total = sum(marks)
    percentage = total / len(marks)  # since 3 subjects
    results[name] = {"Total": total, "Percentage": percentage}

print("Results:", results)