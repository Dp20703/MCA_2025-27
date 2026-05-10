file="employee.dat"

echo "Search by:"
echo "1. Emp ID"
echo "2. Emp Name"
read choice

echo "Enter value:"
read value

awk -F ':' -v ch=$choice -v val="$value" '
BEGIN {
    max = -1
}

{
    emp_id = $1
    name = $2
    dept = $3
    basic = $4
    hra = $5
    da = $6
    pf = $7

    gross = basic + hra + da
    net = gross - pf

    # Find highest paid employee
    if (net > max) {
        max = net
        max_emp = name
    }

    # Search logic
    if ((ch == 1 && emp_id == val) || (ch == 2 && name == val)) {
        print "----- Employee Details -----"
        print "ID:", emp_id
        print "Name:", name
        print "Department:", dept
        print "Gross Salary:", gross
        print "Net Salary:", net
        print "----------------------------"
        found = 1
    }
}

END {
    if (found != 1)
        print "No record found!"

    print "Highest Paid Employee:", max_emp, "Salary:", max
}
' "$file"