# 11) Authentication Ask username, password and compare with encryption (DESAES algo)

from Crypto.Cipher import DES
from Crypto.Util.Padding import pad

# create key of 8 bytes
key=b'abcdefgh'

# create cipher object 
cipher=DES.new(key,DES.MODE_ECB)

# print('cipher:',cipher)

# correct username and password
correct_username = "user123"
correct_password = "pass123"

encrypted_password=cipher.encrypt(pad(correct_password.encode(),8))
# print("encyrpted pass: ",encrypted_password)
# inputs
username = input("Enter username: ")
password = input("Enter password: ")

# pad is used to make data length mutliple of 8 bytes 
encrypted_inputPass=cipher.encrypt(pad(password.encode(),8))
# print("input pass: ",encrypted_inputPass)

# compare
if username == correct_username and encrypted_inputPass == encrypted_password:
    print("Authentication successful!")
else:
    print("Authentication failed!")


# output
# Enter username: user123
# Enter password: pass123
# Authentication successful!