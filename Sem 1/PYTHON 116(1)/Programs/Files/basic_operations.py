# 📘 Basic File Operations
# 1. Open a File
# f = open("example.txt", "w")  # opens file in write mode

# 2. Write to a File
f = open("example.txt", "w")
f.write("Hello, Python!\n")
f.write("This is file handling.")
f.close()

# 3. Read a File
# f = open("example.txt", "r")
# content = f.read()  # reads entire file
# print(content)
# f.close()


# Other ways:

# f.readline()   # read one line
# f.readlines()  # read all lines into a list

# 4. Append to a File
# f = open("example.txt", "a")
# f.write("\nAppending a new line.")
# f.close()

# 5. Close a File
# f.close()
# Always close files to free system resources./

