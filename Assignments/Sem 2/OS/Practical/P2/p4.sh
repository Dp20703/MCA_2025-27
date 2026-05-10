#using sed

echo "Enter file name:"
read filename

if [ -f "$filename" ]; then
    echo "Output after replacing spaces with #:"
    sed 's/ /#/g' "$filename"
else
    echo "File not found!"
fi