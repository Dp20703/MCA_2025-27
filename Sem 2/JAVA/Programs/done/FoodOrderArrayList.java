//Menu Driven Food Order Program Using ARRAYLIST
import java.util.ArrayList;
import java.util.Scanner;

public class FoodOrderArrayList {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        ArrayList<String> foodName = new ArrayList<>();
        ArrayList<Double> price = new ArrayList<>();

        while (true) {
            System.out.println("\n---- FOOD ORDER MENU (ARRAYLIST) ----");
            System.out.println("1. Add Order");
            System.out.println("2. Display Orders");
            System.out.println("3. Remove Order");
            System.out.println("4. Exit");
            System.out.print("Enter choice: ");
            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {

                case 1:
                    System.out.print("Enter Food Name: ");
                    foodName.add(sc.nextLine());

                    System.out.print("Enter Price: ");
                    price.add(sc.nextDouble());

                    System.out.println("Order Added Successfully!");
                    break;

                case 2:
                    System.out.println("\n--- Order List ---");
                    for (int i = 0; i < foodName.size(); i++) {
                        System.out.println((i + 1) + ". " + foodName.get(i) + " - ₹" + price.get(i));
                    }
                    break;

                case 3:
                    System.out.print("Enter order number to remove: ");
                    int index = sc.nextInt() - 1;

                    if (index >= 0 && index < foodName.size()) {
                        foodName.remove(index);
                        price.remove(index);
                        System.out.println("Order Removed!");
                    } else {
                        System.out.println("Invalid Order Number!");
                    }
                    break;

                case 4:
                    System.out.println("Thank You!");
                    return;

                default:
                    System.out.println("Invalid Choice!");
            }
        }
    }
}

