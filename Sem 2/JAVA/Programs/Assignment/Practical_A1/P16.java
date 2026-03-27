import java.io.*;
import java.util.*;

// Custom Exception
class InvalidDurationException extends Exception {
    public InvalidDurationException(String msg) {
        super(msg);
    }
}

// Member Class
class Member {
    int id;
    String name;
    int duration; // in months

    public Member(int id, String name, int duration) throws InvalidDurationException {
        if (duration <= 0) {
            throw new InvalidDurationException("Duration must be positive!");
        }
        this.id = id;
        this.name = name;
        this.duration = duration;
    }

    // Calculate Fees
    public double calculateFees() {
        double monthlyFee = 1000; // ₹1000 per month
        return duration * monthlyFee;
    }

    public void display() {
        System.out.println("ID: " + id +
                ", Name: " + name +
                ", Duration: " + duration + " months" +
                ", Fees: ₹" + calculateFees());
    }

    public String toFileString() {
        return id + "," + name + "," + duration + "," + calculateFees();
    }
}

// Main Class
public class P16 {
    static Scanner sc = new Scanner(System.in);
    static Member[] members = new Member[100];
    static int count = 0;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== Gym Menu =====");
            System.out.println("1. Add Member");
            System.out.println("2. Display Members");
            System.out.println("3. Save to File");
            System.out.println("4. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    addMember();
                    break;

                case 2:
                    displayMembers();
                    break;

                case 3:
                    saveToFile();
                    break;

                case 4:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 4);
    }

    // Add Member
    static void addMember() {
        try {
            System.out.print("Enter ID: ");
            int id = sc.nextInt();
            sc.nextLine();

            System.out.print("Enter Name: ");
            String name = sc.nextLine();

            System.out.print("Enter Duration (months): ");
            int duration = sc.nextInt();

            members[count++] = new Member(id, name, duration);
            System.out.println("Member added!");

        } catch (InvalidDurationException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    // Display Members
    static void displayMembers() {
        if (count == 0) {
            System.out.println("No records!");
            return;
        }

        for (int i = 0; i < count; i++) {
            members[i].display();
        }
    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("members.txt");

            for (int i = 0; i < count; i++) {
                fw.write(members[i].toFileString() + "\n");
            }

            fw.close();
            System.out.println("Data saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}