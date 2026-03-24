echo "Enter The file name:"
		read f1
		if [ ! -e $f1 ] ; then
			echo "ERROR....: File not exists"
			exit 
		elif [ ! -r $f1 ] ; then
			echo "ERROR....: User has not file read permissiopn"
		        exit
		else
			cat $f1
		fi
