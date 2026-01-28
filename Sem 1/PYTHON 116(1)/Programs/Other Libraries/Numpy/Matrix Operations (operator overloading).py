class Matrix:
    def __init__(self, data):
        self.data = data
        self.rows = len(data)
        self.cols = len(data[0])

    # Display matrix
    def display(self):
        for row in self.data:
            print(row)

    # Matrix addition
    def __add__(self, other):
        result = []
        for i in range(self.rows):
            row = []
            for j in range(self.cols):
                row.append(self.data[i][j] + other.data[i][j])
            result.append(row)
        return Matrix(result)

    # Matrix subtraction
    def __sub__(self, other):
        result = []
        for i in range(self.rows):
            row = []
            for j in range(self.cols):
                row.append(self.data[i][j] - other.data[i][j])
            result.append(row)
        return Matrix(result)

    # Matrix multiplication
    def __mul__(self, other):
        result = []
        for i in range(self.rows):
            row = []
            for j in range(other.cols):
                # Compute dot product
                s = 0
                for k in range(self.cols):
                    s += self.data[i][k] * other.data[k][j]
                row.append(s)
            result.append(row)
        return Matrix(result)

    # Transpose of matrix
    def transpose(self):
        result = []
        for i in range(self.cols):
            row = []
            for j in range(self.rows):
                row.append(self.data[j][i])
            result.append(row)
        return Matrix(result)


# ------------------------------------------------
# Demonstration
# ------------------------------------------------

A = Matrix([[1, 2, 3],
            [4, 5, 6]])

B = Matrix([[7, 8, 9],
            [1, 2, 3]])

print("Matrix A:")
A.display()

print("\nMatrix B:")
B.display()

print("\nA + B:")
(A + B).display()

print("\nA - B:")
(A - B).display()

# For multiplication, create compatible matrices
C = Matrix([[1, 2],
            [3, 4],
            [5, 6]])

print("\nMatrix C:")
C.display()

print("\nA * C:")
(A * C).display()

print("\nTranspose of A:")
A.transpose().display()
