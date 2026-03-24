# 21. Two numbers are entered through the keyboard, find the power, one number raised to another.


echo -n "Enter number 1:"
read n1
echo -n "Enter number 2:"
read n2


power=$((n1 ** n2))

echo "Power of $n1 is $power"
