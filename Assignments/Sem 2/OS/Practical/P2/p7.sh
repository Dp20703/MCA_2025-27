echo "Enter file name:"
read filename

if [ -f "$filename" ]; then
    awk -F ':' '
    {
        print "Record " NR
        print $3 " " $2 " " $1
        print $4
        print $5 " - " $6
        print $7
        print ""
    }' "$filename"
else
    echo "File not found!"
fi
