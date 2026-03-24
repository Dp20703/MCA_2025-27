# 18. If cost price and selling price of an item are entered through the keyboard,
# write a program to determine whether the seller has made profit or loss. Also
# determine how much profit/loss is made.


echo -n "Enter the buy price:"
read bprice
echo -n "Enter the sell price:"
read sprice

net=$((sprice - bprice))

if [ $net -gt 0 ]
then
    echo "Total Profit: $net"

elif [ $net -lt 0 ]
then
    loss=$((bprice - sprice))
    echo "Total Loss: $loss"
else
    echo "No Profit No Loss"
fi
