import array

# ==========================
# Create an array
# ==========================
arr = array.array('i', [10, 20, 30, 40, 50])
print("Initial Array:", arr)

# ==========================
# 1. Access elements
# ==========================
print("\nAccessing elements:")
print("First element:", arr[0])
print("Second element:", arr[1])
print("Last element:", arr[-1])

# ==========================
# 2. Append element
# ==========================
arr.append(60)
print("\nAfter append(60):", arr)

# ==========================
# 3. Insert element at index
# ==========================
arr.insert(2, 25)   # insert 25 at index 2
print("After insert(25) at index 2:", arr)

# ==========================
# 4. Extend with another array
# ==========================
arr2 = array.array('i', [70, 80, 90])
arr.extend(arr2)
print("After extend([70, 80, 90]):", arr)

# ==========================
# 5. Remove an element
# ==========================
arr.remove(40)   # removes first occurrence of 40
print("After remove(40):", arr)

# ==========================
# 6. Pop element
# ==========================
popped = arr.pop()   # removes last element
print("After pop():", arr)
print("Popped element:", popped)

# ==========================
# 7. Index of an element
# ==========================
index_val = arr.index(30)
print("\nIndex of 30:", index_val)

# ==========================
# 8. Reverse the array
# ==========================
arr.reverse()
print("After reverse():", arr)

# ==========================
# 9. Count occurrences
# ==========================
arr.append(20)
arr.append(20)
print("Array after adding extra 20s:", arr)
print("Count of 20:", arr.count(20))

# ==========================
# 10. Slice array
# ==========================
print("\nSliced array arr[1:4]:", arr[1:4])

# ==========================
# 11. Convert array to list
# ==========================
list_version = arr.tolist()
print("Converted to list:", list_version)

# ==========================
# 12. Buffer info (memory address, length)
# ==========================
print("\nBuffer info:", arr.buffer_info())

# ==========================
# 13. Typecode of array
# ==========================
print("Typecode of array:", arr.typecode)

# ==========================
# 14. Iteration
# ==========================
print("\nIterating through array:")
for num in arr:
    print(num, end=" ")
print()
