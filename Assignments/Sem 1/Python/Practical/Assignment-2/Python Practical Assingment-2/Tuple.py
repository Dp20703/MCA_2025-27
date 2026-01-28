# TUPLE – 5 Python Programs
# 1) Create & display
t = (1, 2, 3, 4)
print(t)
# Output:
# (1, 2, 3, 4)

# 2) Access elements
t = ("A", "B", "C", "D")
print(t[2])
# Output:
# C

# 3) Count occurrences
t = (2, 4, 2, 2, 6)
print(t.count(2))
# Output
# 3

# 4) Convert tuple → list
t = (10, 20, 30)
lst = list(t)
print(lst)
# Output
# [10, 20, 30]

# 5) Find max & min
t = (8, 3, 9, 1)
print(max(t), min(t))
# Output:
# 9 1

# 6) Slice
t = (10,20,30,40,50)
print(t[1:4])
# Output:
# (20, 30, 40)

# 8) Length
t = (5,6,7,8)
print(len(t))
# Output:
# 4

# 9) Check if element exists
t = (1,2,3,4)
print(2 in t)

#Output:
# True

# 10) Find index of value
t = (10,20,30,20)
print(t.index(20))
# Output:
# 1

