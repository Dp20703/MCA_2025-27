package Sets;
import java.util.*;

class Student {
    int id;
    String name;
    int marks;

    // Constructor
    Student(int id, String name, int marks) {
        this.id = id;
        this.name = name;
        this.marks = marks;
    }

    // Display student
    void display() {
        System.out.println("ID : " + id);
        System.out.println("Name : " + name);
        System.out.println("Marks : " + marks);
        System.out.println("--------------------");
    }
}

public class P1B {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        List<Student> list = new ArrayList<>();

        while (true) {

            System.out.println("\n1. Add Student");
            System.out.println("2. Display Students");
            System.out.println("3. Search Student by Name");
            System.out.println("4. Update Student by Index");
            System.out.println("5. Remove Student by Index");
            System.out.println("6. Sort Students by Marks");
            System.out.println("7. Exit");

            System.out.print("Enter Choice : ");
            int choice = sc.nextInt();

            switch (choice) {

                // Add Student
                case 1:

                    System.out.print("Enter ID : ");
                    int id = sc.nextInt();

                    sc.nextLine();

                    System.out.print("Enter Name : ");
                    String name = sc.nextLine();

                    System.out.print("Enter Marks : ");
                    int marks = sc.nextInt();

                    list.add(new Student(id, name, marks));

                    System.out.println("Student Added Successfully!");
                    break;

                // Display Students
                case 2:

                    if (list.isEmpty()) {
                        System.out.println("No Students Found!");
                    } else {
                        for (Student s : list) {
                            s.display();
                        }
                    }

                    break; 

                // Search by Name
                case 3:

                    sc.nextLine();

                    System.out.print("Enter Name to Search : ");
                    String search = sc.nextLine();

                    boolean found = false;

                    for (Student s : list) {

                        if (s.name.equalsIgnoreCase(search)) {
                            s.display();
                            found = true;
                        }

                    }

                    if (!found)
                        System.out.println("Student Not Found!");

                    break;

                // Update Student
                case 4:

                    System.out.print("Enter Index : ");
                    int index = sc.nextInt();

                    if (index >= 0 && index < list.size()) {

                        System.out.print("Enter New ID : ");
                        list.get(index).id = sc.nextInt();

                        sc.nextLine();

                        System.out.print("Enter New Name : ");
                        list.get(index).name = sc.nextLine();

                        System.out.print("Enter New Marks : ");
                        list.get(index).marks = sc.nextInt();

                        System.out.println("Student Updated!");

                    } else {
                        System.out.println("Invalid Index!");
                    }

                    break;

                // Remove Student
                case 5:

                    System.out.print("Enter Index : ");
                    int remove = sc.nextInt();

                    if (remove >= 0 && remove < list.size()) {
                        list.remove(remove);
                        System.out.println("Student Removed!");
                    } else {
                        System.out.println("Invalid Index!");
                    }

                    break;

                // Sort by Marks
                case 6:

                    Collections.sort(list, new Comparator<Student>() {
                        public int compare(Student s1, Student s2) {
                            return s1.marks - s2.marks;
                        }
                    });

                    System.out.println("Students Sorted by Marks!");

                    break;

                // Exit
                case 7:

                    System.out.println("Thank You!");
                    System.exit(0);

                default:

                    System.out.println("Invalid Choice!");
            }
        }
    }
}
