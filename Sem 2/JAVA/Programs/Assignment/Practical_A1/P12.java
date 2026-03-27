import java.io.*;
import java.util.*;

// Custom Exception
class InvalidDurationException extends Exception {
    public InvalidDurationException(String msg) {
        super(msg);
    }
}

// Song Class
class Song {
    String title;
    String artist;
    double duration;

    public Song(String title, String artist, double duration) throws InvalidDurationException {
        if (duration <= 0) {
            throw new InvalidDurationException("Duration must be positive!");
        }
        this.title = title;
        this.artist = artist;
        this.duration = duration;
    }

    public void display() {
        System.out.println("Title: " + title +
                ", Artist: " + artist +
                ", Duration: " + duration + " mins");
    }

    public String toFileString() {
        return title + "," + artist + "," + duration;
    }
}

// Main Class
public class P12 {
    static Scanner sc = new Scanner(System.in);
    static Song[] songs = new Song[100];
    static int count = 0;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== Playlist Menu =====");
            System.out.println("1. Add Song");
            System.out.println("2. Display Playlist");
            System.out.println("3. Search Song by Title");
            System.out.println("4. Save to File");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    addSong();
                    break;

                case 2:
                    displaySongs();
                    break;

                case 3:
                    searchSong();
                    break;

                case 4:
                    saveToFile();
                    break;

                case 5:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 5);
    }

    // Add Song
    static void addSong() {
        try {
            System.out.print("Enter Title: ");
            String title = sc.nextLine();

            System.out.print("Enter Artist: ");
            String artist = sc.nextLine();

            System.out.print("Enter Duration (minutes): ");
            double duration = sc.nextDouble();
            sc.nextLine();

            songs[count++] = new Song(title, artist, duration);
            System.out.println("Song added!");

        } catch (InvalidDurationException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    // Display Songs
    static void displaySongs() {
        if (count == 0) {
            System.out.println("Playlist is empty!");
            return;
        }

        for (int i = 0; i < count; i++) {
            songs[i].display();
        }
    }

    // Search Song
    static void searchSong() {
        System.out.print("Enter title to search: ");
        String search = sc.nextLine();

        boolean found = false;

        for (int i = 0; i < count; i++) {
            if (songs[i].title.equalsIgnoreCase(search)) {
                songs[i].display();
                found = true;
            }
        }

        if (!found) {
            System.out.println("Song not found!");
        }
    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("playlist.txt");

            for (int i = 0; i < count; i++) {
                fw.write(songs[i].toFileString() + "\n");
            }

            fw.close();
            System.out.println("Playlist saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}