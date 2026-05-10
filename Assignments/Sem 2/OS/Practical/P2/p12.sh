# Check minimum arguments
if [ $# -lt 2 ]; then
    echo "Usage: $0 <string> <file1> [file2 ...]"
    exit 1
fi

pattern=$1
shift   # remove first argument (string), rest are files

for file in "$@"
do
    if [ -f "$file" ]; then
        count=$(grep -c "$pattern" "$file")
        echo "$file : $count"
    else
        echo "$file : File not found"
    fi
done