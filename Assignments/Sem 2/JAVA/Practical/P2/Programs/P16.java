// Unit-8
// Q11

import java.util.ArrayDeque;
import java.util.Deque;

public class P16 {

    public static void main(String[] args) {

        // Create Deque
        Deque<Integer> deque = new ArrayDeque<>();

        // Add elements at front
        deque.addFirst(10);
        deque.addFirst(20);

        // Add elements at rear
        deque.addLast(30);
        deque.addLast(40);

        // Display deque after insertion
        System.out.println(
                "Deque after adding elements:");

        System.out.println(deque);

        // Remove element from front
        int frontRemoved = deque.removeFirst();

        System.out.println(
                "\nRemoved from Front: "
                        + frontRemoved);

        // Remove element from rear
        int rearRemoved = deque.removeLast();

        System.out.println(
                "Removed from Rear: "
                        + rearRemoved);

        // Display final deque
        System.out.println(
                "\nFinal Deque:");

        System.out.println(deque);
    }
}
