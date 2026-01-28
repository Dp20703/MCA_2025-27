import numpy as np

# ------------------------------------------------
# Create two matrices
# ------------------------------------------------
A = np.array([[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]])

B = np.array([[9, 8, 7],
              [6, 5, 4],
              [3, 2, 1]])

print("Matrix A:\n", A)
print("\nMatrix B:\n", B)

# ------------------------------------------------
# Matrix Addition
# ------------------------------------------------
add = A + B
print("\nAddition (A + B):\n", add)

# ------------------------------------------------
# Matrix Subtraction
# ------------------------------------------------
sub = A - B
print("\nSubtraction (A - B):\n", sub)

# ------------------------------------------------
# Matrix Multiplication
# ------------------------------------------------
mul = np.dot(A, B)
print("\nMultiplication (A × B):\n", mul)

# ------------------------------------------------
# Minimum and Maximum of Entire Matrix
# ------------------------------------------------
print("\nMinimum element in A:", np.min(A))
print("Maximum element in A:", np.max(A))

# ------------------------------------------------
# Diagonal Elements
# ------------------------------------------------
diag = np.diag(A)
print("\nDiagonal elements of A:", diag)

# ------------------------------------------------
# Transpose of Matrix
# ------------------------------------------------
transpose = A.T
print("\nTranspose of A:\n", transpose)

# ------------------------------------------------
# Row-wise Minimum and Maximum
# ------------------------------------------------
print("\nRow-wise Minimum of A:", np.min(A, axis=1))
print("Row-wise Maximum of A:", np.max(A, axis=1))

# ------------------------------------------------
# Column-wise Minimum and Maximum
# ------------------------------------------------
print("\nColumn-wise Minimum of A:", np.min(A, axis=0))
print("Column-wise Maximum of A:", np.max(A, axis=0))
