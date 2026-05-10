// Unit-8
// Q20

import java.util.Random;
import java.util.Scanner;

public class P20 {

    public static void main(String[] args) {

        // Create Scanner object
        Scanner sc = new Scanner(System.in);

        // Create Random object
        Random random = new Random();

        // Ask user for OTP length
        System.out.print(
                "Enter OTP Length (4 or 6): ");

        int length = sc.nextInt();

        int otp;

        // Generate 4-digit OTP
        if (length == 4) {

            otp = 1000 + random.nextInt(9000);

            System.out.println(
                    "\nGenerated 4-Digit OTP: "
                            + otp);
        }

        // Generate 6-digit OTP
        else if (length == 6) {

            otp = 100000 +
                    random.nextInt(900000);

            System.out.println(
                    "\nGenerated 6-Digit OTP: "
                            + otp);
        }

        // Invalid input
        else {

            System.out.println(
                    "\nInvalid OTP Length!");
        }

        // Close scanner
        sc.close();
    }
}