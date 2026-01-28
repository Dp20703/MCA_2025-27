# 📂 File Pointer (Cursor)
# When you open a file, a cursor (file pointer) is used to track the position.

# Example:
f = open("data.txt", "w")
f.write("1.345 hello\n")
f = open("data.txt", "r")
print(f.read(5))     # Reads first 5 chars
print("Cursor at:", f.tell())
f.seek(0)            # Move cursor back to start
print("Again:", f.read(5))
f.close()