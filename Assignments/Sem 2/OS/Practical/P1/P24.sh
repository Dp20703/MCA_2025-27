# 24. The script receives any number of filenames as arguments. It should check
# whether every argument supplied is a file or directory. If it is a directory, it should be reported.
# If it is a filename then name of the file as well as the number of lines present in it should be reported.


for item in "$@"
do
	if [ -d "$item" ]
	then
		echo "$item is a directory."
	elif [ -f "$item" ]
	then
		lines=$(wc -l < "$item")
		echo "File:$item | Lines: $lines"
	else
		echo "$item is  not a file "
	fi
done

