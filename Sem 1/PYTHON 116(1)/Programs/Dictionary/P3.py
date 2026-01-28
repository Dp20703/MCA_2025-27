# 3) Create a dictionary of names and age, further, list the people who are eligible to get married. Ensure that the age is not negative using assertion

# Dictionary of names and ages
people = {
    "Darshan": 21,
    "Priya": 17,
    "Rahul": 25,
    "Meena": -5  # Example of invalid age
}

eligible = []

for name, age in people.items():
    # Ensure age is not negative
    assert age >= 0, f"Invalid age for {name}: {age}"
    
    # Check eligibility (let's assume 18+ is eligible)
    if age >= 18:
        eligible.append(name)

print("Eligible for Marriage:", eligible)

