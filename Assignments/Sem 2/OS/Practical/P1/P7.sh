# 7. Write a script to reverse a six-digit number

echo -n "Enter the number " 
read n

rev=0
while [ $n -gt 0 ]
do
	rem=$((n % 10))
	rev=$((rev * 10 + rem))
	n=$((n / 10))
done
echo "Reverse number is  ${rev}"
