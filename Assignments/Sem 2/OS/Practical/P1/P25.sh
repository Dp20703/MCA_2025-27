# 25. Display the dates falling on Sundays of the current month.


echo "Dates falling on Sundays in the current month:"

cal | awk 'NR>2 {print $1}' | grep -v "^$"

