# 22. Write a script which has the functionality similar to head and tail commands.

echo -n "Enter File name:"
read file

if [ ! -f "$file" ]
then
	echo "File doesnt' exist"
	exit
fi

echo "Display first n lines (head)"
echo "Display last n lines (tail)"
echo -n "Enter your choice"
read ch

echo -n "Enter the lines"
read n

case $ch in 
1)
	count=0
	while read line
	do
		echo "$line"
		count=$((count+1))
		if [ $count -eq  $n ]
		then 		
			break
		fi
	done < "$file"
	;;
2)
	total=$(wc -l < "$file")
	start=$((total - n + 1))
	
	count=0
	while read line
	do
		count=$((count+1))
		if [ $count -ge  $start ]
		then
			echo "$line"	
		fi
	done < "$file"
	;;
*)
echo "Invalid option"
;;
esac
