 echo "
        		1.Remove
        		2.Rename
        		3.Copy
        		4.Modify
       			5.Exit
      "
		echo -n "Enter your choice:"
		read str1
		clear 
		case "$str1" in
 	1) echo -n "enter the name of the file that you want to remove:"
       	   read f1
       	   rm $f1
       	   ;;        
	2) echo -n "Enter the name of the file that you want to rename:"
       	   read f1
       	   echo -n "Enter the new file name:"
       	   read f2
       	   mv $f1 $f2
       	   ;;        
       	3) echo -n "Enter the source file name:"
       	   read f1
       	   echo -n "Enter the destination file name:"
       	   read f2
       	   cp $f1 $f2 
	   ;;		
	4) echo -n "Enter the name of the file that you want to modify:"
       	   read f1
       	   vi $f1
       	   ;;			
	5)exit;;
		esac       	


