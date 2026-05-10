import java.io.*;
import java.util.*;

// Custom Exception
class BookNotAvailableException extends Exception {
    public BookNotAvailableException(String msg) {
        super(msg);
    }
}

// Book Class
class Book {
    int id;
    String title;
    String author;
    boolean isIssued;

    public Book(int id, String title, String author) {
        this.id = id;
        this.title = title;
        this.author = author;
        this.isIssued = false;
    }

    public void display() {
        System.out.println("ID: " + id + ", Title: " + title +
                ", Author: " + author +
                ", Status: " + (isIssued ? "Issued" : "Available"));
    }

    public String toFileString() {
        return id + "," + title + "," + author + "," + isIssued;
    }
}

// Library Class
class Library {
    Book[] books = new Book[100];
    int count = 0;

    // Add Book
    public void addBook(int id, String title, String author) {
        books[count++] = new Book(id, title, author);
        System.out.println("Book added successfully!");
    }

    // Find Book
    public Book findBook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                return books[i];
            }
        }
        return null;
    }

    // Issue Book
    public void issueBook(int id) throws BookNotAvailableException {
        Book b = findBook(id);

        if (b == null) {
            System.out.println("Book not found!");
            return;
        }

        if (b.isIssued) {
            throw new BookNotAvailableException("Book already issued!");
        }

        b.isIssued = true;
        System.out.println("Book issued successfully!");
    }

    // Return Book
    public void returnBook(int id) {
        Book b = findBook(id);

        if (b == null) {
            System.out.println("Book not found!");
            return;
        }

        if (!b.isIssued) {
            System.out.println("Book was not issued!");
        } else {
            b.isIssued = false;
            System.out.println("Book returned successfully!");
        }
    }

    // Display Available Books
    public void displayBooks() {
        if (count == 0) {
            System.out.println("No books available!");
            return;
        }

        for (int i = 0; i < count; i++) {
            books[i].display();
        }
    }

    // Save to File
    public void saveToFile() {
        try {
            FileWriter fw = new FileWriter("library.txt");

            for (int i = 0; i < count; i++) {
                fw.write(books[i].toFileString() + "\n");
            }

            fw.close();
            System.out.println("Data saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }

    // Load from File
    public void loadFromFile() {
        try {
            BufferedReader br = new BufferedReader(new FileReader("library.txt"));
            String line;
            count = 0;

            while ((line = br.readLine()) != null) {
                String[] data = line.split(",");

                int id = Integer.parseInt(data[0]);
                String title = data[1];
                String author = data[2];
                boolean issued = Boolean.parseBoolean(data[3]);

                books[count] = new Book(id, title, author);
                books[count].isIssued = issued;
                count++;
            }

            br.close();
            System.out.println("Data loaded!");

        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}

// Main Class
public class P7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Library lib = new Library();
        int choice;

        do {
            System.out.println("\n===== Library Menu =====");
            System.out.println("1. Add Book");
            System.out.println("2. Issue Book");
            System.out.println("3. Return Book");
            System.out.println("4. Display Books");
            System.out.println("5. Save to File");
            System.out.println("6. Load from File");
            System.out.println("7. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter ID: ");
                    int id = sc.nextInt();
                    sc.nextLine();

                    System.out.print("Enter Title: ");
                    String title = sc.nextLine();

                    System.out.print("Enter Author: ");
                    String author = sc.nextLine();

                    lib.addBook(id, title, author);
                    break;

                case 2:
                    try {
                        System.out.print("Enter Book ID: ");
                        int issueId = sc.nextInt();
                        lib.issueBook(issueId);
                    } catch (BookNotAvailableException e) {
                        System.out.println("Error: " + e.getMessage());
                    }
                    break;

                case 3:
                    System.out.print("Enter Book ID: ");
                    int returnId = sc.nextInt();
                    lib.returnBook(returnId);
                    break;

                case 4:
                    lib.displayBooks();
                    break;

                case 5:
                    lib.saveToFile();
                    break;

                case 6:
                    lib.loadFromFile();
                    break;

                case 7:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 7);

        sc.close();
    }
}