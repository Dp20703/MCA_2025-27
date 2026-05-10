# using grep 

echo "Enter file name:"
read filename

if [ -f "$filename" ]; then
    echo "Lines starting with a, b, or c:"
    grep '^[abc]' "$filename"
else
    echo "File not found!"
fi

# using sed 

echo "Enter file name:"
read filename

if [ -f "$filename" ]; then
    echo "Lines starting with a, b, or c:"
    sed -n '/^[abc]/p' "$filename"
else
    echo "File not found!"
fi

