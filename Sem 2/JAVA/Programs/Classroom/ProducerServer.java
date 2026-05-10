import java.io.*;
import java.net.*;

public class ProducerServer {
    public static void main(String[] args) throws Exception {

        ServerSocket server = new ServerSocket(5000);
        System.out.println("Producer waiting for consumer...");

        Socket socket = server.accept();
        System.out.println("Consumer connected");

        DataOutputStream out = new DataOutputStream(socket.getOutputStream());

        for (int i = 1; i <= 5; i++) {
            out.writeInt(i);
            System.out.println("Produced: " + i);
            Thread.sleep(1000);
        }

        socket.close();
        server.close();
    }
}