# 3) Display your age in years, months and days
from datetime import datetime

# bday='2003-07-03'
bday=input('Enter birth date in formate (YYYY-MM-DD):')
today=datetime.now()

bday_formated=datetime.strptime(bday,'%Y-%m-%d')

diff_day=(today-bday_formated).days


years = diff_day // 365
remaining_days = diff_day % 365
months = remaining_days // 30
days = remaining_days % 30

print(f'Years:{years} months:{months} days:{days}')

# output
# Enter birth date in formate (YYYY-MM-DD):2003-07-20
# Years:22 months:1 days:29