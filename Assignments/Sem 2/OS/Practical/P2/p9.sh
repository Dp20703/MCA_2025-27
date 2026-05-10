file="books.txt"

while true
do
    echo "----- MENU -----"
    echo "1. Add Record"
    echo "2. Modify Record"
    echo "3. Delete Record"
    echo "4. Exit"
    echo "Enter your choice:"
    read ch

    case $ch in

    1)
        echo "Enter Book No:"
        read bno
        echo "Enter Book Name:"
        read bname
        echo "Enter Author:"
        read author
        echo "Enter Date of Purchase:"
        read dop

        echo "$bno-$bname-$author-$dop" >> $file
        echo "Record Added!"
        ;;

    2)
        echo "Enter Book No to Modify:"
        read bno

        if grep -q "^$bno-" $file; then
            echo "Enter New Book Name:"
            read bname
            echo "Enter New Author:"
            read author
            echo "Enter New Date:"
            read dop

            sed -i "s/^$bno-.*/$bno-$bname-$author-$dop/" $file
            echo "Record Modified!"
        else
            echo "Record not found!"
        fi
        ;;

    3)
        echo "Enter Book No to Delete:"
        read bno

        if grep -q "^$bno-" $file; then
            sed -i "/^$bno-/d" $file
            echo "Record Deleted!"
        else
            echo "Record not found!"
        fi
        ;;

    4)
        exit
        ;;

    *)
        echo "Invalid Choice!"
        ;;

    esac
done