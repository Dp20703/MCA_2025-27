i#!/bin/ksh
dt=$(date +%I);
tmp=$(date +%p);
echo $dt
echo $tmp
if [ $dt -gt 12 -o $dt -lt 04 -a $tmp="PM" ] ; then
   echo "Good afternoon.................."
elif [ $dt -gt 12 -o $dt -lt 12 -a $tmp="AM" ] ; then
   echo "Good Morning........."
elif [ $dt -gt 04 -a $dt -lt 08 -a $tmp="PM" ] ; then
     echo "good evening............."
else
  echo "good  night............"
fi
#if [ $dt -gt 12 -o $dt -lt 04 -a $tmp=="PM" ] ; then
 #       echo "  Good Afternoon....."
#elif [ $dt -gt 04 -o $dt -lt 08 -a $tmp=="PM" ] ; then
 #       echo "   Good Evening....."
#elif [ $dt -gt 08 -o $dt -lt 12 -a $tmp=="PM" ] ; then
  #      echo "     Good Night....."
#else
 #       echo "       Good Morning....."
#fi
