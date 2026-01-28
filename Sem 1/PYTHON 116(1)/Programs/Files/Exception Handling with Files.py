# Exception Handling with Files
try:
    with open("notfound.txt", "r") as f:
        print(f.read())
except FileNotFoundError:
    print("File not found!")
