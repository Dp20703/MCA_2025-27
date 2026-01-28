countries={
    'IN':'India',
    'GR':'Germary',
    'MX':'Mexico',
    'JP':'Japan'
}
print(countries)
print(' ')
print(countries['IN'])
print(' ')

student={
    'name': 'John',
    'gender':'M',
    'city':'bikaner',
    'age':21,
    'marks':[92,93,83],
    'is_sporty':True
}

print(student)
print(' ')

print(student['name'])
# print(student['address'])
print(student['marks'][0])
print(student['marks'][1])

print('')
print(student.keys())
print('')
print(student.values())
print('')
print(student.items())
print('')
print('Sorted: ',sorted(student.keys()))
# print('Sorted: ',sorted(student.values()))
print('Sorted: ',sorted(student.items()))

print(list(student))
print(tuple(student))
print(set(student))