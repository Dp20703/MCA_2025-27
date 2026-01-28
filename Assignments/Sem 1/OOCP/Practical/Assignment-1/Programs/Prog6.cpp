// 6. Write a program to define a class called book. Write a program to read
// information about 10 books and display books details in ascending order of
// price in proper format.

#include <iostream>
#include <string>
using namespace std;

class Book
{
    int id;
    string title;

public:
    float price;
    void input()
    {
        cout << "Enter Book_Id:";
        cin >> id;
        cout << "Enter Title:";
        cin >> title;
        cout << "Enter Price:";
        cin >> price;
    }
    void display()
    {
        cout << "\tID: " << id << "\tTitle: " << title << "\tPrice: " << price;
    }
};
// sort books in asceding order as per price
void sortBooks(Book b[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (b[j].price > b[j + 1].price)
            {
                Book temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n = 10;
    Book b[n];
    // input
    cout << "Enter Book Details";
    for (int i = 0; i < n; i++)
    {
        cout << "\nBook " << i + 1 << "\n";
        b[i].input();
    }

    // sortbooks
    sortBooks(b, n);

    // display
    cout << "Book Details in asceding order" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\n Book: " << i + 1 << "|";
        b[i].display();
        ;
    }
    return 0;
}
// output:
// Enter Book Details
// Book 1
// Enter Book_Id:101
// Enter Title:book1
// Enter Price:1123

// Book 2
// Enter Book_Id:102
// Enter Title:book2
// Enter Price:1299

// Book 3
// Enter Book_Id:103
// Enter Title:book3
// Enter Price:2399

// Book 4
// Enter Book_Id:104
// Enter Title:book4
// Enter Price:9899

// Book 5
// Enter Book_Id:105
// Enter Title:book5
// Enter Price:9999

// Book 6
// Enter Book_Id:106
// Enter Title:book6
// Enter Price:8799

// Book 7
// Enter Book_Id:107
// Enter Title:book7
// Enter Price:799

// Book 8
// Enter Book_Id:108
// Enter Title:book8
// Enter Price:399

// Book 9
// Enter Book_Id:109
// Enter Title:book9
// Enter Price:499

// Book 10
// Enter Book_Id:110
// Enter Title:book10
// Enter Price:699
// Book Details in asceding order

//  Book: 1|       ID: 108  Title: book8     Price: 399
//  Book: 2|       ID: 109  Title: book9     Price: 499
//  Book: 3|       ID: 110  Title: book10    Price: 699
//  Book: 4|       ID: 107  Title: book7     Price: 799
//  Book: 5|       ID: 101  Title: book1     Price: 1123
//  Book: 6|       ID: 102  Title: book2     Price: 1299
//  Book: 7|       ID: 103  Title: book3     Price: 2399
//  Book: 8|       ID: 106  Title: book6     Price: 8799
//  Book: 9|       ID: 104  Title: book4     Price: 9899
//  Book: 10|      ID: 105  Title: book5     Price: 9999