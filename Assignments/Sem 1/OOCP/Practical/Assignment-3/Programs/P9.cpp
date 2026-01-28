// 9) Create a base class called shape. Use this class to store two double type values
// that could be used to compute the area of figures. Derive three specific classes
// called triangle, rectangle and circle from the base shape. Add to the base class,
// a member function get_data( ) to initialize base class data members and
// another member function display_area( ) to compute and display the area of
// figures. Make display_area( ) as a virtual function and redefine this function in
// derived classes to suit their requirements. Using these three classes design a
// program that will accept dimensions of a triangle or rectangle interactively and
// store it in one array . After having read all the input display the area of all the
// figures whose area has been read in the program. Remember the two values
// given as input will be treated as lengths of two sides in the case of rectangle
// and as base and height in case of triangle. In case of circle only one value
// should be accepted which will be taken as the radius and the default value of
// the next parameter should be 0.

#include <iostream>
using namespace std;

// class shape
class Shape
{
protected:
    double v1, v2;

public:
    virtual void get_data()
    {
        cin >> v1 >> v2;
    }
    virtual void display() = 0;
    virtual ~Shape() {};
};

// class Triangle
class Triangle : public Shape
{
public:
    void get_data() override
    {
        cout << "Enter base and height of triangle:-";
        cin >> v1 >> v2;
    }
    void display() override
    {
        cout << "Triangle Area= " << 0.5 * v1 * v2 << endl;
    }
};
// class Rectangle
class Rectangle : public Shape
{
public:
    void get_data() override
    {
        cout << "Enter Length and width of rectangle:-";
        cin >> v1 >> v2;
    }
    void display() override
    {
        cout << "Rectangle Area= " << 0.5 * v1 * v2 << endl;
    }
};
// class Circle
class Circle : public Shape
{
public:
    void get_data() override
    {
        cout << "Enter Radius of Circle:-";
        cin >> v1;
        v2 = 0;
    }
    void display() override
    {
        cout << "Circle Area= " << 3.14519 * v1 * v1 << endl;
    }
};
int main()
{
    Shape *arr[10]; // array of shape pointers

    int n;
    cout << "How many shapes? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\n1.Triangle  2.Rectangle  3.Circle\nChoose shape: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            arr[i] = new Triangle;
        }
        else if (choice == 2)
        {
            arr[i] = new Rectangle;
        }
        else
        {
            arr[i] = new Circle;
        }
        arr[i]->get_data(); // take input
    }
    cout << "\n--- Areas ---\n";
    for (int i = 0; i < n; i++)
    {
        arr[i]->display(); // polymorphic call
    }

    // free memory
    for (int i = 0; i < n; i++)
    {
        delete arr[i];
    }

    return 0;
}

// output:
// How many shapes? 2

// 1.Triangle  2.Rectangle  3.Circle
// Choose shape: 1
// Enter base and height of triangle:-23
// 23

// 1.Triangle  2.Rectangle  3.Circle
// Choose shape: 3
// Enter Radius of Circle:-35

// --- Areas ---
// Triangle Area= 264.5
// Circle Area= 3852.86