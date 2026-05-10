// Unit-8
// Q12

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class P17 {

    public static void main(String[] args) {

        // Create List
        List<Integer> numbers = new ArrayList<>();

        // Add elements including duplicates
        numbers.add(10);
        numbers.add(20);
        numbers.add(30);
        numbers.add(20);
        numbers.add(40);
        numbers.add(10);
        numbers.add(50);

        // Display original list
        System.out.println(
                "Original List:");

        System.out.println(numbers);

        // Convert List into Set
        Set<Integer> uniqueNumbers = new HashSet<>(numbers);

        // Display unique elements
        System.out.println(
                "\nUnique Elements:");

        System.out.println(uniqueNumbers);
    }
}