# Count Words in a File
with open("data.txt", "r") as f:
    content = f.read()
    words = content.split()
    print("Total words:", len(words))
