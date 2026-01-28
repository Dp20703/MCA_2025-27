# 6) Authentication Ask username, password and compare

userName=input("Enter your username: ")
password=input("Enter your Password: ")

correct_userName='user123'
correct_password='pass123'

if userName == correct_userName and password == correct_password:
    print("Authentication successful!")
else:
    print("Authentication failed!")

# output
# Enter your username: user123
# Enter your Password: pass123
# Authentication successful!

# or 

# Enter your username: user112
# Enter your Password: pass123
# Authentication failed!
