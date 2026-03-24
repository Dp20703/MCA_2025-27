# 11. Write a script to print content of the file if file exits otherwise print appropriate message.


echo -n "Enter file name:"
read file


if [ -f "$file" ];then

echo "File contents"
cat $file

else
	echo "file not found"
fi


