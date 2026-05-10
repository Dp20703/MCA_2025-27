// Unit-5 
// Q1

import java.util.Scanner;

// Generic class Box
class Box<T> {
    private T value;

    // Method to store value
    public void setValue(T value) {
        this.value = value;
    }

    // Method to retrieve value
    public T getValue() {
        return value;
    }
}

public class P1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int dataTypeChoice;
        int menuChoice;

        System.out.println("===== Generic Box Program =====");
        System.out.println("Select Data Type:");
        System.out.println("1. Integer");
        System.out.println("2. String");
        System.out.println("3. Double");
        System.out.print("Enter your choice: ");

        dataTypeChoice = sc.nextInt();
        sc.nextLine(); // Clear buffer

        switch (dataTypeChoice) {

            // Integer Type
            case 1:
                Box<Integer> intBox = new Box<>();

                do {
                    System.out.println("\n--- Integer Box Menu ---");
                    System.out.println("1. Store Value");
                    System.out.println("2. Display Value");
                    System.out.println("3. Exit");
                    System.out.print("Enter your choice: ");

                    menuChoice = sc.nextInt();

                    switch (menuChoice) {
                        case 1:
                            System.out.print("Enter Integer Value: ");
                            int value = sc.nextInt();
                            intBox.setValue(value);
                            System.out.println("Value stored successfully.");
                            break;

                        case 2:
                            System.out.println("Stored Value: " + intBox.getValue());
                            break;

                        case 3:
                            System.out.println("Exiting Integer Box...");
                            break;

                        default:
                            System.out.println("Invalid choice!");
                    }

                } while (menuChoice != 3);
                break;

            // String Type
            case 2:
                Box<String> strBox = new Box<>();

                do {
                    System.out.println("\n--- String Box Menu ---");
                    System.out.println("1. Store Value");
                    System.out.println("2. Display Value");
                    System.out.println("3. Exit");
                    System.out.print("Enter your choice: ");

                    menuChoice = sc.nextInt();
                    sc.nextLine(); // Clear buffer

                    switch (menuChoice) {
                        case 1:
                            System.out.print("Enter String Value: ");
                            String text = sc.nextLine();
                            strBox.setValue(text);
                            System.out.println("Value stored successfully.");
                            break;

                        case 2:
                            System.out.println("Stored Value: " + strBox.getValue());
                            break;

                        case 3:
                            System.out.println("Exiting String Box...");
                            break;

                        default:
                            System.out.println("Invalid choice!");
                    }

                } while (menuChoice != 3);
                break;

            // Double Type
            case 3:
                Box<Double> doubleBox = new Box<>();

                do {
                    System.out.println("\n--- Double Box Menu ---");
                    System.out.println("1. Store Value");
                    System.out.println("2. Display Value");
                    System.out.println("3. Exit");
                    System.out.print("Enter your choice: ");

                    menuChoice = sc.nextInt();

                    switch (menuChoice) {
                        case 1:
                            System.out.print("Enter Double Value: ");
                            double d = sc.nextDouble();
                            doubleBox.setValue(d);
                            System.out.println("Value stored successfully.");
                            break;

                        case 2:
                            System.out.println("Stored Value: " + doubleBox.getValue());
                            break;

                        case 3:
                            System.out.println("Exiting Double Box...");
                            break;

                        default:
                            System.out.println("Invalid choice!");
                    }

                } while (menuChoice != 3);
                break;

            default:
                System.out.println("Invalid Data Type Choice!");
        }

        sc.close();
    }
}