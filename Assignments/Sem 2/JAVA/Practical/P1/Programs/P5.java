import java.io.*;
import java.util.*;

// Base Class
class Vehicle {
    int id; // instance variable
    String brand; // instance variable
    static int totalVehicles = 0; // static variable

    public Vehicle(int id, String brand) {
        this.id = id;
        this.brand = brand;
        totalVehicles++; // count vehicles
    }

    // Method to display (will be overridden)
    public void display() {
        System.out.println("ID: " + id + ", Brand: " + brand);
    }

    public String toFileString() {
        return id + "," + brand + "," + this.getClass().getSimpleName();
    }
}

// TwoWheeler Class
class TwoWheeler extends Vehicle {
    int mileage;

    public TwoWheeler(int id, String brand, int mileage) {
        super(id, brand);
        this.mileage = mileage;
    }

    @Override
    public void display() {
        System.out.println("TwoWheeler -> ID: " + id + ", Brand: " + brand +
                ", Mileage: " + mileage + " km/l");
    }
}

// FourWheeler Class
class FourWheeler extends Vehicle {
    int seatingCapacity;

    public FourWheeler(int id, String brand, int seatingCapacity) {
        super(id, brand);
        this.seatingCapacity = seatingCapacity;
    }

    @Override
    public void display() {
        System.out.println("FourWheeler -> ID: " + id + ", Brand: " + brand +
                ", Seats: " + seatingCapacity);
    }
}

// Main Class
public class P5 {
    static Scanner sc = new Scanner(System.in);
    static Vehicle[] vehicles = new Vehicle[100];
    static int count = 0;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== Vehicle Menu =====");
            System.out.println("1. Add Vehicle");
            System.out.println("2. Display Vehicles");
            System.out.println("3. Show Total Vehicles");
            System.out.println("4. Save to File");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    addVehicle();
                    break;
                case 2:
                    displayVehicles();
                    break;
                case 3:
                    System.out.println("Total Vehicles: " + Vehicle.totalVehicles);
                    break;
                case 4:
                    saveToFile();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 5);
    }

    // Add Vehicle
    static void addVehicle() {
        System.out.println("Select Type: 1.TwoWheeler  2.FourWheeler");
        int type = sc.nextInt();

        System.out.print("Enter ID: ");
        int id = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Brand: ");
        String brand = sc.nextLine();

        switch (type) {
            case 1:
                System.out.print("Enter Mileage: ");
                int mileage = sc.nextInt();
                vehicles[count++] = new TwoWheeler(id, brand, mileage);
                break;

            case 2:
                System.out.print("Enter Seating Capacity: ");
                int seats = sc.nextInt();
                vehicles[count++] = new FourWheeler(id, brand, seats);
                break;

            default:
                System.out.println("Invalid type!");
        }

        System.out.println("Vehicle added successfully!");
    }

    // Display Vehicles
    static void displayVehicles() {
        if (count == 0) {
            System.out.println("No vehicles found!");
            return;
        }

        for (int i = 0; i < count; i++) {
            vehicles[i].display();

            // Dynamic type identification
            if (vehicles[i] instanceof TwoWheeler) {
                System.out.println("Type: TwoWheeler");
            } else if (vehicles[i] instanceof FourWheeler) {
                System.out.println("Type: FourWheeler");
            }
        }
    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("vehicles.txt");

            for (int i = 0; i < count; i++) {
                fw.write(vehicles[i].toFileString() + "\n");
            }

            fw.close();
            System.out.println("Data saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}