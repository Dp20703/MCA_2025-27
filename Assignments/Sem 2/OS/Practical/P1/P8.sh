# 8. Write a menu driven shell script to find area of rectangle, triangle, and circle

ch=0

while [ $ch -ne 4 ]
do
    echo "---------------------------"
    echo "1 : Area of Rectangle"
    echo "2 : Area of Triangle"
    echo "3 : Area of Circle"
    echo "4 : Exit"
    echo "---------------------------"
    echo -n "Enter your choice: "
    read ch

    case $ch in 
    1)
	echo -n "Enter length:"
	read l
	echo -n "Enter width:"
	read w
	area=$((l * w))
	echo "Area of Rectangle = $area"
	;;
     2)
	echo -n "Enter base:"
	read b 
	echo -n "Enter height:"
	read h
	area=$((b * h / 2))
	echo "Area of Triangle = $area"
	;;
       3)
	echo -n "Enter  radius:"
	read r
	area=$(( 22 * r * r / 7))
	echo "Area of Circle = $area"
	;;
	4)
	echo "Exiting program..."
	;;
	*)
	echo "invalid choice!"
	;;
	esac
done
