import java.io.*;
import java.util.*;

import javax.annotation.processing.FilerException;

class InvalidMarksException extends Exception {
    InvalidMarksException(String msg) {
        super(msg);
    }
}

// class student
class Student {
    int id;
    String name;
    double marks;

    Student(int id, String name, double marks) throws InvalidMarksException {
        if (marks < 0 || marks > 100) {
            throw new InvalidMarksException("Marks must be between 0 and 100!");
        }
        this.id = id;
        this.name = name;
        this.marks = marks;
    }

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

    public void display() {
        System.out.println("Id:" + id + ", Name:" + name + ", Marks:" + marks + ". Grade: " + getGrade());
    }

    public String toFileString() {
        return id + "," + name + "," + marks;
    }

}

public class Demo {
    static Student[] students = new Student[100];
    static Scanner sc = new Scanner(System.in);
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

            System.out.println("Enter choice:");
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
                    break;
            }

        } while (choice != 5);
    }

    static void addStudent() {
        try {
            System.out.println("Enter id:");
            int id = sc.nextInt();
            sc.nextLine();

            System.out.println("Enter name:");
            String name = sc.nextLine();

            System.out.println("Enter marks:");
            double marks = sc.nextDouble();

            students[count++] = new Student(id, name, marks);
            System.out.println("Student added...");
        } catch (InvalidMarksException e) {
            System.out.println("Error:" + e.getMessage());
        }
    }

    static void displayStudents() {
        if (count == 0) {
            System.out.println("No students");
            return;
        }
        for (int index = 0; index < count; index++) {
            students[index].display();
        }
    }

    // save to file
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("dp.txt");
            for (int index = 0; index < count; index++) {
                fw.write(students[index].toFileString() + "\n");
            }
            fw.close();
            System.out.println("Data saved to file");

        } catch (IOException e) {
            System.out.println("file error:" + e.getMessage());
        }
    }

    // load from file
    static void loadFromFile() {
        try {
            BufferedReader br = new BufferedReader(new FileReader("dp.txt"));
            String line;
            count = 0;
            while ((line = br.readLine()) != null) {
                String[] data = line.split(",");

                int id = Integer.parseInt(data[0]);
                String name = data[1];
                double marks = Double.parseDouble(data[2]);

                students[count++] = new Student(id, name, marks);
            }
            br.close();
            System.out.println("Data loaded ....");
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
