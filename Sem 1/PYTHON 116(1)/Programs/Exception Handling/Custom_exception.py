# Creating a custom exception class
class InvalidAgeError(Exception):
    def __init__(self, message="Voters age must be between 18 and 100"):
        super().__init__(message)

# Function that uses the custom exception
def check_age(age):
    if age < 18 or age > 100:
        raise InvalidAgeError(f"Invalid age of voter: {age}")
    else:
        print(f"Valid age: {age}")

# Main program
try:
    age = int(input("Enter your age: "))
    check_age(age)
except InvalidAgeError as e:
    print("Custom Exception Caught:", e)
except ValueError:
    print("Please enter a valid integer age.")
