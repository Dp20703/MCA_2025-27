import java.io.*;
import java.util.*;

// Custom Exception
class InvalidScoreException extends Exception {
    public InvalidScoreException(String msg) {
        super(msg);
    }
}

// Player Class
class Player {
    int id;
    String name;
    int totalRuns;
    int matches;

    public Player(int id, String name, int totalRuns, int matches) throws InvalidScoreException {
        if (totalRuns < 0 || matches <= 0) {
            throw new InvalidScoreException("Invalid runs or matches!");
        }
        this.id = id;
        this.name = name;
        this.totalRuns = totalRuns;
        this.matches = matches;
    }

    // Calculate Batting Average
    public double getAverage() {
        return (double) totalRuns / matches;
    }

    public void display() {
        System.out.println("ID: " + id + ", Name: " + name +
                ", Runs: " + totalRuns +
                ", Matches: " + matches +
                ", Avg: " + getAverage());
    }

    public String toFileString() {
        return id + "," + name + "," + totalRuns + "," + matches;
    }
}

// Main Class
public class P11 {
    static Scanner sc = new Scanner(System.in);
    static Player[] players = new Player[100];
    static int count = 0;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== Player Menu =====");
            System.out.println("1. Add Player");
            System.out.println("2. Display Players");
            System.out.println("3. Save to File");
            System.out.println("4. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    addPlayer();
                    break;

                case 2:
                    displayPlayers();
                    break;

                case 3:
                    saveToFile();
                    break;

                case 4:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 4);
    }

    // Add Player
    static void addPlayer() {
        try {
            System.out.print("Enter ID: ");
            int id = sc.nextInt();
            sc.nextLine();

            System.out.print("Enter Name: ");
            String name = sc.nextLine();

            System.out.print("Enter Total Runs: ");
            int runs = sc.nextInt();

            System.out.print("Enter Matches Played: ");
            int matches = sc.nextInt();

            players[count++] = new Player(id, name, runs, matches);
            System.out.println("Player added!");

        } catch (InvalidScoreException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    // Display Players
    static void displayPlayers() {
        if (count == 0) {
            System.out.println("No records!");
            return;
        }

        for (int i = 0; i < count; i++) {
            players[i].display();
        }
    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("players.txt");

            for (int i = 0; i < count; i++) {
                fw.write(players[i].toFileString() + "\n");
            }

            fw.close();
            System.out.println("Data saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}
