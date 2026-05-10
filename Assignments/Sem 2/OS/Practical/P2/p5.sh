# using grep

echo -n "Enter file name:"
read filename

if [ -f "$filename" ]; then
    echo "Lines starting with t/T and second char h or s:"
    grep '^[Tt][hs]' "$filename"
else
    echo "File not found!"
fi

# using sed

echo -n "Enter file name:"
read filename

if [ -f "$filename" ]; then
    echo "Lines starting with t/T and second char h or s:"
    sed -n '/^[Tt][hs]/p' "$filename"
else
    echo "File not found!"
fi