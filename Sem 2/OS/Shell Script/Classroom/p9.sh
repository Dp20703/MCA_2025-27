$t=0;
while [ $t = 0 ]
do
        echo "--------------------------------"
        echo "EMPLOYEE INFORMATION"
        echo "--------------------------------"
        echo "1.Add Employee"
        echo "2.Modify Employee"
        echo "3.Delete Employee"
        echo "4.Display Employee"
	echo "5.Exit"
        echo "--------------------------------"
        echo "Enter the  choice"
        read ch;
        case "$ch" in
                1) echo "enter the Employee No->"
                   read empno
                   echo "enter the Employee Name->"
                   read empname
                   echo "-------------------------------"
                   echo "enter the Employee Department->"
                   echo "-------------------------------"
                   echo "1.Sales"
                   echo "2.Purchase"
                   echo "3.Marketing"
                   echo "-------------------------------"
                   echo "select Department"
                   read dept
                        case "$dept" in
                              1) dept ="Sales";;
                              2) dept ="Purchase";;
                              3) dept ="Matketing";;
                        esac
                   echo "-------------------------------"
                   echo "Enter the Employee Designation"
                   echo "-------------------------------"
                   echo "1.Manager"
                   echo "2.Director"
                   echo "3.Programmer"
                   echo "-------------------------------"
                   read desig
                        case "$desig" in
                                1) desig ="Manager";;
                                2) desig ="programmer";;
 				3) desig ="Director";;
                        esac
                   echo "enter the Employee Salary->"
                   read sal
                   echo $empno:$empname:$dept:$desig:$sal >>emp.txt
                   echo "Inserted Record Successfully.........."
                   echo "---------------------------------------"
                   ;;
                2);;
                3);;
                4)echo "Enter the Employee No->"
                        read em
                        cnt=0;
                  for i in `cat emp.txt`
                  do
                      echo $i >tmp
                     k=`cut -d: -f1 tmp`
                    if [ "$k" == "$em"] ; then 
                                cnt=`$cnt + 1`
              echo "-------------------------------------------"
              echo "          Employee Information             "
              echo "-------------------------------------------"
              echo "Employee No=$k"
              echo "Employee Name="`cut -d: -f2 tmp`
              echo "Employee Department="`cut -d: -f3 tmp`
              echo "Employee Designation="`cut -d: -f4 tmp`
              echo "Employee Salary="`cut -d: -f5 tmp`
              echo "--------------------------------------------"
              fi
              done
              	if [ "$cnt" == "0" ] ; then
                        echo "Employee is not Exists..."
                 fi
		;;

                5)
                echo "Enter proper choice"
			exit
;;
        esac
done

