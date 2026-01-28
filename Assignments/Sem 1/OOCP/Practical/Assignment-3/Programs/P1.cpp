// Inheritance

// 1) WAP to create base class Book having int id and char name as data members
// and respective functionality, show following types of inheritance and display
// the details of each kind of books, also calculate the total no of each type of
// books in proper format.
// Simple inheritance with derived class Sales
// Hierarchical inheritance with derived classes academics and thrillers
// Show use of constructor and destructor in above examples of inheritance.
#include <iostream>
#include <cstring>
using namespace std;

// Base Class
class Book
{
protected:
    int id;
    char name[50];
    static int totalBooks;

public:
    Book()
    {
        totalBooks++;
        cout << "\n[Book Constructor Called]";
    }

    virtual ~Book()
    {
        cout << "\n[Book Destructor Called]";
    }

    void getData()
    {
        cout << "\nEnter Book ID: ";
        cin >> id;
        cout << "Enter Book Name: ";
        cin.ignore();
        cin.getline(name, 50);
    }

    void displayData()
    {
        cout << "\nBook ID: " << id;
        cout << "\nBook Name: " << name;
    }

    static void showTotalBooks()
    {
        cout << "\nTotal Books (All Types): " << totalBooks;
    }
};

int Book::totalBooks = 0;

// ---------------- SIMPLE INHERITANCE ----------------

class Sales : public Book
{
    float price;
    static int totalSalesBooks;

public:
    Sales()
    {
        totalSalesBooks++;
        cout << "\n[Sales Constructor Called]";
    }

    ~Sales()
    {
        cout << "\n[Sales Destructor Called]";
    }

    void getData()
    {
        Book::getData();
        cout << "Enter Book Price: ";
        cin >> price;
    }

    void displayData()
    {
        cout << "\n--- Sales Book Details ---";
        Book::displayData();
        cout << "\nPrice: " << price;
    }

    static void showTotalSalesBooks()
    {
        cout << "\nTotal Sales Books: " << totalSalesBooks;
    }
};

int Sales::totalSalesBooks = 0;

// ---------------- HIERARCHICAL INHERITANCE ----------------

class Academics : public Book
{
    char subject[30];
    static int totalAcademicBooks;

public:
    Academics()
    {
        totalAcademicBooks++;
        cout << "\n[Academics Constructor Called]";
    }

    ~Academics()
    {
        cout << "\n[Academics Destructor Called]";
    }

    void getData()
    {
        Book::getData();
        cout << "Enter Subject: ";
        cin.ignore();
        cin.getline(subject, 30);
    }

    void displayData()
    {
        cout << "\n--- Academic Book Details ---";
        Book::displayData();
        cout << "\nSubject: " << subject;
    }

    static void showTotalAcademicBooks()
    {
        cout << "\nTotal Academic Books: " << totalAcademicBooks;
    }
};

int Academics::totalAcademicBooks = 0;

class Thrillers : public Book
{
    char author[30];
    static int totalThrillerBooks;

public:
    Thrillers()
    {
        totalThrillerBooks++;
        cout << "\n[Thrillers Constructor Called]";
    }

    ~Thrillers()
    {
        cout << "\n[Thrillers Destructor Called]";
    }

    void getData()
    {
        Book::getData();
        cout << "Enter Author Name: ";
        cin.ignore();
        cin.getline(author, 30);
    }

    void displayData()
    {
        cout << "\n--- Thriller Book Details ---";
        Book::displayData();
        cout << "\nAuthor: " << author;
    }

    static void showTotalThrillerBooks()
    {
        cout << "\nTotal Thriller Books: " << totalThrillerBooks;
    }
};

int Thrillers::totalThrillerBooks = 0;

// ---------------- MAIN FUNCTION ----------------

int main()
{
    cout << "=== SIMPLE INHERITANCE ===";
    Sales s1;
    s1.getData();
    s1.displayData();

    cout << "\n\n=== HIERARCHICAL INHERITANCE ===";
    Academics a1;
    a1.getData();
    a1.displayData();

    Thrillers t1;
    t1.getData();
    t1.displayData();

    cout << "\n\n=== TOTAL COUNTS ===";
    Book::showTotalBooks();
    Sales::showTotalSalesBooks();
    Academics::showTotalAcademicBooks();
    Thrillers::showTotalThrillerBooks();

    cout << "\n\nProgram End - Destructors will be called automatically.\n";

    return 0;
}

// Output:
// === SIMPLE INHERITANCE ===
// [Book Constructor Called]
// [Sales Constructor Called]
// Enter Book ID: 101
// Enter Book Name: Osho
// Enter Book Price: 1000

// --- Sales Book Details ---
// Book ID: 101
// Book Name: Osho
// Price: 1000

// === HIERARCHICAL INHERITANCE ===
// [Book Constructor Called]
// [Academics Constructor Called]
// Enter Book ID: 102
// Enter Book Name: Puppu
// Enter Subject: comedy

// --- Academic Book Details ---
// Book ID: 102
// Book Name: Puppu
// Subject: omedy
// [Book Constructor Called]
// [Thrillers Constructor Called]
// Enter Book ID: 103
// Enter Book Name: Fitnesss
// Enter Author Name: Dp

// --- Thriller Book Details ---
// Book ID: 103
// Book Name: Fitnesss
// Author: p

// === TOTAL COUNTS ===
// Total Books (All Types): 3
// Total Sales Books: 1
// Total Academic Books: 1
// Total Thriller Books: 1

// Program End - Destructors will be called automatically.

// [Thrillers Destructor Called]
// [Book Destructor Called]
// [Academics Destructor Called]
// [Book Destructor Called]
// [Sales Destructor Called]
// [Book Destructor Called]