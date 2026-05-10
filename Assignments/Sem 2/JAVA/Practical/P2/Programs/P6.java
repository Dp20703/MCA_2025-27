// Unit-8
// Q1

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

    // Display Student Details
    @Override
    public String toString() {
        return "ID: " + id +
                ", Name: " + name +
                ", Marks: " + marks;
    }
}

public class P6 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // List to store student objects
        List<Student> students = new ArrayList<>();

        int choice;

        do {

            System.out.println("\n===== Student Management System =====");
            System.out.println("1. Add Student");
            System.out.println("2. Display All Students");
            System.out.println("3. Search Student by Name");
            System.out.println("4. Update Student using Index");
            System.out.println("5. Remove Student by Index");
            System.out.println("6. Sort Students by Marks");
            System.out.println("7. Exit");
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

                // Display All Students
                case 2:

                    if (students.isEmpty()) {
                        System.out.println("No students found.");
                    } else {

                        System.out.println("\n--- Student List ---");

                        for (int i = 0; i < students.size(); i++) {

                            System.out.println(
                                    "Index " + i + " -> "
                                            + students.get(i));
                        }
                    }

                    break;

                // Search Student by Name
                case 3:

                    sc.nextLine(); // Clear buffer

                    System.out.print("Enter Name to Search: ");
                    String searchName = sc.nextLine();

                    boolean found = false;

                    for (Student s : students) {

                        if (s.name.equalsIgnoreCase(searchName)) {

                            System.out.println(
                                    "Student Found: " + s);

                            found = true;
                        }
                    }

                    if (!found) {
                        System.out.println("Student Not Found.");
                    }

                    break;

                // Update Student using Index
                case 4:

                    System.out.print("Enter Index to Update: ");
                    int updateIndex = sc.nextInt();

                    if (updateIndex >= 0 &&
                            updateIndex < students.size()) {

                        System.out.print("Enter New ID: ");
                        int newId = sc.nextInt();

                        sc.nextLine(); // Clear buffer

                        System.out.print("Enter New Name: ");
                        String newName = sc.nextLine();

                        System.out.print("Enter New Marks: ");
                        double newMarks = sc.nextDouble();

                        students.set(
                                updateIndex,
                                new Student(
                                        newId,
                                        newName,
                                        newMarks));

                        System.out.println(
                                "Student Updated Successfully!");

                    } else {

                        System.out.println("Invalid Index.");
                    }

                    break;

                // Remove Student using Index
                case 5:

                    System.out.print("Enter Index to Remove: ");
                    int removeIndex = sc.nextInt();

                    if (removeIndex >= 0 &&
                            removeIndex < students.size()) {

                        students.remove(removeIndex);

                        System.out.println(
                                "Student Removed Successfully!");

                    } else {

                        System.out.println("Invalid Index.");
                    }

                    break;

                // Sort Students by Marks
                case 6:

                    Collections.sort(
                            students,
                            new Comparator<Student>() {

                                @Override
                                public int compare(
                                        Student s1,
                                        Student s2) {

                                    return Double.compare(
                                            s1.marks,
                                            s2.marks);
                                }
                            });

                    System.out.println(
                            "Students Sorted by Marks.");

                    break;

                // Exit
                case 7:

                    System.out.println("Exiting Program...");
                    break;

                default:

                    System.out.println("Invalid Choice!");
            }

        } while (choice != 7);

        sc.close();
    }
}
