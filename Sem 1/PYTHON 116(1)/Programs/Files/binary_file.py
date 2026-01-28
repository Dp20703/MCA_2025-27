# Writing binary
with open("binaryfile.bin", "wb") as f:
    f.write(b'010101')

# Reading binary
with open("binaryfile.bin", "rb") as f:
    print(f.read())
