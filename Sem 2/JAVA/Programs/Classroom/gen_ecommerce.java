class Box<T> {
    T item;

    // Store item
    void store(T item) {
        this.item = item;
    }

    // Get item
    T get() {
        return item;
    }
}

// Main class
public class gen_ecommrece {
    public static void main(String[] args) {

        // Box for String (Product Name)
        Box<String> b1 = new Box<>();
        b1.store("Shoes");

        // Box for Integer (Product ID)
        Box<Integer> b2 = new Box<>();
        b2.store(101);

        // Box for Double (Price)
        Box<Double> b3 = new Box<>();
        b3.store(1999.99);

        // Display stored values
        System.out.println("Product Name: " + b1.get());
        System.out.println("Product ID: " + b2.get());
        System.out.println("Product Price: " + b3.get());
    }
}