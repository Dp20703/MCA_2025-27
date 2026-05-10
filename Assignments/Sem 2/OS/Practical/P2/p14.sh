file="sales.dat"

awk -F ':' '
BEGIN {
    total = 0
    p1 = p2 = p3 = 0
    max = -1
    min = 999999
}

{
    salesman = $1
    s1 = $2
    s2 = $3
    s3 = $4

    sum = s1 + s2 + s3

    total += sum

    p1 += s1
    p2 += s2
    p3 += s3

    if (sum > max) {
        max = sum
        best = salesman
    }

    if (sum < min) {
        min = sum
        worst = salesman
    }
}

END {
    print "Total Sales of Company:", total

    if (p1 > p2 && p1 > p3)
        print "Highest Sold Product: Product1"
    else if (p2 > p1 && p2 > p3)
        print "Highest Sold Product: Product2"
    else
        print "Highest Sold Product: Product3"

    print "Best Salesman:", best
    print "Worst Salesman:", worst
}
' "$file"