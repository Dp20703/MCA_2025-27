// Unit-8
// Q6

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class P11 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Create HashMap
        HashMap<String, String> phoneBook = new HashMap<>();

        // Add multiple entries
        phoneBook.put("Darshan", "9876543210");
        phoneBook.put("Amit", "9123456780");
        phoneBook.put("Ravi", "9988776655");
        phoneBook.put("Bhavik", "9090909090");

        // Display all entries
        System.out.println("Phone Directory:");

        for (Map.Entry<String, String> entry : phoneBook.entrySet()) {

            System.out.println(
                    "Name: " + entry.getKey()
                            + ", Phone: "
                            + entry.getValue());
        }

        // Search phone number using name
        System.out.print(
                "\nEnter Name to Search: ");

        String searchName = sc.nextLine();

        if (phoneBook.containsKey(searchName)) {

            System.out.println(
                    "Phone Number: "
                            + phoneBook.get(searchName));

        } else {

            System.out.println(
                    "Name not found in directory.");
        }

        sc.close();
    }
}
