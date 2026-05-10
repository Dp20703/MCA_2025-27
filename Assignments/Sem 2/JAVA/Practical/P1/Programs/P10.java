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
    String courseName;

    public Course(int id, String courseName) {
        this.id = id;
        this.courseName = courseName;
    }
}

// Registration Class
class Registration {
    Student student;
    Course course;

    public Registration(Student student, Course course) {
        this.student = student;
        this.course = course;
    }

    public void display() {
        System.out.println("Student: " + student.name +
                " -> Course: " + course.courseName);
    }

    public String toFileString() {
        return student.id + "," + student.name + "," +
                course.id + "," + course.courseName;
    }
}

// Main Class
public class P10 {
    static Scanner sc = new Scanner(System.in);

    static Student[] students = new Student[100];
    static Course[] courses = new Course[100];
    static Registration[] regs = new Registration[100];

    static int sCount = 0, cCount = 0, rCount = 0;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== University Menu =====");
            System.out.println("1. Add Student");
            System.out.println("2. Add Course");
            System.out.println("3. Register Student");
            System.out.println("4. Display Registrations");
            System.out.println("5. Save to File");
            System.out.println("6. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            try {
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
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
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

    // Find Student
    static Student findStudent(int id) {
        for (int i = 0; i < sCount; i++) {
            if (students[i].id == id)
                return students[i];
        }
        return null;
    }

    // Find Course
    static Course findCourse(int id) {
        for (int i = 0; i < cCount; i++) {
            if (courses[i].id == id)
                return courses[i];
        }
        return null;
    }

    // Register Student
    static void registerStudent() throws Exception {
        System.out.print("Enter Student ID: ");
        int sid = sc.nextInt();

        System.out.print("Enter Course ID: ");
        int cid = sc.nextInt();

        Student s = findStudent(sid);
        Course c = findCourse(cid);

        if (s == null || c == null) {
            throw new Exception("Invalid Student or Course ID!");
        }

        regs[rCount++] = new Registration(s, c);
        System.out.println("Registration successful!");
    }

    // Display Registrations
    static void displayRegistrations() {
        if (rCount == 0) {
            System.out.println("No registrations found!");
            return;
        }

        for (int i = 0; i < rCount; i++) {
            regs[i].display();
        }
    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("registrations.txt");

            for (int i = 0; i < rCount; i++) {
                fw.write(regs[i].toFileString() + "\n");
            }

            fw.close();
            System.out.println("Data saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}