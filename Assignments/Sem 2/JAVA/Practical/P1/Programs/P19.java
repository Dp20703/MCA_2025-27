import java.io.*;
import java.util.*;

// Trip Class
class Trip {
    int id;
    String destination;
    double price;

    public Trip(int id, String destination, double price) {
        this.id = id;
        this.destination = destination;
        this.price = price;
    }

    public void display() {
        System.out.println("ID: " + id + ", Destination: " + destination +
                ", Price: ₹" + price);
    }
}

// Booking Class
class Booking {
    int bookingId;
    String customerName;
    Trip trip;

    public Booking(int bookingId, String customerName, Trip trip) {
        this.bookingId = bookingId;
        this.customerName = customerName;
        this.trip = trip;
    }

    public void display() {
        System.out.println("Booking ID: " + bookingId +
                ", Name: " + customerName +
                ", Trip: " + trip.destination +
                ", Price: ₹" + trip.price);
    }

    public String toFileString() {
        return bookingId + "," + customerName + "," +
                trip.destination + "," + trip.price;
    }
}

// Main Class
public class P19 {
    static Scanner sc = new Scanner(System.in);

    static Trip[] trips = new Trip[100];
    static Booking[] bookings = new Booking[100];

    static int tCount = 0, bCount = 0;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== Travel Booking Menu =====");
            System.out.println("1. Add Trip");
            System.out.println("2. Display Trips");
            System.out.println("3. Book Trip");
            System.out.println("4. Display Bookings");
            System.out.println("5. Save to File");
            System.out.println("6. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    addTrip();
                    break;

                case 2:
                    displayTrips();
                    break;

                case 3:
                    bookTrip();
                    break;

                case 4:
                    displayBookings();
                    break;

                case 5:
                    saveToFile();
                    break;

                case 6:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 6);
    }

    // Add Trip
    static void addTrip() {
        System.out.print("Enter Trip ID: ");
        int id = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Destination: ");
        String dest = sc.nextLine();

        System.out.print("Enter Price: ");
        double price = sc.nextDouble();

        trips[tCount++] = new Trip(id, dest, price);
        System.out.println("Trip added!");
    }

    // Display Trips
    static void displayTrips() {
        if (tCount == 0) {
            System.out.println("No trips available!");
            return;
        }

        for (int i = 0; i < tCount; i++) {
            trips[i].display();
        }
    }

    // Find Trip
    static Trip findTrip(int id) {
        for (int i = 0; i < tCount; i++) {
            if (trips[i].id == id)
                return trips[i];
        }
        return null;
    }

    // Book Trip
    static void bookTrip() {
        System.out.print("Enter Trip ID: ");
        int id = sc.nextInt();

        Trip trip = findTrip(id);
        if (trip == null) {
            System.out.println("Trip not found!");
            return;
        }

        System.out.print("Enter Customer Name: ");
        sc.nextLine();
        String name = sc.nextLine();

        bookings[bCount++] = new Booking(bCount, name, trip);
        System.out.println("Booking successful!");
    }

    // Display Bookings
    static void displayBookings() {
        if (bCount == 0) {
            System.out.println("No bookings!");
            return;
        }

        for (int i = 0; i < bCount; i++) {
            bookings[i].display();
        }
    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("travel_bookings.txt");

            for (int i = 0; i < bCount; i++) {
                fw.write(bookings[i].toFileString() + "\n");
            }

            fw.close();
            System.out.println("Data saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}