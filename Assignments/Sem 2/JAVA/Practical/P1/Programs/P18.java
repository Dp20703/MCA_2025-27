import java.io.*;
import java.util.*;

// Custom Exception
class InvalidInputException extends Exception {
    public InvalidInputException(String msg) {
        super(msg);
    }
}

// Product Class
class Product {
    String name;
    int quantity;
    double price;

    public Product(String name, int quantity, double price) throws InvalidInputException {
        if (quantity <= 0 || price <= 0) {
            throw new InvalidInputException("Quantity and price must be positive!");
        }
        this.name = name;
        this.quantity = quantity;
        this.price = price;
    }

    public double getTotal() {
        return quantity * price;
    }

    public void display() {
        System.out.println("Product: " + name +
                ", Qty: " + quantity +
                ", Price: ₹" + price +
                ", Total: ₹" + getTotal());
    }

    public String toFileString() {
        return name + "," + quantity + "," + price + "," + getTotal();
    }
}

// Main Class
public class P18 {
    static Scanner sc = new Scanner(System.in);
    static Product[] cart = new Product[100];
    static int count = 0;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== Shopping Cart Menu =====");
            System.out.println("1. Add Product");
            System.out.println("2. Display Cart");
            System.out.println("3. Calculate Total");
            System.out.println("4. Save to File");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    addProduct();
                    break;

                case 2:
                    displayCart();
                    break;

                case 3:
                    calculateTotal();
                    break;

                case 4:
                    saveToFile();
                    break;

                case 5:
                    System.out.println("Thank you for shopping!");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 5);
    }

    // Add Product
    static void addProduct() {
        try {
            System.out.print("Enter Product Name: ");
            String name = sc.nextLine();

            System.out.print("Enter Quantity: ");
            int qty = sc.nextInt();

            System.out.print("Enter Price: ");
            double price = sc.nextDouble();
            sc.nextLine();

            cart[count++] = new Product(name, qty, price);
            System.out.println("Product added!");

        } catch (InvalidInputException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    // Display Cart
    static void displayCart() {
        if (count == 0) {
            System.out.println("Cart is empty!");
            return;
        }

        for (int i = 0; i < count; i++) {
            cart[i].display();
        }
    }

    // Calculate Total Bill
    static void calculateTotal() {
        double total = 0;

        for (int i = 0; i < count; i++) {
            total += cart[i].getTotal();
        }

        System.out.println("Total Purchase Amount = ₹" + total);
    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("cart.txt");

            for (int i = 0; i < count; i++) {
                fw.write(cart[i].toFileString() + "\n");
            }

            fw.close();
            System.out.println("Cart saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}