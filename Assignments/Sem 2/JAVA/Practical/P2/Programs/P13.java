// Unit-8
// Q8

import java.util.Map;
import java.util.TreeMap;

public class P13 {

    public static void main(String[] args) {

        // Create TreeMap
        TreeMap<Integer, String> employees = new TreeMap<>();

        // Add entries
        employees.put(104, "Darshan");
        employees.put(101, "Amit");
        employees.put(103, "Ravi");
        employees.put(102, "Bhavik");

        // Display entries in sorted order
        System.out.println(
                "Employee Details (Sorted by ID):");

        for (Map.Entry<Integer, String> entry : employees.entrySet()) {

            System.out.println(
                    "Employee ID: "
                            + entry.getKey()
                            + ", Employee Name: "
                            + entry.getValue());
        }
    }
}