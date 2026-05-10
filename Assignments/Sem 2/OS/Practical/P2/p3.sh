# using grep

echo -n "Enter file name:"
read filename

if [ -f "$filename" ]; then
    echo "Lines NOT starting with a, b, or c (with line numbers):"
    grep -n '^[^abc]' "$filename"
else
    echo "File not found!"
fi

# using sed

echo "Enter file name:"
read filename

if [ -f "$filename" ]; then
    echo "Lines NOT starting with a, b, or c (with line numbers):"
    sed -n '/^[^abc]/=' "$filename" | paste - - | awk '{print $1 ": " $2}'
else
    echo "File not found!"
fi
