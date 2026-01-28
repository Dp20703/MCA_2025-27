# STRING – 5 Python Programs
# 1) Create a string & print it
name = "Darshan Prajapati"
print(name)
# Output:
# Darshan Prajapati

# 2) Length of string
text = "Hello World"
print("Length =", len(text))
# Output:
# Length = 11

# 3) Count a specific character
msg = "banana"
print(msg.count('a'))
# Output:
# 3

# 4) Reverse a string
s = "python"
rev = s[::-1]
print(rev)
# Output:
# nohtyp

# 5) Check if string is palindrome
s = "madam"
if s == s[::-1]:
    print("Palindrome")
else:
    print("Not Palindrome")

# Output:
# Palindrome