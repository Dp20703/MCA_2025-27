# 9. Write a script to print message like good morning, good afternoon, ….etc
# according to the current time.

hour=$(date +%H)

if [ $hour -gt 5 ] && [ $hour -lt 12 ]
then
	echo "Good morning"
elif [ $hour -gt 12 ] && [ $hour -lt 17 ]
then
echo "Good Afternoon"

elif [ $hour -gt 17 ] && [ $hour -lt 21 ] 
then
echo "Good Evening"

else
	echo "Good night " 
fi
