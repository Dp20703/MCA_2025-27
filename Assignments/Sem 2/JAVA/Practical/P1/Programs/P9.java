import java.io.*;
import java.util.*;

// Employee Class
class Employee {
    int id;
    String name;
    double salary;

    public Employee(int id, String name, double salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }
}

// Main Class
public class P9 {
    static final int NAME_SIZE = 20; // fixed length name

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;

        try {
            RandomAccessFile file = new RandomAccessFile("employees.dat", "rw");

            do {
                System.out.println("\n===== Employee Menu =====");
                System.out.println("1. Add Employee");
                System.out.println("2. Display All");
                System.out.println("3. Search by ID");
                System.out.println("4. Update Employee");
                System.out.println("5. Exit");
                System.out.print("Enter choice: ");
                choice = sc.nextInt();

                switch (choice) {
                    case 1:
                        addEmployee(file, sc);
                        break;

                    case 2:
                        displayEmployees(file);
                        break;

                    case 3:
                        searchEmployee(file, sc);
                        break;

                    case 4:
                        updateEmployee(file, sc);
                        break;

                    case 5:
                        System.out.println("Exiting...");
                        break;

                    default:
                        System.out.println("Invalid choice!");
                }

            } while (choice != 5);

            file.close();

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }

    // Add Employee
    static void addEmployee(RandomAccessFile file, Scanner sc) throws IOException {
        System.out.print("Enter ID: ");
        int id = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Name: ");
        String name = sc.nextLine();

        System.out.print("Enter Salary: ");
        double salary = sc.nextDouble();

        file.seek(file.length()); // go to end

        file.writeInt(id);

        // Write fixed length name
        StringBuffer sb = new StringBuffer(name);
        sb.setLength(NAME_SIZE);
        file.writeChars(sb.toString());

        file.writeDouble(salary);

        System.out.println("Employee added!");
    }

    // Display All Employees
    static void displayEmployees(RandomAccessFile file) throws IOException {
        file.seek(0);

        while (file.getFilePointer() < file.length()) {
            int id = file.readInt();

            char[] nameArr = new char[NAME_SIZE];
            for (int i = 0; i < NAME_SIZE; i++) {
                nameArr[i] = file.readChar();
            }
            String name = new String(nameArr).trim();

            double salary = file.readDouble();

            System.out.println("ID: " + id + ", Name: " + name + ", Salary: " + salary);
        }
    }

    // Search Employee
    static void searchEmployee(RandomAccessFile file, Scanner sc) throws IOException {
        System.out.print("Enter ID to search: ");
        int searchId = sc.nextInt();

        file.seek(0);
        boolean found = false;

        while (file.getFilePointer() < file.length()) {
            long position = file.getFilePointer();

            int id = file.readInt();

            char[] nameArr = new char[NAME_SIZE];
            for (int i = 0; i < NAME_SIZE; i++) {
                nameArr[i] = file.readChar();
            }
            String name = new String(nameArr).trim();

            double salary = file.readDouble();

            if (id == searchId) {
                System.out.println("Found -> ID: " + id + ", Name: " + name + ", Salary: " + salary);
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("Employee not found!");
        }
    }

    // Update Employee
    static void updateEmployee(RandomAccessFile file, Scanner sc) throws IOException {
        System.out.print("Enter ID to update: ");
        int updateId = sc.nextInt();

        file.seek(0);
        boolean found = false;

        while (file.getFilePointer() < file.length()) {
            long position = file.getFilePointer();

            int id = file.readInt();

            char[] nameArr = new char[NAME_SIZE];
            for (int i = 0; i < NAME_SIZE; i++) {
                nameArr[i] = file.readChar();
            }

            double salary = file.readDouble();

            if (id == updateId) {
                found = true;

                System.out.print("Enter new Name: ");
                sc.nextLine();
                String newName = sc.nextLine();

                System.out.print("Enter new Salary: ");
                double newSalary = sc.nextDouble();

                // Move pointer back to start of this record
                file.seek(position);

                file.writeInt(updateId);

                StringBuffer sb = new StringBuffer(newName);
                sb.setLength(NAME_SIZE);
                file.writeChars(sb.toString());

                file.writeDouble(newSalary);

                System.out.println("Record updated!");
                break;
            }
        }

        if (!found) {
            System.out.println("Employee not found!");
        }
    }
}
