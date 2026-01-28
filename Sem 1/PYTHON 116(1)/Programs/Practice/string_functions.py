# String Manipulation Examples

text = "  Hello, World! Python is FUN.  "

# 1. Convert to lowercase
print("Lowercase:", text.lower())

# 2. Convert to uppercase
print("Uppercase:", text.upper())

# 3. Remove extra spaces
print("Stripped:", text.strip())

# 4. Replace words
print("Replace:", text.replace("FUN", "Awesome"))

# 5. Split into words
print("Split:", text.split())

# 6. Check if string starts with "Hello"
print("Starts with 'Hello':", text.strip().startswith("Hello"))

# 7. Check if string ends with "FUN."
print("Ends with 'FUN.':", text.strip().endswith("FUN."))

# 8. Find position of substring
print("Find 'Python':", text.find("Python"))

# 9. Count occurrences of a word/letter
print("Count 'o':", text.count("o"))

# 10. Join a list of words into string
words = ["Python", "is", "great"]
print("Join:", " ".join(words))

# 11. Using reversed() and join()
text = "Python"
rev = reversed(text)
print(rev)               # This gives an iterator object
print(list(rev))         # Convert iterator to list
#Alternate way
#reversed_text2 = "".join(reversed(text))
#print("Reversed String:", reversed_text2)