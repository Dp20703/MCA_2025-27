# Count Lines, Words, and Characters

# f=open("data.txt",'w')
# f.write("1.hello world\n")
# f.write("2.hello world\n")
# f.write("3.hello world")

# f=open('data.txt','r')
# text=f.read()
# lines=text.split("\n")
# words=text.split()
# print("Characters: ",len(text))
# print("Lines: ",len(lines))
# print("Words : ",len(words))

# using with
with open("data.txt", "r") as f:
    text = f.read()
    lines = text.split("\n")
    words = text.split()
    print("Lines:", len(lines))
    print("Words:", len(words))
    print("Characters:", len(text))
