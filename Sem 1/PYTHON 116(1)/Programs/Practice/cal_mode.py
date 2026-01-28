def calculate_mode():
    n = int(input("Enter how many numbers you want: "))
    numbers = []
    for i in range(n):
        num = float(input(f"Enter number {i+1}: "))
        numbers.append(num)

    # Find the mode
    mode=max(set(numbers),key=numbers.count)
    return mode

# -------------------
# Main program
# -------------------
result = calculate_mode()
print("The mode of entered numbers is:", result)
