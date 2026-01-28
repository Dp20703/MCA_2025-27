# syntax:
# [expression for item in iterable]
# cubes=[]
# for i in range(5,11):
#     cubes.append(i**3)

# 1.convert into cube
cubes=[i**3 for i in range(5,11)]
# print(cubes) 

# 2. convert into square
L = [3, 5, 7, 1, 8, 9, 4]
L2=[x**2 for x in L]
# print(L2)
cubes=[x**3 for x in L]
# print(cubes)

# 3. convert list of numbers in string
num=[3, 5, 7, 1, 8, 9, 4]
strings=[str(i) for i in num]
# print(strings)

# 4.
cities = ['Belmont', 'New york', 'Paris',
'Buenos aires']
shortName=[city[:3] for city in cities]
# print(shortName)
titleCase=[city.title() for city in cities]
# print(titleCase)

createTuple=[(city,len(city)) for city in cities]
createList=[[city,len(city)] for city in cities]
# print(createTuple)
# print(createList)

# 5.
L = [[1, 2, 11, 13], [12, 34, 56, 10], [13,
77, 89], [56, 78]]
sumList=[sum(lists) for lists in L]
maxNum=[max(lists) for lists in L]
# print(sumList)
# print(maxNum)


# 6. convert heights from ht to cm
heights = [12, 45, 78, 77, 12, 14, 54]
heights_cm = [ht*2.54 for ht in heights]
# print(heights_cm)

# 7. Convert grams to kilograms
weights = [2900, 3450, 6678, 2348, 800, 8999,
90]
wts=[(wt//1000 ,wt%1000) for wt in weights]
# print(wts)
# weightList=[t[0]*1000+t[1] for t in wts]
weightList=[kg*1000+grams for kg,grams in wts]
# print(weightList)

# 8.
L1 = [1, 2, 3, 4, 5]
L2 = [4, 6, 7, 1, 8]
L3 = [7, 5, 3, 1, 2]
L=[x+y+z for x, y,z in zip(L1,L2,L3)]
# print(L)

# .............with if clause.. 
# [expression for item in iterable if condition]

L = [3, 5, 7, 1, 8, 9, 4]
cubes=[n**3 for n in L if  n%2==0]
# print(cubes)

L = [32, -51, 63, 11, 86, -9, 66, 88, 97]
# print([n*2 for n in L if n>0])

even=[n for n in L if n%2==0]
odd=[n for n in L if n%2!=0]
# print("Even:",even)
# print("Odd: ",odd)

words = ['apple', 'civic', 'board', 'noon',
'moon', 'lamp', 'madam']

palindromes=[word for word in words if word==word[::-1]]
# print("Palindromes:",palindromes)

L = [('Ted', 23), ('Lee', 18), ('Sam', 22),
('Bob', 30), ('Dev', 27), ('Ray', 25)]

newList=[name for name,bmi in L if 20<bmi<26]
# print(newList)    

# print( [method for method in dir(str) if not
# method.startswith('_')])
# print([method for method in dir(str) if
# method.startswith('is')])


# Ternary operator
L= [1, 2, -3, 6, 18, -9, 12, -5, 19, -8, 5]
lists=[n if n%2==0 else 0 for n in L]
# print(lists)

L = [1, 2, -3, 6, 18, -9, 12, -5, 19, -8, 5]
lists=[n if n>0 else 0 for n in L]
# print(lists)

lists=[n//2 if n%2==0 else n*2 for n in L if n>=0]
# print(lists)

# modifying a list
students = ['Era', 'Ted', 'Rob', 'Joe', 'Amy',
'Sam', 'Pat', 'Joy', 'Tia']
failed_students = ['Ted', 'Amy', 'Sam']
students[:]=[ s for s in students if s not in failed_students]

# print(students)



