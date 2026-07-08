package Sets;
import java.util.*;

// Generic Class
class Box<T> {

    T data;

    Box(T data) {
        this.data = data;
    }

    void display() {
        System.out.println("Data : " + data);
    }
}

// Multiple Type Parameters
class Pair<T, U> {

    T first;
    U second;

    Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    void display() {
        System.out.println(first + " " + second);
    }
}

// Bounded Generic
class Calculator<T extends Number> {

    void square(T num) {
        System.out.println("Square = " +
                (num.doubleValue() * num.doubleValue()));
    }
}

public class P7B {

    // Wildcard Method
    static void show(List<?> list) {

        for (Object obj : list)
            System.out.println(obj);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        while (true) {

            System.out.println("\n1. Generic Box");
            System.out.println("2. Pair");
            System.out.println("3. Calculator");
            System.out.println("4. Wildcard");
            System.out.println("5. Exit");

            System.out.print("Enter Choice : ");
            int ch = sc.nextInt();

            switch (ch) {

                case 1:

                    Box<String> b = new Box<>("Java");
                    b.display();

                    break;

                case 2:

                    Pair<Integer, String> p = new Pair<>(101, "Rahul");

                    p.display();

                    break;

                case 3:

                    Calculator<Integer> c = new Calculator<>();

                    c.square(10);

                    break;

                case 4:

                    List<Integer> list = Arrays.asList(10, 20, 30);

                    show(list);

                    break;

                case 5:

                    System.exit(0);

            }

        }

    }

}