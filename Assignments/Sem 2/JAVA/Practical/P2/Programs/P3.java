// Unit-6
// Q1

import java.util.*;

// Student class implementing Comparable
class Student implements Comparable<Student> {

    int id;
    String name;
    double marks;

    // Constructor
    public Student(int id, String name, double marks) {
        this.id = id;
        this.name = name;
        this.marks = marks;
    }

    // Comparable -> Sort by ID
    @Override
    public int compareTo(Student s) {
        return this.id - s.id;
    }

    // Display Student Details
    @Override
    public String toString() {
        return "ID: " + id +
                ", Name: " + name +
                ", Marks: " + marks;
    }
}

// Comparator for Name
class NameComparator implements Comparator<Student> {

    @Override
    public int compare(Student s1, Student s2) {
        return s1.name.compareToIgnoreCase(s2.name);
    }
}

// Comparator for Marks
class MarksComparator implements Comparator<Student> {

    @Override
    public int compare(Student s1, Student s2) {
        return Double.compare(s1.marks, s2.marks);
    }
}

public class P3 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        ArrayList<Student> students = new ArrayList<>();

        int choice;

        do {
            System.out.println("\n===== Student Management System =====");
            System.out.println("1. Add Student");
            System.out.println("2. Display Students");
            System.out.println("3. Sort by ID");
            System.out.println("4. Sort by Name");
            System.out.println("5. Sort by Marks");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");

            choice = sc.nextInt();

            switch (choice) {

                // Add Student
                case 1:
                    System.out.print("Enter Student ID: ");
                    int id = sc.nextInt();

                    sc.nextLine(); // Clear buffer

                    System.out.print("Enter Student Name: ");
                    String name = sc.nextLine();

                    System.out.print("Enter Student Marks: ");
                    double marks = sc.nextDouble();

                    students.add(new Student(id, name, marks));

                    System.out.println("Student Added Successfully!");
                    break;

                // Display Students
                case 2:
                    System.out.println("\n--- Student Details ---");

                    if (students.isEmpty()) {
                        System.out.println("No students available.");
                    } else {
                        for (Student s : students) {
                            System.out.println(s);
                        }
                    }
                    break;

                // Sort by ID using Comparable
                case 3:
                    Collections.sort(students);

                    System.out.println("Students Sorted by ID.");
                    break;

                // Sort by Name using Comparator
                case 4:
                    Collections.sort(students, new NameComparator());

                    System.out.println("Students Sorted by Name.");
                    break;

                // Sort by Marks using Comparator
                case 5:
                    Collections.sort(students, new MarksComparator());

                    System.out.println("Students Sorted by Marks.");
                    break;

                // Exit
                case 6:
                    System.out.println("Exiting Program...");
                    break;

                default:
                    System.out.println("Invalid Choice!");
            }

        } while (choice != 6);

        sc.close();
    }
}
