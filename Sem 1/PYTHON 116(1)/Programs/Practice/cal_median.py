def calculate_median():
    # Ask how many numbers the user wants to enter
    n = int(input("Enter how many numbers you want: "))

    numbers = []
    for i in range(n):
        num = float(input(f"Enter number {i+1}: "))
        numbers.append(num)

    # Sort the list
    numbers.sort()
    print("Sorted numbers:", numbers)

    # Calculate median
    if n % 2 == 1:  # odd count
        median = numbers[n // 2]
    else:           # even count
        mid1 = numbers[n // 2 - 1]
        mid2 = numbers[n // 2]
        median = (mid1 + mid2) / 2

    return median


# -------------------
# Main program
# -------------------
result = calculate_median()
print("The median of entered numbers is:", result)
