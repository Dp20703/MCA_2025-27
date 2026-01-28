# Tuple of weeks
weeks = ("Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday")

print("Tuple of weeks:", weeks)

# Accessing elements
print("\nAccessing Elements:")
print("First day of the week:", weeks[0])
print("Last day of the week:", weeks[-1])

# Slicing tuple
print("\nSlicing Tuple:")
print("Weekdays (first 5 days):", weeks[0:5])
print("Weekend (last 2 days):", weeks[5:])

# Concatenation
extra_days = ("Holiday", "Funday")
new_tuple = weeks + extra_days
print("\nConcatenation Result:", new_tuple)

# Repetition
repeat_weeks = weeks * 2
print("\nRepetition (Weeks * 2):", repeat_weeks)

# Iteration
print("\nIterating through tuple:")
for day in weeks:
    print(day)

# Membership test
print("\nMembership Test:")
print("Is 'Monday' in weeks?", "Monday" in weeks)
print("Is 'Vacation' in weeks?", "Vacation" in weeks)

# Length of tuple
print("\nLength of tuple:", len(weeks))

# Finding index and count
print("\nIndex and Count:")
print("Index of 'Wednesday':", weeks.index("Wednesday"))
print("Count of 'Sunday':", weeks.count("Sunday"))

# Using min and max
print("\nAlphabetically smallest day:", min(weeks))
print("Alphabetically largest day:", max(weeks))

# Nested tuple example
nested_tuple = (weeks, ("Week1", "Week2", "Week3"))
print("\nNested Tuple:", nested_tuple)
print("Accessing element from nested tuple:", nested_tuple[1][2])

