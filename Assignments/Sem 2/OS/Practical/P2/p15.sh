file='student.dat'

awk -F '-' '
BEGIN {
	male = female = 0
	pass = fail = 0
	print "Student Summary "
	print "--------------------"
}
{
	total = $4 + $5 + $6
	percent = total/3
	
	print "Student:",$2
	print "Total marks:",total
	printf "Percentage:%.2f\n",percent

	if($3 == "M")
		male++
	else if ($3 == "F")
		female++
	
	 if ($4 >= 40 && $5 >= 40 && $6 >= 40)
        pass++
    else
        fail++

    print "----------------------------"
}
END {
	  print "Total Male Students:", male
    print "Total Female Students:", female
    print "Total Pass Students:", pass
    print "Total Fail Students:", fail
}
' $file
