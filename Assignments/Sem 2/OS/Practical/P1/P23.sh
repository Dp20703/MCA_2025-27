# 23. The script displays a list of all files in the current directory to which you have read, write and execute permissions.


echo "Files with read, write and execute permissions:"

for file in *
do
	if [ -f "$file" ] && [ -r "$file" ] && [ -w "$file" ] && [ -x "$file" ]
	then
	echo "$file"
	fi
done
