// Unit-8
// Q7

import java.util.HashMap;
import java.util.Map;

public class P12 {

    public static void main(String[] args) {

        // Create HashMap
        HashMap<Integer, String> products = new HashMap<>();

        // Add entries
        products.put(101, "Laptop");
        products.put(102, "Mobile");
        products.put(103, "Keyboard");
        products.put(104, "Mouse");

        // Display original map
        System.out.println("Original Product Map:");

        for (Map.Entry<Integer, String> entry : products.entrySet()) {

            System.out.println(
                    "Product ID: "
                            + entry.getKey()
                            + ", Product Name: "
                            + entry.getValue());
        }

        // Replace value of existing key
        products.replace(102, "Smartphone");

        // Display updated map
        System.out.println(
                "\nUpdated Product Map:");

        for (Map.Entry<Integer, String> entry : products.entrySet()) {

            System.out.println(
                    "Product ID: "
                            + entry.getKey()
                            + ", Product Name: "
                            + entry.getValue());
        }
    }
}
