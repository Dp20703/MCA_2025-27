import java.io.*;
import java.util.*;

// Student Class
class Student {
    int id;
    String name;

    public Student(int id, String name) {
        this.id = id;
        this.name = name;
    }
}

// Course Class
class Course {
    int id;
    String name;

    public Course(int id, String name) {
        this.id = id;
        this.name = name;
    }
}

// Main Class
public class P17 {
    static Scanner sc = new Scanner(System.in);

    static Student[] students = new Student[100];
    static Course[] courses = new Course[100];

    static int sCount = 0, cCount = 0;

    // Store registrations as index mapping
    static int[][] registrations = new int[100][2];
    static int rCount = 0;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== Online Course Menu =====");
            System.out.println("1. Add Student");
            System.out.println("2. Add Course");
            System.out.println("3. Register Student");
            System.out.println("4. Display Registrations");
            System.out.println("5. Save to File");
            System.out.println("6. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    addStudent();
                    break;

                case 2:
                    addCourse();
                    break;

                case 3:
                    registerStudent();
                    break;

                case 4:
                    displayRegistrations();
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

    // Add Student
    static void addStudent() {
        System.out.print("Enter Student ID: ");
        int id = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Name: ");
        String name = sc.nextLine();

        students[sCount++] = new Student(id, name);
        System.out.println("Student added!");
    }

    // Add Course
    static void addCourse() {
        System.out.print("Enter Course ID: ");
        int id = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Course Name: ");
        String name = sc.nextLine();

        courses[cCount++] = new Course(id, name);
        System.out.println("Course added!");
    }

    // Find Student Index
    static int findStudent(int id) {
        for (int i = 0; i < sCount; i++) {
            if (students[i].id == id)
                return i;
        }
        return -1;
    }

    // Find Course Index
    static int findCourse(int id) {
        for (int i = 0; i < cCount; i++) {
            if (courses[i].id == id)
                return i;
        }
        return -1;
    }

    // Register Student
    static void registerStudent() {
        System.out.print("Enter Student ID: ");
        int sid = sc.nextInt();

        System.out.print("Enter Course ID: ");
        int cid = sc.nextInt();

        int sIndex = findStudent(sid);
        int cIndex = findCourse(cid);

        if (sIndex == -1 || cIndex == -1) {
            System.out.println("Invalid Student or Course ID!");
            return;
        }

        registrations[rCount][0] = sIndex;
        registrations[rCount][1] = cIndex;
        rCount++;

        System.out.println("Registration successful!");
    }

    // Display Registrations
    static void displayRegistrations() {
        if (rCount == 0) {
            System.out.println("No registrations!");
            return;
        }

        for (int i = 0; i < rCount; i++) {
            Student s = students[registrations[i][0]];
            Course c = courses[registrations[i][1]];

            System.out.println("Student: " + s.name +
                    " -> Course: " + c.name);
        }
    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("online_courses.txt");

            for (int i = 0; i < rCount; i++) {
                Student s = students[registrations[i][0]];
                Course c = courses[registrations[i][1]];

                fw.write(s.id + "," + s.name + "," +
                        c.id + "," + c.name + "\n");
            }

            fw.close();
            System.out.println("Data saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}