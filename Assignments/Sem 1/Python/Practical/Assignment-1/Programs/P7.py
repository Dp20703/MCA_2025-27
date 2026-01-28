# 7) Authentication Ask username, password and compare with encryption

from cryptography.fernet import Fernet
key=Fernet.generate_key()
cipher=Fernet(key)

correct_username='user123'
correct_password='pass123'.encode()
encrypted_password=cipher.encrypt(correct_password)

username=input("Enter your username: ")
password=input("Enter your password: ").encode()

if(username==correct_username and password==cipher.decrypt(encrypted_password)):
    print('Authentication Successful!')
else:
    print('Authentication Failed!')

# output
# Enter your username: user123
# Enter your password: pass123
# Authentication Successful!