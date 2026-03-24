# 2. Write a menu driven shell script for basic arithmetic operations.

ch=0
while [ $ch -ne 6 ]
do
	echo "1. Addition"
	echo "2. Substraction"
	echo "3. Multiplication"
	echo "4. Division"
	echo "5. Modulus"
	echo "6. Exit"

	echo -n "Enter choice:"
	read ch

	echo -n "Enter no1"
	read  no1
	echo -n "Enter no2"
        read  no2

	if [ $ch -eq  1 ]; then
	 ans=$((no1+no2))
	 echo "Ans:$ans"
	 
	 elif [ $ch -eq 2 ];then
	 ans=$((no1-no2))
	 echo "Ans:$ans"
		 
	 elif [ $ch -eq 3 ];then
         ans=$((no1*no2))
         echo "Ans:$ans"
	 
  	 elif [ $ch -eq 4 ];then
         ans=$((no1/no2))
         echo "Ans:$ans"

    elif [ $ch -eq 5 ];then
         ans=$((no1%no2))
         echo "Ans:$ans"	 

	 elif [ $ch -eq 6 ];then
         echo "Bye bye"
 	 break

	 else
	 echo "Invalid choice "
	 fi
done
