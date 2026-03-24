# 20. Write a shell script to display the menu driven interface :
# 1) list all files of the current directory 2) print the current directory 3) print the date 
# 4)print the users otherwise display Invalid Option.


echo "1) List all files in current directory"
echo "2) Print current directory"
echo "3) Print date"
echo "4) Print users"
echo "--------------------------------"
echo -n "Enter your choice: "
read  ch


case $ch in 
1)

	echo "Files in  Currrent directory"
	ls 
	;;

2)
	echo "Current directory"
	pwd
	;;

3)
	echo "Current Date:"
	date
	;;

4)
	echo "users"
	who		
	;;

*)
	echo "invalid option"
	;;
esac
