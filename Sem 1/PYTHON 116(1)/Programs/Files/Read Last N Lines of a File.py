# Read Last N Lines of a File

# optional to write in file
# with open("dp.txt",'w') as f:
#     f.write("Name: Darshan Prajapati\n")
#     f.write("Age: 22\n")
#     f.write("zender: male\n")
#     f.write("address: bareja\n")
#     f.write("Nationality: Indian\n")
#     f.write("Weight: 69\n")

def tail(filename, n):
    with open(filename, "r") as f:
        lines = f.readlines()
        for line in lines[-n:]:
            print(line, end="")

tail("dp.txt", 3)   # prints last 3 lines

