file="library.dat"

echo "Enter student name to search:"
read sname

echo "Enter current date (DD-MM-YYYY):"
read today

echo "----- All Issued Books -----"
cat "$file"

echo "----- Books issued to $sname -----"
grep -i ":$sname:" "$file"

echo "----- Total Issued Books -----"
wc -l < "$file"

echo "----- Overdue Books -----"

awk -F ':' -v today="$today" '
function to_days(d) {
    split(d, a, "-")
    return a[3]*365 + a[2]*30 + a[1]
}

BEGIN {
    today_days = to_days(today)
}

{
    return_date = $6
    r_days = to_days(return_date)

    if (r_days < today_days) {
        print "Book:", $2, "| Student:", $4, "| Return Date:", $6
    }
}
' "$file"