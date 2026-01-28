fruits = ["apple", "banana", "cherry"]
print(fruits[0])   # apple
print(fruits[-1])  # cherry


numbers = [10, 20, 30]

# Adding elements
numbers.append(40)        # [10, 20, 30, 40]
numbers.insert(1, 15)     # [10, 15, 20, 30, 40]

# Removing elements
numbers.remove(20)        # [10, 15, 30, 40]
last = numbers.pop()      # Removes last element → 40
del numbers[0]            # Removes index 0

# Searching
print(30 in numbers)      # True

# Iterating
for n in numbers:
    print(n)

# List Slicing
nums = [1, 2, 3, 4, 5]
print(nums[1:4])   # [2, 3, 4]
print(nums[:3])    # [1, 2, 3]
print(nums[::2])   # [1, 3, 5]

# List Functions
# | Function    | Example          | Result             |
# | ----------- | ---------------- | ------------------ |
# | `len()`     | `len(nums)`      | Number of elements |
# | `min()`     | `min(nums)`      | Minimum value      |
# | `max()`     | `max(nums)`      | Maximum value      |
# | `sum()`     | `sum(nums)`      | Sum of elements    |
# | `sort()`    | `nums.sort()`    | Ascending order    |
# | `reverse()` | `nums.reverse()` | Reverses list      |
