# Making L global
L = [1,2,3,4,5]

def Function1():
  print(L)

def Function2():
  L = [11,22,33,44,55]
  print(L)

def Function3():
  print(L)

#Calling Functions
Function1()
L = [5,4,3,2,1]
Function2()
L = [5,4,3,2,1]
Function3()