import java.util.ArrayList;

public class ArrayListExample {
    public static void main(String[] args) {

        // Create ArrayList
        ArrayList<Integer> numbers = new ArrayList<>();

        // Add elements
        numbers.add(10);
        numbers.add(20);
        numbers.add(30);

        // Access element
        System.out.println("First element: " + numbers.get(0));

        // Modify element
        numbers.set(1, 200);

        // Remove element
        numbers.remove(2);

        // Loop through ArrayList
        System.out.println("ArrayList Elements:");
        for (Integer num : numbers) {
            System.out.println(num);
        }
    }
}
