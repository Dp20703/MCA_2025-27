# 📂 Example: Copying File Content
with open("example.txt", "r") as f1, open("copy.txt", "w") as f2:
    f2.write(f1.read())