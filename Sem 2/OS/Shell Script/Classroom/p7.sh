len=0
rev=0
rem=0
while [ $len -ne 5 ]
do
        clear
        echo enter a five digit number
        read n
        len=`echo $n | wc -c`
        len=`expr $len - 1`
done
while [ $n -gt 0 ]
do
        rem=`expr $n % 10`
        rev=`expr $rev \* 10 + $rem`
        n=`expr $n / 10`
done
echo " reverse number is $rev"
