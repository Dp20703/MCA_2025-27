import java.io.*;
import java.net.*;

public class ConsumerClient {
    public static void main(String[] args) throws Exception {

        Socket socket = new Socket("localhost", 5000);

        DataInputStream in = new DataInputStream(socket.getInputStream());

        for (int i = 1; i <= 5; i++) {
            int data = in.readInt();
            System.out.println("Consumed: " + data);
        }

        socket.close();
    }
}