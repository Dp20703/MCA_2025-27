import java.io.*;
import java.util.*;

// Custom Exception
class InvalidSalaryException extends Exception {
    public InvalidSalaryException(String msg) {
        super(msg);
    }
}

// Base Class
class Employee {
    int id;
    String name;
    double baseSalary;

    public Employee(int id, String name, double baseSalary) throws InvalidSalaryException {
        if (baseSalary < 0) {
            throw new InvalidSalaryException("Salary cannot be negative!");
        }
        this.id = id;
        this.name = name;
        this.baseSalary = baseSalary;
    }

    // Method to calculate salary (will be overridden)
    public double calculateSalary() {
        return baseSalary;
    }

    public void display() {
        System.out.println("ID: " + id + ", Name: " + name +
                ", Salary: " + calculateSalary());
    }

    public String toFileString() {
        return id + "," + name + "," + calculateSalary() + "," + this.getClass().getSimpleName();
    }
}

// Manager Class
class Manager extends Employee {
    public Manager(int id, String name, double baseSalary) throws InvalidSalaryException {
        super(id, name, baseSalary);
    }

    @Override
    public double calculateSalary() {
        return baseSalary + 5000; // Bonus
    }
}

// Developer Class
class Developer extends Employee {
    public Developer(int id, String name, double baseSalary) throws InvalidSalaryException {
        super(id, name, baseSalary);
    }

    @Override
    public double calculateSalary() {
        return baseSalary + 3000; // Bonus
    }
}

// Intern Class
class Intern extends Employee {
    public Intern(int id, String name, double baseSalary) throws InvalidSalaryException {
        super(id, name, baseSalary);
    }

    @Override
    public double calculateSalary() {
        return baseSalary; // No bonus
    }
}

// Main Class
public class P2 {
    static Scanner sc = new Scanner(System.in);
    static Employee[] employees = new Employee[100];
    static int count = 0;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== Payroll Menu =====");
            System.out.println("1. Add Employee");
            System.out.println("2. Display Employees");
            System.out.println("3. Save to File");
            System.out.println("4. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    addEmployee();
                    break;
                case 2:
                    displayEmployees();
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

    // Add Employee
    static void addEmployee() {
        try {
            System.out.println("Select Type: 1.Manager  2.Developer  3.Intern");
            int type = sc.nextInt();

            System.out.print("Enter ID: ");
            int id = sc.nextInt();
            sc.nextLine();

            System.out.print("Enter Name: ");
            String name = sc.nextLine();

            System.out.print("Enter Base Salary: ");
            double salary = sc.nextDouble();

            switch (type) {
                case 1:
                    employees[count++] = new Manager(id, name, salary);
                    break;
                case 2:
                    employees[count++] = new Developer(id, name, salary);
                    break;
                case 3:
                    employees[count++] = new Intern(id, name, salary);
                    break;
                default:
                    System.out.println("Invalid type!");
                    return;
            }

            System.out.println("Employee added successfully!");

        } catch (InvalidSalaryException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    // Display Employees
    static void displayEmployees() {
        if (count == 0) {
            System.out.println("No records!");
            return;
        }

        for (int i = 0; i < count; i++) {
            employees[i].display();
        }
    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("employees.txt");

            for (int i = 0; i < count; i++) {
                fw.write(employees[i].toFileString() + "\n");
            }

            fw.close();
            System.out.println("Data saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}