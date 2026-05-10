import java.io.*;
import java.util.*;

// Custom Exception
class InvalidAgeException extends Exception {
    public InvalidAgeException(String msg) {
        super(msg);
    }
}

// Patient Class
class Patient {
    int id;
    String name;
    int age;
    String disease;

    public Patient(int id, String name, int age, String disease) throws InvalidAgeException {
        if (age <= 0 || age > 120) {
            throw new InvalidAgeException("Invalid age entered!");
        }
        this.id = id;
        this.name = name;
        this.age = age;
        this.disease = disease;
    }

    public void display() {
        System.out.println("ID: " + id +
                ", Name: " + name +
                ", Age: " + age +
                ", Disease: " + disease);
    }

    public String toFileString() {
        return id + "," + name + "," + age + "," + disease;
    }
}

// Main Class
public class P15 {
    static Scanner sc = new Scanner(System.in);
    static Patient[] patients = new Patient[100];
    static int count = 0;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== Patient Menu =====");
            System.out.println("1. Add Patient");
            System.out.println("2. Display Patients");
            System.out.println("3. Search Patient by ID");
            System.out.println("4. Save to File");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    addPatient();
                    break;

                case 2:
                    displayPatients();
                    break;

                case 3:
                    searchPatient();
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

    // Add Patient
    static void addPatient() {
        try {
            System.out.print("Enter ID: ");
            int id = sc.nextInt();
            sc.nextLine();

            System.out.print("Enter Name: ");
            String name = sc.nextLine();

            System.out.print("Enter Age: ");
            int age = sc.nextInt();
            sc.nextLine();

            System.out.print("Enter Disease: ");
            String disease = sc.nextLine();

            patients[count++] = new Patient(id, name, age, disease);
            System.out.println("Patient added!");

        } catch (InvalidAgeException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    // Display Patients
    static void displayPatients() {
        if (count == 0) {
            System.out.println("No records found!");
            return;
        }

        for (int i = 0; i < count; i++) {
            patients[i].display();
        }
    }

    // Search Patient
    static void searchPatient() {
        System.out.print("Enter ID to search: ");
        int searchId = sc.nextInt();

        boolean found = false;

        for (int i = 0; i < count; i++) {
            if (patients[i].id == searchId) {
                patients[i].display();
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("Patient not found!");
        }
    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("patients.txt");

            for (int i = 0; i < count; i++) {
                fw.write(patients[i].toFileString() + "\n");
            }

            fw.close();
            System.out.println("Data saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}
