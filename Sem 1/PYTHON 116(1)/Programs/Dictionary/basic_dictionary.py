# Example
student = {"name": "Darshan", "age": 21, "course": "MCA"}
print(student["name"])   # Darshan
print(student.get("age")) # 21

# Adding / Updating / Removing
student["age"] = 22         # Update value
student["city"] = "Ahmedabad"  # Add new key
print(student)

del student["course"]       # Delete key
age = student.pop("age")    # Remove key & return value

# Dictionary Iteration
for key in student.keys():
    print("Key:", key)

for value in student.values():
    print("Value:", value)

for key, value in student.items():
    print(key, ":", value)

# Dictionary Functions
# | Function   | Example            | Result                     |
# | ---------- | ------------------ | -------------------------- |
# | `len()`    | `len(student)`     | Number of key-value pairs  |
# | `keys()`   | `student.keys()`   | All keys                   |
# | `values()` | `student.values()` | All values                 |
# | `items()`  | `student.items()`  | List of (key, value) pairs |
# | `clear()`  | `student.clear()`  | Removes all items          |
