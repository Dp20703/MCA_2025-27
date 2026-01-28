// 11) ABC publishing company markets both book and audio cassette versions of its
// work. Create a class called publication that stores the title( a string) and price(
// type float) of a publication. From this class derive two classes : book , which
// adds a page count (type int); and tape, which adds playing time in minutes
// (type float). Write a main program that reads both book and tape information in
// one array. When the user has finished entering data for all books and tapes,
// displays the resulting data for all the books and tapes entered. Also count no of
// book and cassette entries in the array using runtime identification feature of
// C++.

// Base class Publication : title string , price float
// Derive class Book: pageCount int
// Derive class Tape: minutes float

#include <iostream>
#include <typeinfo>
using namespace std;

// base class : Publication
class Publication
{
protected:
    string title;
    float price;

public:
    virtual void input()
    {
        cout << "\n Enter the title:- ";
        cin.ignore();
        getline(cin, title);

        cout << "\n Enter the price:- ";
        cin >> price;
    }
    void display()
    {
        cout << "\t Title:" << title << "\t Price:" << price;
    }
};
// derived class: Book
class Book : public Publication
{
private:
    int pageCount;

public:
    void input()
    {
        Publication::input();
        cout << "Enter the page count: ";
        cin >> pageCount;
    }
    void display()
    {
        Publication::display();
        cout << "\t Page Count :" << pageCount;
    }
};
// derived class: Tape
class Tape : public Publication
{
private:
    float minutes;

public:
    void input()
    {
        Publication::input();
        cout << "Enter the minutes: ";
        cin >> minutes;
    }
    void display()
    {
        Publication::display();
        cout << "\t Audio minutes :" << minutes;
    }
};
int main()
{
    Publication *items[20];
    int n, type;
    int bookCount = 0, tapeCount = 0;
    cout << "How many publication do you want to store? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter 1 for Book, 2 for Tape: ";
        cin >> type;

        if (type == 1)
            items[i] = new Book;
        else
            items[i] = new Tape;

        items[i]->input();
    }
    cout << "\n\n--- Displaying Publications ---\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nPublication " << i + 1 << ":\n";
        items[i]->display();

        // Runtime Identification
        // using dynamic_cast
        if (dynamic_cast<Book *>(items[i]) != nullptr)
            bookCount++;
        else if (dynamic_cast<Tape *>(items[i]) != nullptr)
            tapeCount++;

        // using typeid
        // if (typeid(*items[i]) == typeid(Book))
        // {
        //     bookCount++;
        // }
        // else if (typeid(*items[i]) == typeid(Tape))
        // {
        //     tapeCount++;
        // }
    }

    cout << "\nTotal Books: " << bookCount;
    cout << "\nTotal Tapes: " << tapeCount << endl;

    for (int i = 0; i < n; i++)
        delete items[i];

    return 0;
}

// Output:

// How many publication do you want to store? 5

// Enter 1 for Book, 2 for Tape: 1

//  Enter the title:- DS Book

//  Enter the price:- 120
// Enter the page count: 25

// Enter 1 for Book, 2 for Tape: 2

//  Enter the title:- Kishor kumar audio

//  Enter the price:- 1200
// Enter the minutes: 820

// Enter 1 for Book, 2 for Tape: 1

//  Enter the title:- RDBMS book

//  Enter the price:- 839
// Enter the page count: 88

// Enter 1 for Book, 2 for Tape: 2

//  Enter the title:- Yo yo honey singh

//  Enter the price:- 283
// Enter the minutes: 82

// Enter 1 for Book, 2 for Tape: 1

//  Enter the title:- Python for beginner

//  Enter the price:- 822
// Enter the page count: 833

// --- DISPLAYING PUBLICATIONS ---

// Publication 1:
//          Title:DS Book   Price:120
// Publication 2:
//          Title:Kishor kumar audio        Price:1200
// Publication 3:
//          Title:RDBMS book        Price:839
// Publication 4:
//          Title:Yo yo honey singh         Price:283
// Publication 5:
//          Title:Python for beginner       Price:822
// Total Books: 3
// Total Tapes: 2