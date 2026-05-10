// Unit-6
// Q2

import java.util.*;

// Student Class
class Student {

    int id;
    String name;
    double marks;

    // Constructor
    public Student(int id, String name, double marks) {
        this.id = id;
        this.name = name;
        this.marks = marks;
    }

    // Method to display student details
    @Override
    public String toString() {
        return "ID: " + id +
                ", Name: " + name +
                ", Marks: " + marks;
    }
}

// Comparator for Multilevel Sorting
class MultiLevelSort implements Comparator<Student> {

    @Override
    public int compare(Student s1, Student s2) {

        // First sort by marks
        int marksCompare = Double.compare(s1.marks, s2.marks);

        // If marks are different
        if (marksCompare != 0) {
            return marksCompare;
        }

        // If marks are same, sort by name
        return s1.name.compareToIgnoreCase(s2.name);
    }
}

public class P4 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        ArrayList<Student> students = new ArrayList<>();

        int choice;

        do {
            System.out.println("\n===== Student Sorting System =====");
            System.out.println("1. Add Student");
            System.out.println("2. Display Students");
            System.out.println("3. Sort Students");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");

            choice = sc.nextInt();

            switch (choice) {

                // Add Student
                case 1:

                    System.out.print("Enter Student ID: ");
                    int id = sc.nextInt();

                    sc.nextLine(); // Clear Buffer

                    System.out.print("Enter Student Name: ");
                    String name = sc.nextLine();

                    System.out.print("Enter Student Marks: ");
                    double marks = sc.nextDouble();

                    students.add(new Student(id, name, marks));

                    System.out.println("Student Added Successfully!");
                    break;

                // Display Students
                case 2:

                    if (students.isEmpty()) {
                        System.out.println("No students available.");
                    } else {

                        System.out.println("\n--- Student Details ---");

                        for (Student s : students) {
                            System.out.println(s);
                        }
                    }

                    break;

                // Sort Students
                case 3:

                    Collections.sort(students, new MultiLevelSort());

                    System.out.println(
                            "Students Sorted by Marks and Name.");

                    break;

                // Exit
                case 4:

                    System.out.println("Exiting Program...");
                    break;

                default:

                    System.out.println("Invalid Choice!");
            }

        } while (choice != 4);

        sc.close();
    }
}