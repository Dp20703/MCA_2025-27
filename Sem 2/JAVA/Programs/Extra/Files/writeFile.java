import java.io.FileWriter;
import java.io.IOException;

public class writeFile {
    public static void main(String[] args) {
        try {
            FileWriter writer = new FileWriter("test.txt");
            writer.write("Hello Darshan!\nWelcome to Java File Handling.");
            writer.close();
            System.out.println("Successfully written.");

        } catch (IOException e) {
            System.err.println("Error Occured:" + e);
        }
    }
}
