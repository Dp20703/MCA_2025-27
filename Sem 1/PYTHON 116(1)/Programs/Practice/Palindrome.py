#Check for Palindrome

#my_string = "Indian is Wonderful"
my_string = "MalayalaM"

#Convert string into characters
char_list = list(my_string)
print("List : ", char_list)
print(len(char_list))
#Create another list to reverse the list
rev = char_list[::-1]
print("Reverse List", rev)

#Check for Palindrome
if char_list == rev:
    print('Yes Palindrome')
else:
    print('Not Plaindrome')