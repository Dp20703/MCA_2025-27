file="electricity.dat"

echo "Search by:"
echo "1. Consumer No"
echo "2. Name"
read ch

echo "Enter value:"
read val

awk -F ':' -v choice=$ch -v value="$val" '
BEGIN {
    total_revenue = 0
    max_bill = -1
}

{
    cno = $1
    name = $2
    units = $3
    month = $4

    # Slab calculation
    if (units <= 100)
        bill = units * 2
    else if (units <= 200)
        bill = (100 * 2) + ((units - 100) * 3)
    else
        bill = (100 * 2) + (100 * 3) + ((units - 200) * 5)

    total_revenue += bill

    # Highest bill
    if (bill > max_bill) {
        max_bill = bill
        max_name = name
    }

    # Search
    if ((choice == 1 && cno == value) || (choice == 2 && name == value)) {
        print "----- Bill Details -----"
        print "Consumer No:", cno
        print "Name:", name
        print "Units:", units
        print "Month:", month
        print "Bill Amount: Rs.", bill
        print "------------------------"
        found = 1
    }
}

END {
    if (found != 1)
        print "No record found!"

    print "Total Revenue: Rs.", total_revenue
    print "Highest Bill Consumer:", max_name, "Amount:", max_bill
}
' "$file"