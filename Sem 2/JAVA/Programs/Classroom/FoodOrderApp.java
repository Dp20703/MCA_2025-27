
//Object-Oriented Food Order System
public class Food {

    private String foodName;
    private double price;

    // Constructor
    public Food(String foodName, double price) {
        this.foodName = foodName;
        this.price = price;
    }

    // Getter Methods
    public String getFoodName() {
        return foodName;
    }

    public double getPrice() {
        return price;
    }

    // Display Method
    public void display() {
        System.out.println(foodName + " - ₹" + price);
    }
}

import java.util.ArrayList;
import java.util.Scanner;

public class FoodOrderApp {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        ArrayList<Food> orders = new ArrayList<>();

        while (true) {
            System.out.println("\n------ FOOD ORDER MENU ------");
            System.out.println("1. Add Order");
            System.out.println("2. Display Orders");
            System.out.println("3. Remove Order");
            System.out.println("4. Calculate Total Bill");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {

                case 1:
                    System.out.print("Enter Food Name: ");
                    String name = sc.nextLine();

                    System.out.print("Enter Price: ");
                    double price = sc.nextDouble();

                    Food f = new Food(name, price);
                    orders.add(f);

                    System.out.println("Order Added Successfully!");
                    break;

                case 2:
                    if (orders.isEmpty()) {
                        System.out.println("No Orders Found!");
                    } else {
                        System.out.println("\n--- Order List ---");
                        for (int i = 0; i < orders.size(); i++) {
                            System.out.print((i + 1) + ". ");
                            orders.get(i).display();
                        }
                    }
                    break;

                case 3:
                    System.out.print("Enter Order Number to Remove: ");
                    int index = sc.nextInt() - 1;

                    if (index >= 0 && index < orders.size()) {
                        orders.remove(index);
                        System.out.println("Order Removed Successfully!");
                    } else {
                        System.out.println("Invalid Order Number!");
                    }
                    break;

                case 4:
                    double total = 0;
                    for (Food item : orders) {
                        total += item.getPrice();
                    }
                    System.out.println("Total Bill = ₹" + total);
                    break;

                case 5:
                    System.out.println("Thank You! Visit Again.");
                    return;

                default:
                    System.out.println("Invalid Choice!");
            }
        }
    }
}
