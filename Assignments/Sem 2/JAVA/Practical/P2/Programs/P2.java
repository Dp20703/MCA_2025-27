// Unit-5 
// Q2

import java.util.*;

// Generic Container Class
class Container<T> {
    private T data;

    // Store data
    public void setData(T data) {
        this.data = data;
    }

    // Retrieve data
    public T getData() {
        return data;
    }
}

// Generic Pair Class with Multiple Type Parameters
class Pair<T, U> {
    private T first;
    private U second;

    public Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    public void displayPair() {
        System.out.println("First Value : " + first);
        System.out.println("Second Value: " + second);
    }
}

// Bounded Generic Class for Numeric Operations
class NumericOperations<T extends Number> {

    // Method to add two numbers
    public double add(T num1, T num2) {
        return num1.doubleValue() + num2.doubleValue();
    }
}

// Wildcard Example Class
class DisplayData {

    // Wildcard method to display list elements
    public static void displayList(List<?> list) {
        System.out.println("List Elements:");
        for (Object obj : list) {
            System.out.println(obj);
        }
    }
}

public class P2 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int choice;

        do {
            System.out.println("\n===== Generic Data Management System =====");
            System.out.println("1. Store and Retrieve Data using Generic Container");
            System.out.println("2. Store Paired Data using Multiple Type Parameters");
            System.out.println("3. Perform Arithmetic Operation using Bounded Generics");
            System.out.println("4. Display Collection using Wildcards");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");

            choice = sc.nextInt();

            switch (choice) {

                // Generic Container Example
                case 1:
                    System.out.println("\n--- Generic Container ---");
                    System.out.println("Choose Data Type:");
                    System.out.println("1. Integer");
                    System.out.println("2. String");
                    System.out.println("3. Double");
                    System.out.print("Enter choice: ");

                    int typeChoice = sc.nextInt();

                    switch (typeChoice) {

                        case 1:
                            Container<Integer> intContainer = new Container<>();
                            System.out.print("Enter Integer Value: ");
                            int intValue = sc.nextInt();
                            intContainer.setData(intValue);

                            System.out.println("Stored Value: " + intContainer.getData());
                            break;

                        case 2:
                            sc.nextLine();
                            Container<String> strContainer = new Container<>();
                            System.out.print("Enter String Value: ");
                            String strValue = sc.nextLine();
                            strContainer.setData(strValue);

                            System.out.println("Stored Value: " + strContainer.getData());
                            break;

                        case 3:
                            Container<Double> doubleContainer = new Container<>();
                            System.out.print("Enter Double Value: ");
                            double doubleValue = sc.nextDouble();
                            doubleContainer.setData(doubleValue);

                            System.out.println("Stored Value: " + doubleContainer.getData());
                            break;

                        default:
                            System.out.println("Invalid Data Type Choice!");
                    }
                    break;

                // Multiple Type Parameters Example
                case 2:
                    System.out.println("\n--- Pair Data Example ---");

                    System.out.print("Enter ID (Integer): ");
                    int id = sc.nextInt();

                    sc.nextLine();

                    System.out.print("Enter Name (String): ");
                    String name = sc.nextLine();

                    Pair<Integer, String> student = new Pair<>(id, name);

                    System.out.println("\nStored Pair Data:");
                    student.displayPair();

                    break;

                // Bounded Generics Example
                case 3:
                    System.out.println("\n--- Arithmetic Operation ---");

                    NumericOperations<Number> operations = new NumericOperations<>();

                    System.out.print("Enter First Number: ");
                    double num1 = sc.nextDouble();

                    System.out.print("Enter Second Number: ");
                    double num2 = sc.nextDouble();

                    double result = operations.add(num1, num2);

                    System.out.println("Addition Result: " + result);

                    break;

                // Wildcard Example
                case 4:
                    System.out.println("\n--- Wildcard Collection Display ---");

                    List<Integer> intList = Arrays.asList(10, 20, 30, 40);

                    List<String> strList = Arrays.asList("Java", "Python", "C++");

                    System.out.println("\nInteger List:");
                    DisplayData.displayList(intList);

                    System.out.println("\nString List:");
                    DisplayData.displayList(strList);

                    break;

                case 5:
                    System.out.println("Exiting Program...");
                    break;

                default:
                    System.out.println("Invalid Choice!");
            }

        } while (choice != 5);

        sc.close();
    }
}
