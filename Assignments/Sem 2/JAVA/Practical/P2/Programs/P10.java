// Unit-8
// Q5
import java.util.TreeSet;

public class P10 {

    public static void main(String[] args) {

        // Create TreeSet
        TreeSet<Integer> numbers = new TreeSet<>();

        // Add elements
        numbers.add(50);
        numbers.add(10);
        numbers.add(30);
        numbers.add(20);
        numbers.add(40);

        // Display elements
        System.out.println(
                "Elements in TreeSet:");

        for (Integer num : numbers) {
            System.out.println(num);
        }

        // Display total elements
        System.out.println(
                "\nTotal Elements: "
                        + numbers.size());

        // Message
        System.out.println(
                "\nTreeSet automatically stores elements in sorted order.");
    }
}