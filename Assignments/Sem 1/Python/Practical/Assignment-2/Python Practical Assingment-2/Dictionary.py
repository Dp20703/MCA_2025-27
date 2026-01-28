# 1) Create & display
student = {"name": "Darshan", "age": 21}
print(student)
# Output
# {'name': 'Darshan', 'age': 21}

# 2) Add key-value
student = {"name": "DP"}
student["course"] = "MCA"
print(student)
# Output
# {'name': 'DP', 'course': 'MCA'}

# 3) Remove a key
data = {"a":1, "b":2, "c":3}
data.pop("b")
print(data)
# Output
# {'a': 1, 'c': 3}


# 4) Loop through dictionary
d = {"x":10, "y":20, "z":30}
for k, v in d.items():
    print(k, "=", v)
# Output
# x = 10
# y = 20
# z = 30


# 5) Get only keys / only values
d = {"id":101, "name":"Ram", "marks":85}
print(d.keys())
print(d.values())
# Output
# dict_keys(['id', 'name', 'marks'])
# dict_values([101, 'Ram', 85])