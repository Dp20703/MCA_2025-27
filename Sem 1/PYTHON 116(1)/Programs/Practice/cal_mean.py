def calculate_mean():
    n = int(input("Enter how many numbers you want: "))

    numbers = []
    total = 0 
    for i in range(n):
        num = float(input(f"Enter number {i+1}: "))
        numbers.append(num)
        total += num
    
    return total / n

# -------------------
# Main program
# -------------------
result = calculate_mean()
print("The mean of entered numbers is:", result)
