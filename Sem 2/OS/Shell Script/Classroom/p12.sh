echo "Enter the password:"
read pass1
echo "\nRetype password:"
read pass2
if [ "${pass1}" = "${pass2}" ]
then
        tput clear
        echo "\nThe terminal is locked"
        echo "\nEnter password to unlock:"
        read pass3
        while [ "${pass1}" != "${pass3}" ]
        do
                echo "\nWrong password"
                echo "\nEnter password to unlock:"
                read pass3
        done
        echo "\nTerminal Unlocked"
else
        echo "\nPassword does not match"
fi


 