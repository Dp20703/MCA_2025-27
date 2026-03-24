# 6. Write a menu driven shell script for remove, rename, copy and modify a file


ch=0

while [ $ch -ne 5 ]
do
	echo
	echo "1. Remove a file"
	echo "2. Rename a file"
	echo "3. Copy a file"
	echo "4. Modify(Append) a file"
	echo "5. Exit"
	echo -n "Enter your choice:"
	read ch
	
  	case $ch in
	1)
	echo -n "Enter file name to remove: "
	read file
	
	if [ -f $file ]
	then
		rm "$file"
		echo "File removed successfully"
	else
		echo "File does not exist."
	fi
	;;
	
	2)
	echo -n "Enter old file name: "
        read old
	echo -n "Enter new file name: "
	read new
	
        if [ -f $old ]
        then
        	mv "$old" "$new"
        	echo "File renamed successfully"
        else
       		echo "File does not exist."
        fi
        ;;

	3)
	echo -n "Enter source file name: "
        read source
        echo -n "Enter destination file name: "
        read dest
	
	if [ -f $source ]
	then
		cp "$source" "$dest"
		echo "File copied successfully."
	else
		echo "File does not exist"
	fi
	;;	
	
	4)
	
	echo -n "Enter file name to modify: "
            read file

        if [ -f "$file" ]
        then
                echo "Enter text to append:"
                read text
                echo "$text" >> "$file"
                echo "File modified successfully."
         else
                echo "File does not exist."
         fi
            ;;
	
	5)
		echo "Exiting......."
	;;
	
	*)
		echo "Invalid choice"
	;;
        esac

done
