# 1) Display the difference in dates

from datetime import datetime


# date1='2025-08-20'
# date2='2025-08-30'

date1=input('Enter first date ( YYYY-MM-DD): ')
date2=input('Enter second date ( YYYY-MM-DD): ')

d1=datetime.strptime(date1,"%Y-%m-%d")
d2=datetime.strptime(date2,"%Y-%m-%d")

difference=abs(d2 - d1) 

print('Difference of dates in days: ',difference.days, ' days')

# output

# Enter first date ( YYYY-MM-DD): 2025-10-01
# Enter second date ( YYYY-MM-DD): 2025-11-01
# Difference of dates in days:  31  days