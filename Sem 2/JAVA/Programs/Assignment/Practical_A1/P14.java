import java.io.*;
import java.util.*;

// FoodItem Class
class FoodItem {
    String name;
    double price;

    public FoodItem(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public void display() {
        System.out.println(name + " - ₹" + price);
    }
}

// Main Class
public class P14 {
    static Scanner sc = new Scanner(System.in);

    // Menu Items
    static FoodItem[] menu = {
            new FoodItem("Pizza", 250),
            new FoodItem("Burger", 120),
            new FoodItem("Pasta", 180),
            new FoodItem("Sandwich", 100)
    };

    static FoodItem[] orders = new FoodItem[100];
    static int count = 0;
    static double total = 0;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== Restaurant Menu =====");
            System.out.println("1. Display Menu");
            System.out.println("2. Place Order");
            System.out.println("3. Generate Bill");
            System.out.println("4. Save Order");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    displayMenu();
                    break;

                case 2:
                    placeOrder();
                    break;

                case 3:
                    generateBill();
                    break;

                case 4:
                    saveToFile();
                    break;

                case 5:
                    System.out.println("Thank you! Visit again.");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 5);
    }

    // Display Menu
    static void displayMenu() {
        System.out.println("\n--- Menu ---");
        for (int i = 0; i < menu.length; i++) {
            System.out.print((i + 1) + ". ");
            menu[i].display();
        }
    }

    // Place Order
    static void placeOrder() {
        displayMenu();
        System.out.print("Enter item number: ");
        int item = sc.nextInt();

        if (item < 1 || item > menu.length) {
            System.out.println("Invalid item!");
            return;
        }

        orders[count++] = menu[item - 1];
        total += menu[item - 1].price;

        System.out.println("Item added to order!");
    }

    // Generate Bill
    static void generateBill() {
        if (count == 0) {
            System.out.println("No orders placed!");
            return;
        }

        System.out.println("\n--- Bill ---");
        for (int i = 0; i < count; i++) {
            orders[i].display();
        }

        System.out.println("Total Amount = ₹" + total);
    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("orders.txt");

            for (int i = 0; i < count; i++) {
                fw.write(orders[i].name + "," + orders[i].price + "\n");
            }

            fw.write("Total: ₹" + total);

            fw.close();
            System.out.println("Order saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}