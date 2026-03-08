//Menu Driven Food Order Program Using ARRAY
import java.util.Scanner;

public class FoodOrderArray {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String[] foodName = new String[5];
        double[] price = new double[5];
        int count = 0;

        while (true) {
            System.out.println("\n---- FOOD ORDER MENU (ARRAY) ----");
            System.out.println("1. Add Order");
            System.out.println("2. Display Orders");
            System.out.println("3. Exit");
            System.out.print("Enter choice: ");
            int choice = sc.nextInt();
            sc.nextLine();  // consume newline

            switch (choice) {

                case 1:
                    if (count < 5) {
                        System.out.print("Enter Food Name: ");
                        foodName[count] = sc.nextLine();

                        System.out.print("Enter Price: ");
                        price[count] = sc.nextDouble();

                        count++;
                        System.out.println("Order Added Successfully!");
                    } else {
                        System.out.println("Order limit reached (Max 5)");
                    }
                    break;

                case 2:
                    System.out.println("\n--- Order List ---");
                    for (int i = 0; i < count; i++) {
                        System.out.println((i + 1) + ". " + foodName[i] + " - ₹" + price[i]);
                    }
                    break;

                case 3:
                    System.out.println("Thank You!");
                    return;

                default:
                    System.out.println("Invalid Choice!");
            }
        }
    }
}
