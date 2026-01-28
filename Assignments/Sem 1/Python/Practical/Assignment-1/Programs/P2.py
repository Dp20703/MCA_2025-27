# 2) Display time since epoch in hours and minutes

import time

epoch =time.time()

hours=int(epoch//3600)
minutes=int((epoch%3600)//60)

print("Time since epoch")
print(f"Hours: {hours} Minutes: {minutes}")

# output
# Time since epoch
# Hours: 488225 Minutes: 15