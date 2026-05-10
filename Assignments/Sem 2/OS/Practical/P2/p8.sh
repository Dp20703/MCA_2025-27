echo "Username    No. of Processes"

ps -e -o user= | sort | uniq -c | awk '{print $2 "\t\t" $1}'
