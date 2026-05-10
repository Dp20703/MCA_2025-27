import java.util.*;

class Box<T> {
    private T value;

    void set(T value) {
        this.value = value;
    }

    T get() {
        return value;
    }
}

public class GenericBoxMenu {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Box<Integer> intBox = new Box<>();
        Box<String> strBox = new Box<>();

        int choice;

        do {
            System.out.println("\n--- Generic Box Menu ---");
            System.out.println("1. Store Integer");
            System.out.println("2. Store String");
            System.out.println("3. Display Integer");
            System.out.println("4. Display String");
            System.out.println("5. Exit");

            choice = sc.nextInt();
            sc.nextLine(); // clear buffer

            switch(choice) {
                case 1:
                    System.out.print("Enter Integer: ");
                    intBox.set(sc.nextInt());
                    break;

                case 2:
                    System.out.print("Enter String: ");
                    strBox.set(sc.nextLine());
                    break;

                case 3:
                    System.out.println("Integer Value: " + intBox.get());
                    break;

                case 4:
                    System.out.println("String Value: " + strBox.get());
                    break;
            }
        } while(choice != 5);
    }
}