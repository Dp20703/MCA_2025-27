file="cricket.dat"

awk -F ':' '
BEGIN {
    max_runs = -1
    count50 = 0

    print "----- Player Summary -----"
}

{
    name = $1
    runs = $2
    balls = $3
    fours = $4
    sixes = $5

    # Strike Rate
    strike_rate = (runs / balls) * 100

    printf "Player: %s | Runs: %d | Balls: %d | SR: %.2f\n", name, runs, balls, strike_rate

    # Highest scorer
    if (runs > max_runs) {
        max_runs = runs
        top_player = name
    }

    # Count players above 50
    if (runs > 50)
        count50++
}

END {
    print "----------------------------"
    print "Highest Scorer:", top_player, "Runs:", max_runs
    print "Players scoring above 50:", count50
}
' "$file"