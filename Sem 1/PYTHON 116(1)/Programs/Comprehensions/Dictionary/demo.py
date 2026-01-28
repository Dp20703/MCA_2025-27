# Getting keys from values in dictionary

d = {
'Poems for kids': 'Joe',
'Stories for kids': 'Zen',
'Health is wealth': 'James',
'Rhymes for Babies': 'Joe',
'Stories for teens': 'Ted',
'Be healthy': 'James'
}

book_name=[book_name for book_name, author in d.items()
if author == 'James']
# print(book_name)

employees = {
'Jack': '02-03-1973',
'John': '09-12-1977',
'Mark': '09-11-1972',
'Mary': '08-05-1977',
}
# We need to create a list of all those names who were born in 1977. 

names=[name for name, dob in employees.items() if
dob[-4:] == '1977']
# print(names)    

students ={
'12AB': 
{'name': 'Joe', 'age': 13,
'grade': 'A'
},
'17CD': 
{'name': 'Sam', 'age': 14,
'grade': 'A+'
},
'42CR': 
{'name': 'Ted', 'age': 13,
'grade': 'A+'
},
'13CR': 
{'name': 'Bob', 'age': 13,
'grade': 'B+'
},
'19FD': 
{'name': 'Rob', 'age': 12,
'grade': 'A+'
}
}

# From the students dictionary, we want to create a list of names of all those students who got A+ grade

# aPlusStud=[record['name'] for record in students.values() if record['grade']=='A+']

aPlusStud=[(id,record['name']) for id,record in students.items() if record['grade']=='A+']
# print(aPlusStud)

# Matrix
matrix = [ 
[1, 4, 8, 3],
[2, 5, 6, 3],
[7, 9, 5, 8],
]
mat=[[ele*2 for ele in row] for row in matrix]
# print(mat)

column=[row[1] for row in matrix]
print(column)