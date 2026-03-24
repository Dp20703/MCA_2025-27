# 14. Write a script to display the student marksheet in appropriate format


echo "Enter marks of Subject 1:"
read s1

echo "Enter marks of Subject 2:"
read s2

echo "Enter marks of Subject 3:"
read s3

echo "Enter marks of Subject 4:"
read s4

echo "Enter marks of Subject 5:"
read s5


total=$((s1 + s2 + s3 + s4 + s5))
per=$((total /5))

echo "---------------------------------"
echo "        STUDENT MARKSHEET        "
echo "---------------------------------"
echo "Name : $name"
echo "---------------------------------"
echo "Subject 1 : $s1"
echo "Subject 2 : $s2"
echo "Subject 3 : $s3"
echo "Subject 4 : $s4"
echo "Subject 5 : $s5"
echo "---------------------------------"
echo "Total Marks : $total / 500 "
echo "Percentage  : $per %"
echo "---------------------------------"
