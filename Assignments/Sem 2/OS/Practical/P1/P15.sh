# 15. Basic salary of a person is input through the keyboard. His dearness 
# allowance is 40% of basic salary and house rent is 20% of basic salary.
# Write a program to calculate the gross pay.

echo -n "Enter the basic salary:"
read salary

da=$((salary * 40 / 100))
hra=$((salary * 20 / 100))


gpay=$((salary + da + hra))

echo "Basic salary: $salary"
echo "DA: $da"
echo "HRA: $hra"
echo "------------------"
echo "Gross salary: $gpay"
