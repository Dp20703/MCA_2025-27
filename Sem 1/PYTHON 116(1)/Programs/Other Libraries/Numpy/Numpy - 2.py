import numpy as np

# Creating arrays
a = np.array([1, 2, 3, 4, 5])
b = np.array([10, 20, 30, 40, 50])

print("Array a:", a)
print("Array b:", b)

# Basic arithmetic operations
print("\nAddition:", a + b)
print("Subtraction:", b - a)
print("Multiplication:", a * b)
print("Division:", b / a)

# Array properties
print("\nShape of a:", a.shape)
print("Size of a:", a.size)
print("Data type of a:", a.dtype)

# Reshaping an array
c = np.arange(1, 10)  # 1 to 9
print("\nOriginal c:", c)

c_reshaped = c.reshape(3, 3)
print("Reshaped c (3x3):\n", c_reshaped)

# Statistical operations
print("\nMean of a:", np.mean(a))
print("Median of a:", np.median(a))
print("Standard Deviation of a:", np.std(a))

# Element-wise comparison
print("\nComparison (a > 3):", a[a > 3])

# Matrix operations
m1 = np.array([[1, 2], [3, 4]])
m2 = np.array([[5, 6], [7, 8]])

print("\nMatrix m1:\n", m1)
print("Matrix m2:\n", m2)

print("\nMatrix Addition:\n", m1 + m2)
print("Matrix Multiplication:\n", np.dot(m1, m2))  # or m1 @ m2
