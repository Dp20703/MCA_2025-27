file="inventory.dat"

echo "Search by:"
echo "1. Product ID"
echo "2. Product Name"
read ch

echo "Enter value:"
read val

awk -F ':' -v choice=$ch -v value="$val" '
BEGIN {
    total_value = 0
    max_qty = -1
    min_price = 999999
}

{
    pid = $1
    pname = $2
    qty = $3
    price = $4

    value_prod = qty * price
    total_value += value_prod

    # Highest quantity
    if (qty > max_qty) {
        max_qty = qty
        max_product = pname
    }

    # Lowest price
    if (price < min_price) {
        min_price = price
        min_product = pname
    }

    # Search
    if ((choice == 1 && pid == value) || (choice == 2 && pname == value)) {
        print "----- Product Details -----"
        print "ID:", pid
        print "Name:", pname
        print "Quantity:", qty
        print "Price:", price
        print "Total Value:", value_prod
        print "---------------------------"
        found = 1
    }
}

END {
    if (found != 1)
        print "No record found!"

    print "Total Inventory Value:", total_value
    print "Highest Quantity Product:", max_product, "Qty:", max_qty
    print "Lowest Price Product:", min_product, "Price:", min_price
}
' "$file"