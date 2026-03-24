# 19. The script receives two file names as arguments, the script must check
# whether the files are same or not, if they are similar then delete the second file.


f1=$1
f2=$2

if [ ! -f "$f1" ] || [ ! -f "$f2" ];then
	echo "One or Both files do not exist"
	exit
fi
cmp -s "$f1" "$f2"

if [ $? -eq 0 ];then
	echo "Files are identical."
	rm "$f2"
else
	echo "Files are different"
fi
