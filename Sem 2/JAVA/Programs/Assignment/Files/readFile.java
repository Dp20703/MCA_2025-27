import java.io.File;
import java.util.Scanner;

public class readFile {
    public static void main(String[] args) {
        try {
            File file = new File("test.txt");
            Scanner sc = new Scanner(file);

            while (sc.hasNextLine()) {
                String data = sc.nextLine();
                System.out.println(data);
            }

            sc.close();
        } catch (Exception e) {
            System.out.println("Error occurred");
        }
    }
}