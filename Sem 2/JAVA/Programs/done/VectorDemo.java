import java.util.Vector;

public class VectorDemo {
    public static void main(String[] args) {

        Vector<String> names = new Vector<>();

        // Add elements
        names.add("Kruti");
        names.add("Riya");
        names.add("Asha");

        // Display elements
        System.out.println("Vector Elements: " + names);

        // Get element
        System.out.println("First element: " + names.get(0));

        // Remove element
        names.remove(1);

        System.out.println("After Removal: " + names);

        // Size
        System.out.println("Size: " + names.size());

        // Capacity
        System.out.println("Capacity: " + names.capacity());
    }
}
