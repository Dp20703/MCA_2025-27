from datetime import date, timedelta

class MyDate:
    def __init__(self, year, month, day):
        self.date = date(year, month, day)

    # Overload + operator (add days)
    def __add__(self, days):
        if isinstance(days, int):
            new_date = self.date + timedelta(days=days)
            return MyDate(new_date.year, new_date.month, new_date.day)
        return NotImplemented

    # Overload - operator (subtract days)
    def __sub__(self, days):
        if isinstance(days, int):
            new_date = self.date - timedelta(days=days)
            return MyDate(new_date.year, new_date.month, new_date.day)
        return NotImplemented

    # For printing nicely
    def __str__(self):
        return self.date.strftime("%Y-%m-%d")


# ----------------------------------
# Demonstration
# ----------------------------------
d1 = MyDate(2025, 1, 20)
print("Original Date:", d1)

# Add 10 days
d2 = d1 + 10
print("After Adding 10 Days:", d2)

# Subtract 5 days
d3 = d1 - 5
print("After Subtracting 5 Days:", d3)  
