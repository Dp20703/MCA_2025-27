# Exercise 1: Perform basic dictionary operations

# Perform following operations on given dictionary
# 1. Add New Key-Value Pair: Add a new key-value pair, 'profession': 'Doctor', to the dictionary and print the updated dictionary.
# 2.Modify Value: Change the value of the age key to 40 in the dictionary and print the updated dictionary.
# 3.Access Key: Print the value associated with the city key

# my_dict = {'name': 'Alice', 'age': 35, 'city': 'New York'}

# print(f"Original dictionary: {my_dict}")

# # Add a new key-value pair
# my_dict['profession'] = 'Doctor'
# print(f"Updated dictionary after adding 'profession': {my_dict}")

# # Modify Value
# my_dict['age'] = 40
# # my_dict.update({'age':45})
# print(f"Updated dictionary after modification: {my_dict}")

# # print key
# print('City:', my_dict['city'])


# Exercise 2: Perform dictionary operations
# Given:

# my_dict = {'name': 'Alice', 'age': 35, 'city': 'New York', 'profession': 'Doctor'}

# # 1.Remove Key-Value Pair : Remove the profession key-value pair from the dictionary.
# # 2.Get Items (Key-Value Pairs): Print all key-value pairs (items) in the dictionary.
# # 3.Check if Key Exists in the dictionary

# print(f"Original dictionary: {my_dict}")

# # Remove the 'model' key-value pair using del
# del my_dict['profession']
# print(f"Updated dictionary after removing 'profession': {my_dict}")

# print("Printing all key-value pairs:")
# for key, value in my_dict.items():
#   print(f"{key}: {value}")
  
# def check_key_exists(dictionary, key_to_check):
#   return key_to_check in dictionary

# key1 = 'age'
# print(f"Does '{key1}' exist? {check_key_exists(my_dict, key1)}")

# Exercise 3: Dictionary from Lists

# Solution 1: The zip() function and a dict() constructor

# Use the zip(keys, values) to aggregate two lists.
# Wrap the result of a zip() function into a dict() constructor.
# keys = ['Ten', 'Twenty', 'Thirty']
# values = [10, 20, 30]

# res_dict = dict(zip(keys, values))
# print(res_dict)

# # Solution 2: Using a loop and update() method of a dictionary

# keys = ['Ten', 'Twenty', 'Thirty']
# values = [10, 20, 30]

# # empty dictionary
# res_dict = dict()

# for i in range(len(keys)):
#     res_dict.update({keys[i]: values[i]})
# print(res_dict).

# Exercise 4: Clear Dictionary

# my_dict = {'name': 'Alice', 'age': 35, 'city': 'New York'}
# print(f"dictionary: {my_dict}")

# my_dict.clear()
# print(f"dictionary after removing all items: {my_dict}")

# Exercise 5: Merge two Python dictionaries into one

# dict1 = {'Ten': 10, 'Twenty': 20, 'Thirty': 30}
# dict2 = {'Thirty': 30, 'Fourty': 40, 'Fifty': 50}

# dict3=dict1.copy()
# dict3.update(dict2)
# print(dict3)

# dict4={**dict1,**dict2}
# print(dict4)

# Exercise 6: Count Character Frequencies
# Given a string, create a dictionary where keys are characters and values are their frequencies in the string.

# Given:
# string1 = 'Jessa'

# Expected Output:
# Frequencies for 'Jessa': {'J': 1, 'e': 1, 's': 2, 'a': 1}

# def count_char_frequencies(input_string):
#   frequency_dict = {}
#   for char in input_string:
#     # Use get() method: if char is in dict, get its value; otherwise, default to 0
#     frequency_dict[char] = frequency_dict.get(char, 0) + 1
#   return frequency_dict

# string1 = 'Jessa'
# print(f"Frequencies for '{string1}': {count_char_frequencies(string1)}")

# Exercise 7: Access Nested Dictionary
# data = {'person': {'name': 'Alice', 'age': 30}}

# print(f'Age of {data['person']['name']} is: {data["person"]['age']}')

# Exercise 8: Print the value of key ‘history’ from nested dict
# sampleDict = {
#     "class": {
#         "student": {
#             "name": "Mike",
#             "marks": {
#                 "physics": 70,
#                 "history": 80
#             }
#         }
#     }
# }

# print(sampleDict["class"]['student']['marks']['history'])

# Exercise 9: Modify Nested Dictionary
# In the below dictionary, change name to ‘Jessa’.

nested_student_dict = {
    "class": {
        "student": {
            "name": "Mike",
            "marks": {
                "physics": 70,
                "history": 80
            }
        }
    }
}

# print(f"Nested dictionary: {nested_student_dict}")
# nested_student_dict['class']['student']['name'] = 'Jessa'

# print(f"Dict after modification: {nested_student_dict}")    

# -----------------------------Exercise 10: Initialize dictionary with default values---------------
# In Python, we can initialize the keys with the same values.

# Given:

# employees = ['Kelly', 'Emma']
# defaults = {"designation": 'Developer', "salary": 8000}

