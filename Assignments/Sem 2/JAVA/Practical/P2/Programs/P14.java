// Unit-8
// Q9

import java.util.LinkedList;
import java.util.Queue;

public class P14 {
    public static void main(String[] args) {

        // Create Queue
        Queue<String> customers = new LinkedList<>();

        // Add customer names
        customers.add("Darshan");
        customers.add("Amit");
        customers.add("Ravi");
        customers.add("Bhavik");

        // Display queue
        System.out.println(
                "Customers in Queue:");

        System.out.println(customers);

        // Remove customers using FIFO
        System.out.println(
                "\nServing Customers:");

        while (!customers.isEmpty()) {

            // Remove first customer
            String removedCustomer = customers.poll();

            System.out.println(
                    removedCustomer
                            + " has been served.");
        }

        // Queue after removal
        System.out.println(
                "\nAll customers served.");
    }
}
