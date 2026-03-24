# 16. The distance between two cities is input through the keyboard. (in km).
# Write a program to convert this distance into metres, feet, inches and
# centimetres and display the results.


echo -n "Enter distance in kilometers: "
read km

meters=$((km * 1000))
centimeters=$((km * 100000))

feet=$((km * 3281))
inches=$((km * 39370))

echo "--------------------------------"
echo "Distance in Kilometers : $km km"
echo "Distance in Meters     : $meters m"
echo "Distance in Centimeters: $centimeters cm"
echo "Distance in Feet       : $feet ft"
echo "Distance in Inches     : $inches in"
echo "--------------------------------"
