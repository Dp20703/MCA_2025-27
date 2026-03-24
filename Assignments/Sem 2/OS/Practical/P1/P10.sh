# 10. Write a menu driven shell script for storing employee information (like add,
# modify, delete, display info).


ch=0
file="emp.txt"

while [ $ch -ne 5 ]
do
    echo "-----------------------------"
    echo "1 : Add Employee"
    echo "2 : Modify Employee"
    echo "3 : Delete Employee"
    echo "4 : Display Employees"
    echo "5 : Exit"
    echo "-----------------------------"
    echo -n "Enter your choice: "

    read ch
    case $ch in 
	1)
	echo -n "Enter Employee id:"
	read id
	echo -n "Enter Employee name:"
	read name
	echo -n "Enter Emplyee Salary:"
	read salary
	echo "$id | $name | $salary ">> $file
	echo "Employee added Succesfully!"
	;;
	2)
	echo -n "Enter Employee ID to modify: "
            read id
	if grep -q "$id" $file
	then
		grep -v "$id" $file > text.txt
		mv  text.txt $file
		echo "Enter new  details"
		echo -n "Name: "
        read name
        echo -n "Salary: "
        read salary
		
		echo "$id | $name | $salary" >> $file
                echo "Employee record modified."
	else 
		echo "Employee doesn't exist"
	fi
	;;
	3)
		echo -n "Enter  Employee Id to delete:"
		read id

		if grep -q "$id" $file
		then
			grep -v "$id" $file > text.txt
			mv text.txt $file
			echo "Employee deleted successfully."
		else
			echo "Employee not found!"
		fi
		;;
	4)
	if [ -f $file ]
	then
	 	cat $file
	else
		echo "File not exist"
	fi
	;;
	5)
	echo "Exiting..."
	;;
	*)
	echo "Invalid option"
	;;
	esac	
done 
