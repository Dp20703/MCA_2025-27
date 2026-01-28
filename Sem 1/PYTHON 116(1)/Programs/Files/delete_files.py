import os

# check if file exists before deleting
if os.path.exists("data.txt"):
    os.remove("data.txt")
    print("File deleted successfully!")
else:
    print("File does not exist")
