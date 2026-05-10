// Unit-8
// Q10

import java.util.PriorityQueue;

public class P15 {

    public static void main(String[] args) {

        // Create PriorityQueue
        PriorityQueue<Integer> numbers = new PriorityQueue<>();

        // Add elements
        numbers.add(50);
        numbers.add(10);
        numbers.add(30);
        numbers.add(20);
        numbers.add(40);

        // Display original queue
        System.out.println(
                "PriorityQueue Elements:");

        System.out.println(numbers);

        // Display elements in priority order
        System.out.println(
                "\nElements in Priority Order:");

        while (!numbers.isEmpty()) {

            // Remove highest priority element
            System.out.println(numbers.poll());
        }
    }
}