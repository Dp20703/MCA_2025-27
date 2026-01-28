# LIST - Programs
# 1) Create a list & display elements
nums = [10, 20, 30, 40]
print("List:", nums)


# 2) Add element into a list
fruits = ["apple", "banana"]
fruits.append("orange")
print(fruits)

# 3) Remove an element
colors = ["red", "blue", "green"]
colors.remove("blue")
print(colors)

# 4) Sort a list
marks = [45, 12, 90, 33]
marks.sort()
print(marks)

# 5) Sum of all list elements
nums = [3, 5, 7, 9]
print("Sum =", sum(nums))

# 6) Insert at index
a = [1, 2, 4]
a.insert(2, 3)
print(a)
# Output
# [1, 2, 3, 4]

# 7) Pop last element
a = [5,6,7,8]
a.pop()
print(a)
# Output:
# [5, 6, 7]


# 8) Reverse list
a = [1,2,3,4,5]
a.reverse()
print(a)
# Output:
# [5, 4, 3, 2, 1]

# 9) Find max/min
a = [11,3,9,25]
print(max(a), min(a))
# Output
# 25 3

# 10) Loop through list
a = ["ram","shyam","rita"]
for i in a:
    print(i)
# Output:
# ram
# shyam
# rita
