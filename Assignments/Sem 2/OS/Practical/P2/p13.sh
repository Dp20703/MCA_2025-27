file="bill.txt"

echo "Search by:"
echo "1. Bill No"
echo "2. Customer No"
echo "3. Customer Name"
read choice

echo "Enter value:"
read value

case $choice in
1) result=$(grep "^$value:" $file) ;;
2) result=$(grep "^[^:]*:$value:" $file) ;;
3) result=$(grep -i ":$value:" $file) ;;
*) echo "Invalid choice"; exit ;;
esac

if [ -z "$result" ]; then
    echo "No record exists!"
else
    echo "$result" | while IFS=":" read bno cno cname addr city pin curr prev month
    do
        units=$((curr - prev))
        rate=5   # per unit
        bill=$((units * rate))

        echo "------ ELECTRICITY BILL ------"
        echo "Bill No: $bno"
        echo "Customer No: $cno"
        echo "Name: $cname"
        echo "Address: $addr"
        echo "City: $city - $pin"
        echo "Month: $month"
        echo "Units Consumed: $units"
        echo "Total Bill: Rs. $bill"
        echo "-------------------------------"
    done
fi