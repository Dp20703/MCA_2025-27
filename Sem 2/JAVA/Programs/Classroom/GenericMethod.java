import java.util.*;

class GenericMethod {
    public static <T> void display(T data) {
        System.out.println("Value: " + data);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n--- Generic Method Menu ---");
            System.out.println("1. Integer");
            System.out.println("2. String");
            System.out.println("3. Double");
            System.out.println("4. Exit");

            choice = sc.nextInt();

            switch(choice) {
                case 1:
                    System.out.print("Enter Integer: ");
                    display(sc.nextInt());
                    break;

                case 2:
                    sc.nextLine();
                    System.out.print("Enter String: ");
                    display(sc.nextLine());
                    break;

                case 3:
                    System.out.print("Enter Double: ");
                    display(sc.nextDouble());
                    break;
            }
        } while(choice != 4);
    }
}