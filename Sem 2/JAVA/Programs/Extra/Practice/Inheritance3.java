/*
 * Create three crasses Vehicle, TwoWheeler and FourWheeler. 
Vehicle is a parent
 * class of TwoWheeler and FourWheeler. In Vehicle class data members are
 * company name, and methods are input and display. 
 * In TwoWheelers class, data
 * members are name, type (gear, non gear); and methods are input and display.
 * In FourWheelers data members are name, model no, fuel type: and methods are
 * input and display.
 * 
 * 3 Write a program which will input and display information of two wheeler and
 * four wheeler using the concept of method overriding.
 */

import java.util.Scanner;

class Vehicle {
    String company_name;

    // input
    void input() {
        System.out.println("enter name of company:");
        Scanner sc = new Scanner(System.in);
        company_name = sc.nextLine();
    }

    // display
    void display() {
        System.out.println("Company name:" + company_name);
    }
}

class TwoWheeler extends Vehicle {
    String name;
    String type;

    // input
    void input() {
        super.input();
        Scanner sc = new Scanner(System.in);
        System.out.println("enter name of model:");
        name = sc.nextLine();
        System.out.println("enter type of vehical (gear or non-gear):");
        type = sc.nextLine();
    }

    // display
    void display() {
        super.display();
        System.out.println("Name of two-wheeler :" + name);
        System.out.println("Type of two-wheeler :" + type);
    }

}

class FourWheeler extends Vehicle {
    String name;
    String modelNo;
    String fuelType;

    // input
    void input() {
        super.input();
        Scanner sc = new Scanner(System.in);
        System.out.println("enter name of model:");
        name = sc.nextLine();
        System.out.println("enter modelno:");
        modelNo = sc.nextLine();
        System.out.println("enter type of fuel:");
        fuelType = sc.nextLine();
    }

    // display
    void display() {
        super.display();
        System.out.println("Name of four-wheeler :" + name);
        System.out.println("Model no of four-wheeler :" + modelNo);
        System.out.println("Fuel type of four-wheeler :" + fuelType);
    }

}

public class Inheritance3 {

    public static void main(String[] args) {
        System.out.println("1. Two Wheeler");
        System.out.println("2. Four Wheeler");
        System.out.println("Enter choice:");
        int choice;
        Scanner sc = new Scanner(System.in);
        choice = sc.nextInt();

        switch (choice) {
            case 1:
                Vehicle v1 = new TwoWheeler();
                v1.input();
                v1.display();
                break;
            case 2:
                Vehicle v2 = new FourWheeler();
                v2.input();
                v2.display();
                break;

            default:
                System.out.println("Invalid input");
                break;
        }
    }

}