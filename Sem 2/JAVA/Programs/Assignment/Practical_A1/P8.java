import java.io.*;
import java.util.*;

// Custom Exception
class InvalidAgeException extends Exception {
    public InvalidAgeException(String msg) {
        super(msg);
    }
}

// Voter Class
class Voter {
    int id;
    String name;
    int age;

    public Voter(int id, String name, int age) throws InvalidAgeException {
        if (age < 18) {
            throw new InvalidAgeException("Age must be 18 or above!");
        }
        this.id = id;
        this.name = name;
        this.age = age;
    }

    public void display() {
        System.out.println("ID: " + id + ", Name: " + name +
                ", Age: " + age + " (Eligible)");
    }

    public String toFileString() {
        return id + "," + name + "," + age;
    }
}

// Main Class
public class P8 {
    static Scanner sc = new Scanner(System.in);
    static Voter[] voters = new Voter[100];
    static int count = 0;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== Voter Menu =====");
            System.out.println("1. Add Voter");
            System.out.println("2. Display Voters");
            System.out.println("3. Save to File");
            System.out.println("4. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    addVoter();
                    break;

                case 2:
                    displayVoters();
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

    // Add Voter
    static void addVoter() {
        try {
            System.out.print("Enter ID: ");
            int id = sc.nextInt();
            sc.nextLine();

            System.out.print("Enter Name: ");
            String name = sc.nextLine();

            System.out.print("Enter Age: ");
            int age = sc.nextInt();

            voters[count++] = new Voter(id, name, age);
            System.out.println("Voter added successfully!");

        } catch (InvalidAgeException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    // Display Voters
    static void displayVoters() {
        if (count == 0) {
            System.out.println("No voter records!");
            return;
        }

        for (int i = 0; i < count; i++) {
            voters[i].display();
        }
    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("voters.txt");

            for (int i = 0; i < count; i++) {
                fw.write(voters[i].toFileString() + "\n");
            }

            fw.close();
            System.out.println("Data saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}