// Unit-9
// Q1

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class P21 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Create list of integers
        List<Integer> numbers = Arrays.asList(10, 15, 20, 25, 30, 35);

        int choice;

        do {

            System.out.println(
                    "\n===== Stream API Program =====");

            System.out.println(
                    "1. Display Even Numbers");

            System.out.println(
                    "2. Display Odd Numbers");

            System.out.println(
                    "3. Display Square of Each Number");

            System.out.println(
                    "4. Exit");

            System.out.print(
                    "Enter your choice: ");

            choice = sc.nextInt();

            switch (choice) {

                // Display Even Numbers
                case 1:

                    System.out.println(
                            "\nEven Numbers:");

                    numbers.stream()

                            .filter(n -> n % 2 == 0)

                            .forEach(System.out::println);

                    break;

                // Display Odd Numbers
                case 2:

                    System.out.println(
                            "\nOdd Numbers:");

                    numbers.stream()

                            .filter(n -> n % 2 != 0)

                            .forEach(System.out::println);

                    break;

                // Display Squares
                case 3:

                    System.out.println(
                            "\nSquare of Each Number:");

                    numbers.stream()

                            .map(n -> n * n)

                            .forEach(System.out::println);

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