# Merge Two Files
# optional to write files
f1=open('file1.txt','w')
f1.write("hello from file 1 \n")
f2=open('file2.txt','w')
f2.write("hello from file 2\n")

with open('file1.txt','r') as f1, open('file2.txt') as f2 , open('file3.txt','w') as f3:
    f3.write(f1.read()+"\n "+ f2.read())

# optional to read file
# with open('file3.txt','r') as f3:
#     print(f3.read())