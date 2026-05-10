// Unit-8
// Q2

import java.util.*;

// Order Class
class Order {

    int id;
    String itemName;
    double amount;

    // Constructor
    public Order(int id, String itemName, double amount) {
        this.id = id;
        this.itemName = itemName;
        this.amount = amount;
    }

    // Display Order Details
    @Override
    public String toString() {
        return "ID: " + id +
                ", Item Name: " + itemName +
                ", Amount: " + amount;
    }
}

public class P7 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // List to store orders
        List<Order> orders = new ArrayList<>();

        int choice;

        do {

            System.out.println("\n===== Order Management System =====");
            System.out.println("1. Add Order");
            System.out.println("2. Display All Orders");
            System.out.println("3. Search Order by Item Name");
            System.out.println("4. Update Order Details");
            System.out.println("5. Remove Order by Index");
            System.out.println("6. Sort Orders by Amount");
            System.out.println("7. Exit");
            System.out.print("Enter your choice: ");

            choice = sc.nextInt();

            switch (choice) {

                // Add Order
                case 1:

                    System.out.print("Enter Order ID: ");
                    int id = sc.nextInt();

                    sc.nextLine(); // Clear buffer

                    System.out.print("Enter Item Name: ");
                    String itemName = sc.nextLine();

                    System.out.print("Enter Amount: ");
                    double amount = sc.nextDouble();

                    orders.add(
                            new Order(id, itemName, amount));

                    System.out.println(
                            "Order Added Successfully!");

                    break;

                // Display All Orders
                case 2:

                    if (orders.isEmpty()) {

                        System.out.println("No orders found.");

                    } else {

                        System.out.println(
                                "\n--- Order List ---");

                        for (int i = 0; i < orders.size(); i++) {

                            System.out.println(
                                    "Index " + i + " -> "
                                            + orders.get(i));
                        }
                    }

                    break;

                // Search Order by Item Name
                case 3:

                    sc.nextLine(); // Clear buffer

                    System.out.print(
                            "Enter Item Name to Search: ");

                    String searchItem = sc.nextLine();

                    boolean found = false;

                    for (Order o : orders) {

                        if (o.itemName.equalsIgnoreCase(
                                searchItem)) {

                            System.out.println(
                                    "Order Found: " + o);

                            found = true;
                        }
                    }

                    if (!found) {

                        System.out.println(
                                "Order Not Found.");
                    }

                    break;

                // Update Order Details
                case 4:

                    System.out.print(
                            "Enter Index to Update: ");

                    int updateIndex = sc.nextInt();

                    if (updateIndex >= 0 &&
                            updateIndex < orders.size()) {

                        System.out.print("Enter New ID: ");
                        int newId = sc.nextInt();

                        sc.nextLine(); // Clear buffer

                        System.out.print(
                                "Enter New Item Name: ");

                        String newItemName = sc.nextLine();

                        System.out.print(
                                "Enter New Amount: ");

                        double newAmount = sc.nextDouble();

                        orders.set(
                                updateIndex,
                                new Order(
                                        newId,
                                        newItemName,
                                        newAmount));

                        System.out.println(
                                "Order Updated Successfully!");

                    } else {

                        System.out.println(
                                "Invalid Index.");
                    }

                    break;

                // Remove Order by Index
                case 5:

                    System.out.print(
                            "Enter Index to Remove: ");

                    int removeIndex = sc.nextInt();

                    if (removeIndex >= 0 &&
                            removeIndex < orders.size()) {

                        orders.remove(removeIndex);

                        System.out.println(
                                "Order Removed Successfully!");

                    } else {

                        System.out.println(
                                "Invalid Index.");
                    }

                    break;

                // Sort Orders by Amount
                case 6:

                    Collections.sort(
                            orders,
                            new Comparator<Order>() {

                                @Override
                                public int compare(
                                        Order o1,
                                        Order o2) {

                                    return Double.compare(
                                            o1.amount,
                                            o2.amount);
                                }
                            });

                    System.out.println(
                            "Orders Sorted by Amount.");

                    break;

                // Exit
                case 7:

                    System.out.println(
                            "Exiting Program...");

                    break;

                default:

                    System.out.println(
                            "Invalid Choice!");
            }

        } while (choice != 7);

        sc.close();
    }
}
