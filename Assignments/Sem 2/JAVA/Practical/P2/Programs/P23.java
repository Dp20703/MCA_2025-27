// Unit-9
// Q3

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class P23 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Create list of integers
        List<Integer> numbers = Arrays.asList(
                10, 20, 30, 40, 50, 15, 25);

        int choice;

        do {

            System.out.println(
                    "\n===== Aggregate Operations =====");

            System.out.println(
                    "1. Find Sum of Elements");

            System.out.println(
                    "2. Find Maximum Element");

            System.out.println(
                    "3. Store Even Numbers into New List");

            System.out.println(
                    "4. Exit");

            System.out.print(
                    "Enter your choice: ");

            choice = sc.nextInt();

            switch (choice) {

                // Find Sum
                case 1:

                    int sum = numbers.stream()

                            .reduce(0, (a, b) -> a + b);

                    System.out.println(
                            "\nSum of Elements: "
                                    + sum);

                    break;

                // Find Maximum Element
                case 2:

                    int max = numbers.stream()

                            .max(Integer::compare)

                            .get();

                    System.out.println(
                            "\nMaximum Element: "
                                    + max);

                    break;

                // Store Even Numbers into New List
                case 3:

                    List<Integer> evenList = numbers.stream()

                            .filter(
                                    n -> n % 2 == 0)

                            .collect(
                                    Collectors.toList());

                    System.out.println(
                            "\nEven Numbers List:");

                    System.out.println(evenList);

                    break;

                // Exit
                case 4:

                    System.out.println(
                            "Exiting Program...");

                    break;

                default:

                    System.out.println(
                            "Invalid Choice!");
            }

        } while (choice != 4);

        sc.close();
    }
}
