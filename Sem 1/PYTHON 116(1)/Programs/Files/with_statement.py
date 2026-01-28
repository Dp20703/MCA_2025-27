# ✅ Best Practice: with Statement

# Instead of manually closing:

with open("example.txt", "r") as f:
    data = f.read()
    print(data)
# File closes automatically here