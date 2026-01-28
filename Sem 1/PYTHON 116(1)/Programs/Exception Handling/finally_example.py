try:
    f = open("data.txt")
    # perform file operations
except FileNotFoundError:
    print("File not found.")
finally:
    print("Closing resources...")