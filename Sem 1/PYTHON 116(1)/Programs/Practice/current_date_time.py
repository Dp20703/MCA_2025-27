# Import datetime module
from datetime import datetime

# Get current date and time
now = datetime.now()

# Format and display
print("Current Date and Time:", now)
print("Formatted:", now.strftime("%Y-%m-%d %H:%M:%S"))