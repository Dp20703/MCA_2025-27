# 17. The script will receive the filename or filename with its full path, the script
# should obtain information about this file as given by "ls -l" and display it in
# proper format.e.g., Filename : , File access permissions : , Number of links : , Owner of the
# file : , Group to which belongs : Size of file : , File modification date : , File
# modification time : .


echo -n "Enter the file name:"
read file


if [ -f "$file" ]
then
	info=$(ls -l $file)
	echo $info

	set -- $info
	
	perm=$1
	links=$2
	owner=$3
	group=$4
	size=$5
	date=$6
	month=$7
	time=$8
	fname=$9

    echo "-------------------------------------"
    echo "Filename                : $fname"
    echo "File access permissions : $perm"
    echo "Number of links         : $links"
    echo "Owner of the file       : $owner"
    echo "Group of the file       : $group"
    echo "Size of file            : $size bytes"
    echo "File modification date  : $date $month"
    echo "File modification time  : $time"
    echo "-------------------------------------"
else
	echo "File doesn't exist"
fi
