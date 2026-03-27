import java.io.*;
import java.util.*;

// Abstract Class
abstract class Shape {
    // Abstract method
    abstract double calculateArea();
}

// Circle Class
class Circle extends Shape {
    double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    double calculateArea() {
        return Math.PI * radius * radius;
    }
}

// Rectangle Class
class Rectangle extends Shape {
    double length, width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    double calculateArea() {
        return length * width;
    }
}

// Triangle Class
class Triangle extends Shape {
    double base, height;

    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    double calculateArea() {
        return 0.5 * base * height;
    }
}

// Main Class
public class P4 {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== Shape Area Menu =====");
            System.out.println("1. Circle");
            System.out.println("2. Rectangle");
            System.out.println("3. Triangle");
            System.out.println("4. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            Shape shape = null;
            double area = 0;

            switch (choice) {
                case 1:
                    System.out.print("Enter radius: ");
                    double r = sc.nextDouble();
                    shape = new Circle(r);
                    break;

                case 2:
                    System.out.print("Enter length: ");
                    double l = sc.nextDouble();
                    System.out.print("Enter width: ");
                    double w = sc.nextDouble();
                    shape = new Rectangle(l, w);
                    break;

                case 3:
                    System.out.print("Enter base: ");
                    double b = sc.nextDouble();
                    System.out.print("Enter height: ");
                    double h = sc.nextDouble();
                    shape = new Triangle(b, h);
                    break;

                case 4:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

            // Runtime Polymorphism
            if (shape != null) {
                area = shape.calculateArea();
                System.out.println("Area = " + area);
                saveToFile(choice, area);
            }

        } while (choice != 4);
    }

    // Save result to file
    static void saveToFile(int choice, double area) {
        try {
            FileWriter fw = new FileWriter("areas.txt", true);

            String shapeName = "";
            if (choice == 1)
                shapeName = "Circle";
            else if (choice == 2)
                shapeName = "Rectangle";
            else if (choice == 3)
                shapeName = "Triangle";

            fw.write(shapeName + " Area: " + area + "\n");
            fw.close();

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}