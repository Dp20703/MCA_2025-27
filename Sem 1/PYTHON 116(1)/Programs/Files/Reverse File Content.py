# Reverse File Content
with open("data.txt", "r") as f:
    content = f.read()
    rev = content[::-1]
    print("Reversed Content:\n", rev)

