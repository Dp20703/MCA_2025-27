// Create a generic class Swap<T> to swap two values.
class Swap<T> {
    T a, b;

    Swap(T a, T b) {
        this.a = a;
        this.b = b;
    }

    void swapValues() {
        T temp = a;
        a = b;
        b = temp;
    }

    void display() {
        System.out.println("a = " + a + ", b = " + b);
    }
}

class generic_swap {
    public static void main(String[] args) {
        Swap<Integer> obj = new Swap<>(5, 10);
        obj.display();
        obj.swapValues();
        obj.display();
    }
}