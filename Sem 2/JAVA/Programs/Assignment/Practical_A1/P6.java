import java.util.*;

// Functional Interface
@FunctionalInterface
interface Operation {
    int calculate(int a, int b);
}

// Main Class
public class P6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n===== Calculator Menu =====");
            System.out.println("1. Addition");
            System.out.println("2. Subtraction");
            System.out.println("3. Multiplication");
            System.out.println("4. Division");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            if (choice == 5) {
                System.out.println("Exiting...");
                break;
            }

            System.out.print("Enter first number: ");
            int a = sc.nextInt();

            System.out.print("Enter second number: ");
            int b = sc.nextInt();

            Operation op = null;

            switch (choice) {
                case 1:
                    op = (x, y) -> x + y;
                    break;

                case 2:
                    op = (x, y) -> x - y;
                    break;

                case 3:
                    op = (x, y) -> x * y;
                    break;

                case 4:
                    op = (x, y) -> {
                        if (y == 0) {
                            throw new ArithmeticException("Cannot divide by zero!");
                        }
                        return x / y;
                    };
                    break;

                default:
                    System.out.println("Invalid choice!");
                    continue;
            }

            try {
                int result = op.calculate(a, b);
                System.out.println("Result = " + result);
            } catch (ArithmeticException e) {
                System.out.println("Error: " + e.getMessage());
            }

        } while (true);

        sc.close();
    }
}