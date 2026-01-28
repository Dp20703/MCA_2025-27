# 8) Authentication Ask username, password and compare with hashing

import hashlib

# correct username and password [ hashed ]
correct_username='user123'
correct_password=hashlib.sha256('pass123'.encode()).hexdigest()

# user inputs
username=input("Enter Username: ")
password=input("Enter Password: ")

# hash the input password
password_hash=hashlib.shake_256(password.encode()).hexdigest()

if(username==correct_username and password_hash==correct_password):
    print('Authentication Successful!')
else:
    print('Authentication Failed!')


# output
# Enter your username: user123
# Enter your password: pass123
# Authentication Successful!