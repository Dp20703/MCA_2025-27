// Unit-8
// Q4

import java.util.LinkedHashSet;

public class P9 {

    public static void main(String[] args) {

        // Create LinkedHashSet
        LinkedHashSet<String> cities = new LinkedHashSet<>();

        // Add city names
        cities.add("Ahmedabad");
        cities.add("Surat");
        cities.add("Rajkot");
        cities.add("Vadodara");

        // Add duplicate city names
        cities.add("Surat");
        cities.add("Ahmedabad");

        // Display all cities
        System.out.println(
                "Cities in LinkedHashSet:");

        for (String city : cities) {
            System.out.println(city);
        }

        // Display total unique cities
        System.out.println(
                "\nTotal Unique Cities: "
                        + cities.size());

        // Message
        System.out.println(
                "\nLinkedHashSet maintains insertion order and removes duplicates.");
    }
}
