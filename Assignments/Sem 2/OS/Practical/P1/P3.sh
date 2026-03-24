# 3. Write a shell script to generate Fibonacci numbers from 1 to n.

echo -n "Enter the number:"
read n

a=0
b=1

for ((i=1; i<=n; i++))
do 
	echo -n "$b "
	fn=$((a + b))
	a=$b
	b=$fn	
done
echo
