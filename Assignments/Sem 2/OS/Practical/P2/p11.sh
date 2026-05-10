echo "Enter file name:"
read filename

if [ -f "$filename" ]; then
    echo "Number of vowels (case-insensitive):"
    grep -oi '[aeiou]' "$filename" | wc -l
else
    echo "File not found!"
fi