# res=dict.fromkeys(employees,defaults)
# print(res)
# print('')
# print(res['Kelly'])


# Exercise 11: Create a dictionary by extracting the keys from a given dictionary
# Write a Python program to create a new dictionary by extracting the mentioned keys from the below dictionary.

# Given dictionary:

# sample_dict = {
#     "name": "Kelly",
#     "age": 25,
#     "salary": 8000,
#     "city": "New york"}

# # Keys to extract
# keys = ["name", "salary"]

# newDict = {k: sample_dict[k] for k in keys}
# print(newDict)

# ------------------------Exercise 12: Delete a list of keys from a dictionary--------------
# sample_dict = {
#     "name": "Kelly",
#     "age": 25,
#     "salary": 8000,
#     "city": "New york"
# }

# # Keys to remove
# keys = ["name", "salary"]

# for k in keys:
#     sample_dict.pop(k)
#     # del sample_dict[k]
# print(sample_dict)

# Exercise 13: Check if a value exists in a dictionary
# Write a Python program to check if the value 200 is present in the provided dictionary.
# sample_dict = {'a': 100, 'b': 200, 'c': 300}

# if 200 in sample_dict.values():
#         print('exist')

# Exercise 14: Rename key of a dictionary
# Write a program to rename a key city to a location in the following dictionary.

# sample_dict = {
#   "name": "Kelly",
#   "age":25,
#   "salary": 8000,
#   "city": "New york"
# }

# sample_dict['address']=sample_dict.pop('city')
# print(sample_dict)

# Exercise 15: Get the key of a minimum value
# Write a code to print the key of a minimum value from the following dictionary.

# sample_dict = {
#   'Physics': 82,
#   'Math': 65,
#   'history': 75
# }
# print(min(sample_dict,key=sample_dict.get))

# Exercise 16: Change value of a key in a nested dictionary
# Write a Python program to change Brad’s salary to 8500 in the following dictionary.

# sample_dict = {
#     'emp1': {'name': 'Jhon', 'salary': 7500},
#     'emp2': {'name': 'Emma', 'salary': 8000},
#     'emp3': {'name': 'Brad', 'salary': 500}
# }

# sample_dict['emp3']['salary']=8500
# print(sample_dict)

#-------------------------------- Exercise 17: Invert Dictionary
# Write a code to swap keys and values in a dictionary. Assume all values are unique

# Given:

# original_dict1 = {'a': 1, 'b': 2, 'c': 3}
# def invert_dictionary(input_dict):
#   inverted_dict = {}
#   # iterates through each key-value pair in the input_dict
#   for key, value in input_dict.items():
#     inverted_dict[value] = key
#   return inverted_dict

# original_dict1 = {'a': 1, 'b': 2, 'c': 3}

# print(f"Original dictionary 1: {original_dict1}")
# print(f"Inverted dictionary 1: {invert_dictionary(original_dict1)}")

# Exercise 18: Sort Dictionary by Keys
# Sort a dictionary by its keys and print the sorted dictionary (as an OrderedDict or by converting to a list of tuples).

# Given:
from collections import OrderedDict

# my_dict = {'apple': 3, 'zebra': 1, 'banana': 2, 'cat': 4}
# sorteddict=OrderedDict(sorted(my_dict.items()))
# print(sorteddict)
# sorteddict=(sorted(my_dict.items()))
# print(sorteddict) 

# Exercise 19: Sort Dictionary by Values

# from collections import OrderedDict

# my_dict = {'Jessa': 3, 'Kelly': 1, 'Jon': 2, 'Kerry': 4, 'Joy': 1}
# print(f"Original dictionary: {my_dict}")

# # Method 1: Create an OrderedDict sorted by values
# print("\nSorted by values (as OrderedDict):")
# sorted_by_value_ordered_dict = OrderedDict(my_dict)
# print(sorted_by_value_ordered_dict)

# # Method 2: Convert to a list of (key, value) tuples, sorted by value
# print("\nSorted by values (as list of tuples):")
# print(my_dict)

# Exercise 20: Check if All Values are Unique


# def are_all_values_unique(input_dict):
#   # Get all values from the dictionary
#   all_values = list(input_dict.values())

#   # Convert the list of values to a set to get only unique values
#   unique_values_set = set(all_values)

#   # If the length of the original values list is equal to the length of the unique values set,
#   # it means all values were unique.
#   return len(all_values) == len(unique_values_set)

# # Test cases
# dict1 = {'a': 1, 'b': 2, 'c': 3}             # All values unique
# dict2 = {'x': 10, 'y': 20, 'z': 10}          # Value 10 is duplicated
# dict3 = {} # Empty dictionary (all values are vacuously unique)

# print(f"Dictionary: {dict1} -> All values unique? {are_all_values_unique(dict1)}")
# print(f"Dictionary: {dict2} -> All values unique? {are_all_values_unique(dict2)}")
# print(f"Dictionary: {dict3} -> All values unique? {are_all_values_unique(dict3)}")
        

# exercises....
# ....Link......
# https://pynative.com/python-dictionary-exercise-with-solutions/