file="file.txt"
i=1
while read line
do
echo "Line No. $i : $line"
words = $line|wc -w
echo "Words are : $words"
i=$((i+1))
done < $file
