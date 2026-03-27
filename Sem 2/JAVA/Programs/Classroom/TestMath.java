import mathpack2.Addition;
import mathpack2.Subtraction;

public class TestMath {
    public static void main(String[] args) {
        Addition a = new Addition();
        Subtraction s = new Subtraction();

        System.out.println("Addition: " + a.add(10, 5));
        System.out.println("Subtraction: " + s.sub(10, 5));
    }
}
