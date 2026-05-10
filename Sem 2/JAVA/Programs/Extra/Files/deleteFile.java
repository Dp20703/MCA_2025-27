import java.io.File;

public class deleteFile {
    public static void main(String[] args) {
        File file = new File("test.txt");
        if (file.delete()) {
            System.out.println("File deleted");
        } else {
            System.out.println("Failed to delete");
        }
    }
}
