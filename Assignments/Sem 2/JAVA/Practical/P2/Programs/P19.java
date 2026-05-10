// Unit-8
// Q14

import java.util.Scanner;

public class P19 {

    public static void main(String[] args) {

        // Create Scanner object
        Scanner sc = new Scanner(System.in);

        // Accept customer name
        System.out.print("Enter Customer Name: ");
        String name = sc.nextLine();

        // Accept customer age
        System.out.print("Enter Customer Age: ");
        int age = sc.nextInt();

        // Display confirmation message
        System.out.println(
                "\nCustomer "
                        + name
                        + ", age "
                        + age
                        + ", registered successfully.");

        // Close scanner
        sc.close();
    }
}
