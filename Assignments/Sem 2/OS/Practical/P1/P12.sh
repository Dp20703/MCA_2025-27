# 12. Write a script to check the string entered by user is palindrome or not

echo -n "Enter the string:"
read str

rev=""

len=${#str}

for ((i=len-1; i>=0; i--))
do
	rev="$rev${str:i:1}"
done

if [ "$str" = "$rev" ]
then
	echo "It is a Palindrome"
else
	echo "Not a Palindrome"
fi
