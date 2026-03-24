# 13. Write a script to check given number is prime or not.
echo -n "Enter the number:"
read n

flag=0
for ((i=2; i<=n/2; i++))
do
	if [ $((n % i)) -eq 0 ]
	then
		flag=1
		break
	fi
done	


if [ $n -le 1 ]
then
	echo "Not a Prime number"

elif [ $flag -eq 0 ]
then
	echo "Prime Number "
else
	echo "Not a Prime number"
fi
