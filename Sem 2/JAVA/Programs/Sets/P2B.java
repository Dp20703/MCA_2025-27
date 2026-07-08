package Sets;
import java.util.*;

class Order {
    int id;
    String itemName;
    double amount;

    // Constructor
    Order(int id, String itemName, double amount) {
        this.id = id;
        this.itemName = itemName;
        this.amount = amount;
    }

    // Display Order
    void display() {
        System.out.println("ID : " + id);
        System.out.println("Item Name : " + itemName);
        System.out.println("Amount : " + amount);
        System.out.println("---------------------");
    }
}

public class P2B {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        List<Order> list = new ArrayList<>();

        while (true) {

            System.out.println("\n1. Add Order");
            System.out.println("2. Display Orders");
            System.out.println("3. Search Order by Item Name");
            System.out.println("4. Update Order");
            System.out.println("5. Remove Order by Index");
            System.out.println("6. Sort Orders by Amount");
            System.out.println("7. Exit");

            System.out.print("Enter Choice : ");
            int choice = sc.nextInt();

            switch (choice) {

                // Add Order
                case 1:

                    System.out.print("Enter ID : ");
                    int id = sc.nextInt();

                    sc.nextLine();

                    System.out.print("Enter Item Name : ");
                    String item = sc.nextLine();

                    System.out.print("Enter Amount : ");
                    double amount = sc.nextDouble();

                    list.add(new Order(id, item, amount));

                    System.out.println("Order Added Successfully!");
                    break;

                // Display Orders
                case 2:

                    if (list.isEmpty()) {
                        System.out.println("No Orders Found!");
                    } else {
                        for (Order o : list) {
                            o.display();
                        }
                    }

                    break;

                // Search Order
                case 3:

                    sc.nextLine();

                    System.out.print("Enter Item Name : ");
                    String search = sc.nextLine();

                    boolean found = false;

                    for (Order o : list) {
                        if (o.itemName.equalsIgnoreCase(search)) {
                            o.display();
                            found = true;
                        }
                    }

                    if (!found)
                        System.out.println("Order Not Found!");

                    break;

                // Update Order
                case 4:

                    System.out.print("Enter Index : ");
                    int index = sc.nextInt();

                    if (index >= 0 && index < list.size()) {

                        System.out.print("Enter New ID : ");
                        list.get(index).id = sc.nextInt();

                        sc.nextLine();

                        System.out.print("Enter New Item Name : ");
                        list.get(index).itemName = sc.nextLine();

                        System.out.print("Enter New Amount : ");
                        list.get(index).amount = sc.nextDouble();

                        System.out.println("Order Updated!");

                    } else {
                        System.out.println("Invalid Index!");
                    }

                    break;

                // Remove Order
                case 5:

                    System.out.print("Enter Index : ");
                    int remove = sc.nextInt();

                    if (remove >= 0 && remove < list.size()) {
                        list.remove(remove);
                        System.out.println("Order Removed!");
                    } else {
                        System.out.println("Invalid Index!");
                    }

                    break;

                // Sort Orders
                case 6:

                    Collections.sort(list, new Comparator<Order>() {
                        public int compare(Order o1, Order o2) {
                            return Double.compare(o1.amount, o2.amount);
                        }
                    });

                    System.out.println("Orders Sorted by Amount!");

                    break;

                // Exit
                case 7:

                    System.out.println("Thank You!");
                    System.exit(0);

                default:

                    System.out.println("Invalid Choice!");
            }
        }
    }
}