// 6) Define a class Figure and use inheritance to define the classes Triangle,Square, Circle, and Rectangle. Provide a container class Frame to contain any number of figures, possibly overlapped in position. Provide operations for drawing frames on the screen and for inserting, modifying, and deleting frames and the contents of frames. (Actual drawing is not required).

//       figure
// circle squre triangle rectangle

#include <iostream>
using namespace std;

class Figure
{
public:
    virtual ~Figure() = default; // <-- virtual destructor (safe)
    virtual void draw()
    {
        cout << "Drawing base class figure\n";
    };
};

class Triangle : public Figure
{
public:
    void draw() override
    {
        cout << "Drawing Triangle\n";
    }
};

class Square : public Figure
{
public:
    void draw() override
    {
        cout << "Drawing Square\n";
    }
};

class Circle : public Figure
{
public:
    void draw() override
    {
        cout << "Drawing Circle\n";
    }
};

class Rectangle : public Figure
{
public:
    void draw() override
    {
        cout << "Drawing Rectangle\n";
    }
};

int main()
{
    Figure *f1 = nullptr; // initialize pointer
    Circle c1;
    Square s1;
    Rectangle r1;
    Triangle t1;
    int choice;

    while (true)
    {
        cout << "\nEnter the shape you want to draw, -1 to stop drawing:\n"
             << "1. Triangle\t2. Circle\t3. Square\t4. Rectangle\n";
        if (!(cin >> choice))
        {
            cout << "Invalid input. Exiting.\n";
            break;
        }

        if (choice == 1)
        {
            f1 = &t1;
        }
        else if (choice == 2)
        {
            f1 = &c1;
        }
        else if (choice == 3)
        {
            f1 = &s1;
        }
        else if (choice == 4)
        {
            f1 = &r1;
        }
        else if (choice == -1)
        {
            cout << "Bye bye!\n";
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
            continue;
        }

        if (f1)
            f1->draw();
    }

    return 0;
}

// Output:

// Enter the shape you want to draw, -1 to stop drawing:
// 1. Triangle     2. Circle       3. Square       4. Rectangle
// 1
// Drawing Triangle

// Enter the shape you want to draw, -1 to stop drawing:
// 1. Triangle     2. Circle       3. Square       4. Rectangle
// 2
// Drawing Circle

// Enter the shape you want to draw, -1 to stop drawing:
// 1. Triangle     2. Circle       3. Square       4. Rectangle
// 3
// Drawing Square

// Enter the shape you want to draw, -1 to stop drawing:
// 1. Triangle     2. Circle       3. Square       4. Rectangle
// 4
// Drawing Rectangle

// Enter the shape you want to draw, -1 to stop drawing:
// 1. Triangle     2. Circle       3. Square       4. Rectangle
// 41
// Invalid choice!

// Enter the shape you want to draw, -1 to stop drawing:
// 1. Triangle     2. Circle       3. Square       4. Rectangle
// -1
// Bye bye!