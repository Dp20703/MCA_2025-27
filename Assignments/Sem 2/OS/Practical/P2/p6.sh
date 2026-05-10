# using grep

echo -n "Enter file name:"
read filename

if [ -f "$filename" ]; then
    echo "Lines starting with a space:"
    grep '^ ' "$filename"
else
    echo "File not found!"
fi

# using sed

echo -n "Enter file name:"
read filename

if [ -f "$filename" ]; then
    echo "Lines starting with a space:"
    sed -n '/^ /p' "$filename"
else
    echo "File not found!"
fi