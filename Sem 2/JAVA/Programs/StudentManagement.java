import java.io.*;
import java.util.*;

// custom exception
class InvalidMarksException extends Exception {
    InvalidMarksException(String message) {
        super(message);
    }
}

// Student Class
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

    // cal grade
    String getGrade() {
        if (marks >= 80)
            return "A";
        else if (marks >= 60)
            return "B";
        else if (marks >= 40)
            return "C";
        else
            return "Fail";
    }

    // Display Student
    void display() {
        System.out.println("ID : " + id);
        System.out.println("Name : " + name);
        System.out.println("Marks : " + marks);
        System.out.println("Grade : " + getGrade());
        System.out.println("----------------------");
    }

}

public class StudentManagement {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Student students[] = new Student[10];
        int count = 0;

        while (true) {
            System.out.println("\n1. Add Student");
            System.out.println("2. Display Students");
            System.out.println("3. Save to File");
            System.out.println("4. Load from File");
            System.out.println("5. Exit");

            System.out.print("Enter Choice : ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    try {

                        System.out.print("Enter ID : ");
                        int id = sc.nextInt();

                        sc.nextLine();

                        System.out.print("Enter Name : ");
                        String name = sc.nextLine();

                        System.out.print("Enter Marks : ");
                        int marks = sc.nextInt();

                        if (marks < 0 || marks > 100) {
                            throw new InvalidMarksException("Marks should be between 0 to 100");
                        }
                        students[count++] = new Student(id, name, marks);
                        System.out.println("Student added");
                    } catch (InvalidMarksException e) {
                        System.out.println(e.getMessage());

                    }
                    break;

                case 2:

                    if (count == 0) {
                        System.out.println("No Students Found!");
                    } else {

                        for (int i = 0; i < count; i++) {
                            students[i].display();
                        }
                    }

                    break;
                case 3:
                    try {
                        FileWriter fw = new FileWriter("student.txt");

                        for (int i = 0; i < count; i++) {
                            fw.write(students[i].id + ","
                                    + students[i].name + ","
                                    + students[i].marks + ","
                                    + students[i].getGrade() + "\n");
                        }
                        fw.close();
                        System.out.println("saved students");
                    } catch (Exception e) {
                        System.out.println(e);
                    }
                    break;
                case 4:
                    try {
                        BufferedReader br = new BufferedReader(new FileReader("student.txt"));
                        String line;

                        while ((line = br.readLine()) != null) {
                            String data[] = line.split(",");
                            System.out.println("ID : " + data[0]);
                            System.out.println("Name : " + data[1]);
                            System.out.println("Marks : " + data[2]);
                            System.out.println("Grade : " + data[3]);
                            System.out.println("--------------------");
                        }

                    } catch (Exception e) {
                        // TODO: handle exception
                        System.out.println(e);
                    }
                    break;
                case 5:

                    System.out.println("bye bye");
                    System.exit(0);

                default:
                    System.out.println("Invalid choice");
                    break;
            }

        }
    }
}
