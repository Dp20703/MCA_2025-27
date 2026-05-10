// Unit-8
// Q3

import java.util.HashSet;

public class P8 {

    public static void main(String[] args) {

        // Create HashSet
        HashSet<String> studentNames = new HashSet<>();

        // Adding student names
        studentNames.add("Darshan");
        studentNames.add("Amit");
        studentNames.add("Ravi");
        studentNames.add("Bhavik");

        // Adding duplicate names
        studentNames.add("Darshan");
        studentNames.add("Amit");

        // Display all names
        System.out.println("Student Names in HashSet:");

        for (String name : studentNames) {
            System.out.println(name);
        }

        // Display total number of names
        System.out.println(
                "\nTotal Unique Names: "
                        + studentNames.size());

        // Showing duplicate entries are not stored
        System.out.println(
                "\nDuplicate names are automatically removed in HashSet.");
    }
}