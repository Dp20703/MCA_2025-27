echo "Files with number of links (ascending order):"

ls -l | grep -v '^total' | awk '{print $2, $9}' | sort -n
