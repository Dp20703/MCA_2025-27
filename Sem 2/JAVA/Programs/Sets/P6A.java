package Sets;
import java.util.*;

// Functional Interface
interface Operation {
    int calculate(int a, int b);
}

public class P6A {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        while (true) {

            System.out.println("\n1. Addition");
            System.out.println("2. Subtraction");
            System.out.println("3. Multiplication");
            System.out.println("4. Division");
            System.out.println("5. Exit");

            System.out.print("Enter Choice : ");
            int choice = sc.nextInt();

            System.out.print("Enter First Number : ");
            int a = sc.nextInt();

            System.out.print("Enter Second Number : ");
            int b = sc.nextInt();

            Operation op;

            try {

                switch (choice) {

                    case 1:
                        op = (x, y) -> x + y;
                        System.out.println("Answer = " + op.calculate(a, b));
                        break;

                    case 2:
                        op = (x, y) -> x - y;
                        System.out.println("Answer = " + op.calculate(a, b));
                        break;

                    case 3:
                        op = (x, y) -> x * y;
                        System.out.println("Answer = " + op.calculate(a, b));
                        break;

                    case 4:

                        if (b == 0)
                            throw new ArithmeticException("Cannot divide by zero!");

                        op = (x, y) -> x / y;
                        System.out.println("Answer = " + op.calculate(a, b));
                        break;

                    case 5:
                        System.out.println("Thank You!");
                        System.exit(0);

                    default:
                        System.out.println("Invalid Choice!");
                }

            } catch (ArithmeticException e) {
                System.out.println(e.getMessage());
            }

        }

    }
}