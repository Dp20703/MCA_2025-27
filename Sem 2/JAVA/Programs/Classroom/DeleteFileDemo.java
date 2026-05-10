import java.io.File;

public class DeleteFileDemo {
    public static void main(String[] args) {
        File file = new File("stuti.txt");

        if (file.delete()) {
            System.out.println("File deleted");
        } else {
            System.out.println("Failed to delete file");
        }
    }
}