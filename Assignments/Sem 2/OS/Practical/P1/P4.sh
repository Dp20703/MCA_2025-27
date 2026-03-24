# 4. write a shell script to generate prime number from 1 to n, where n any positive integer number by user.

	echo -n "Enter any positive number:"
	read n

	echo "Prime Numbers from 1 to $n  are:"

for ((num=2; num<=n; num++))
do
	flag=0
	for((i=2; i<=num/2; i++))
	do
	    if [ $((num % i))  -eq 0 ];then
		flag=1
	    break
	    fi
	done

    if [ $flag -eq 0 ]
     then
	echo -n "$num "
     fi

done
echo 
