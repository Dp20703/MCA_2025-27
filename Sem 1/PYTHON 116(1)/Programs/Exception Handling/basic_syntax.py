try:
    # Code that might cause an error
    x = int(input("Enter a number: "))
    y = 10 / x
except ZeroDivisionError:
    # Runs if division by zero happens
    print("You can’t divide by zero!")
except ValueError:
    # Runs if input is not an integer
    print("Invalid input! Please enter a number.")
else:
    # Runs only if no exception occurs
    print("Division successful! Result:", y)
finally:
    # Runs no matter what
    print("Program ended.")
