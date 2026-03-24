# 1. Write a shell script to display all odd and even numbers using various loops
# available(for, while and until).

echo " Using FOR loop "

for i  in  {1..20}
do
	if [ $((i % 2)) -eq 0 ]
	then
	  echo "$i is even " 
	else 
	   echo "$i is odd"
	fi
done

echo
echo "Using While loop "

i=1

while [ $i -le 20 ]
do
    if [ $((i % 2)) -eq 0 ]
        then
          echo "$i is even "
        else
           echo "$i is odd"
        fi
	i=$((i+1))
done
echo 

echo "Using UNTIL loop"

i=1
until [ $i -gt 20 ]
do
  if [ $((i % 2)) -eq 0 ]
    then
        echo "$i is Even"
    else
        echo "$i is Odd"
    fi
    i=$((i+1))
done

