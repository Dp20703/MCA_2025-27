# P1.py
# boys=int(input("Enter number of boys: "))
# girls=int(input("Enter number of girls: "))

# try:
#     r=boys/girls
#     print(f'ratio of boys to girls is {r}')
# except ZeroDivisionError:
#     print("No girls, Ration not defined")
# total = boys+girls
# print(f'Total number of students {total}')

import sys
# P2.py
try:
    x = int(input('Enter a number : '))
    print(10 / x)
except ValueError:
    print('ValueError exception handled')
    sys.exit()
finally:
    print('Running clean up code')
print('End ……')

