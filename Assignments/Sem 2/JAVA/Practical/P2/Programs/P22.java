// Unit-9
// Q2

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class P22 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Create list of names
        List<String> names = Arrays.asList(
                "Darshan",
                "Sahil",
                "Ravi",
                "Simran",
                "Amit",
                "Sneha"
        );

        int choice;

        do {

            System.out.println(
                    "\n===== String Stream Operations ====="
            );

            System.out.println(
                    "1. Display Names Starting with 'S'"
            );

            System.out.println(
                    "2. Convert All Names to Uppercase"
            );

            System.out.println(
                    "3. Sort Names"
            );

            System.out.println(
                    "4. Count Total Names"
            );

            System.out.println(
                    "5. Exit"
            );

            System.out.print(
                    "Enter your choice: "
            );

            choice = sc.nextInt();

            switch (choice) {

                // Names Starting with S
                case 1:

                    System.out.println(
                            "\nNames Starting with 'S':"
                    );

                    names.stream()

                            .filter(name ->
                                    name.startsWith("S"))

                            .forEach(System.out::println);

                    break;

                // Convert to Uppercase
                case 2:

                    System.out.println(
                            "\nNames in Uppercase:"
                    );

                    names.stream()

                            .map(String::toUpperCase)

                            .forEach(System.out::println);

                    break;

                // Sort Names
                case 3:

                    System.out.println(
                            "\nSorted Names:"
                    );

                    names.stream()

                            .sorted()

                            .forEach(System.out::println);

                    break;

                // Count Total Names
                case 4:

                    long total = names.stream()

                                      .count();

                    System.out.println(
                            "\nTotal Names: "
                            + total
                    );

                    break;

                // Exit
                case 5:

                    System.out.println(
                            "Exiting Program..."
                    );

                    break;

                default:

                    System.out.println(
                            "Invalid Choice!"
                    );
            }

        } while (choice != 5);

        sc.close();
    }
}
