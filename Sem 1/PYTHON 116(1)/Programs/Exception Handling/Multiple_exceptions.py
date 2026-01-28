try:
    a = [1, 2, 3]
    print(a[5])   # IndexError
except ValueError:
    print("Value Error occurred.")
except IndexError:
    print("Index out of range!")
