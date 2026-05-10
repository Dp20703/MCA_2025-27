import java.io.*;
import java.util.*;

// Custom Exception for Invalid Marks
class InvalidMarksException extends Exception {
    public InvalidMarksException(String message) {
        super(message);
    }
}

// Student Class
class Student {
    int id;
    String name;
    double marks;

    // Constructor
    public Student(int id, String name, double marks) throws InvalidMarksException {
        if (marks < 0 || marks > 100) {
            throw new InvalidMarksException("Marks must be between 0 and 100!");
        }
        this.id = id;
        this.name = name;
        this.marks = marks;
    }

    // Method to calculate grade
    public String getGrade() {
        if (marks >= 90)
            return "A";
        else if (marks >= 75)
            return "B";
        else if (marks >= 60)
            return "C";
        else if (marks >= 50)
            return "D";
        else
            return "F";
    }

    // Display student info
    public void display() {
        System.out.println("ID: " + id + ", Name: " + name +
                ", Marks: " + marks + ", Grade: " + getGrade());
    }

    // Convert to file format
    public String toFileString() {
        return id + "," + name + "," + marks;
    }
}

public class P1 {
    static Scanner sc = new Scanner(System.in);
    static Student[] students = new Student[100];
    static int count = 0;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== Student Management Menu =====");
            System.out.println("1. Add Student");
            System.out.println("2. Display Students");
            System.out.println("3. Save to File");
            System.out.println("4. Load from File");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    displayStudents();
                    break;
                case 3:
                    saveToFile();
                    break;
                case 4:
                    loadFromFile();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 5);
    }

    // Add Student
    static void addStudent() {
        try {
            System.out.print("Enter ID: ");
            int id = sc.nextInt();
            sc.nextLine(); // clear buffer

            System.out.print("Enter Name: ");
            String name = sc.nextLine();

            System.out.print("Enter Marks: ");
            double marks = sc.nextDouble();

            students[count++] = new Student(id, name, marks);
            System.out.println("Student added successfully!");

        } catch (InvalidMarksException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    // Display Students
    static void displayStudents() {
        if (count == 0) {
            System.out.println("No records found!");
            return;
        }

        for (int i = 0; i < count; i++) {
            students[i].display();
        }
    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("students.txt");

            for (int i = 0; i < count; i++) {
                fw.write(students[i].toFileString() + "\n");
            }

            fw.close();
            System.out.println("Data saved to file!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }

    // Load from File
    static void loadFromFile() {
        try {
            BufferedReader br = new BufferedReader(new FileReader("students.txt"));
            String line;

            count = 0; // reset

            while ((line = br.readLine()) != null) {
                String[] data = line.split(",");

                int id = Integer.parseInt(data[0]);
                String name = data[1];
                double marks = Double.parseDouble(data[2]);

                students[count++] = new Student(id, name, marks);
            }

            br.close();
            System.out.println("Data loaded successfully!");

        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}