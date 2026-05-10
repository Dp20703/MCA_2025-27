// Unit-6
// Q3

import java.util.*;

// Player Class
class Player {

    String name;
    int score;

    // Constructor
    public Player(String name, int score) {
        this.name = name;
        this.score = score;
    }

    // Method to display player details
    @Override
    public String toString() {
        return "Name: " + name +
                ", Score: " + score;
    }
}

// Comparator for Multilevel Sorting
class PlayerComparator implements Comparator<Player> {

    @Override
    public int compare(Player p1, Player p2) {

        // Sort by score in descending order
        int scoreCompare = Integer.compare(p2.score, p1.score);

        // If scores are different
        if (scoreCompare != 0) {
            return scoreCompare;
        }

        // If scores are same, sort by name
        return p1.name.compareToIgnoreCase(p2.name);
    }
}

public class P5 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        ArrayList<Player> players = new ArrayList<>();

        int choice;

        do {

            System.out.println("\n===== Leaderboard System =====");
            System.out.println("1. Add Player");
            System.out.println("2. Display All Players");
            System.out.println("3. Display Sorted Leaderboard");
            System.out.println("4. Display Top 3 Players");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");

            choice = sc.nextInt();

            switch (choice) {

                // Add Player
                case 1:

                    sc.nextLine(); // Clear Buffer

                    System.out.print("Enter Player Name: ");
                    String name = sc.nextLine();

                    System.out.print("Enter Player Score: ");
                    int score = sc.nextInt();

                    players.add(new Player(name, score));

                    System.out.println("Player Added Successfully!");
                    break;

                // Display All Players
                case 2:

                    if (players.isEmpty()) {
                        System.out.println("No players available.");
                    } else {

                        System.out.println("\n--- Player Details ---");

                        for (Player p : players) {
                            System.out.println(p);
                        }
                    }

                    break;

                // Display Sorted Leaderboard
                case 3:

                    Collections.sort(players,
                            new PlayerComparator());

                    System.out.println(
                            "\n--- Sorted Leaderboard ---");

                    for (Player p : players) {
                        System.out.println(p);
                    }

                    break;

                // Display Top 3 Players
                case 4:

                    Collections.sort(players,
                            new PlayerComparator());

                    System.out.println(
                            "\n--- Top 3 Players ---");

                    int limit = Math.min(3, players.size());

                    for (int i = 0; i < limit; i++) {

                        System.out.println(
                                (i + 1) + ". " + players.get(i));
                    }

                    break;

                // Exit
                case 5:

                    System.out.println("Exiting Program...");
                    break;

                default:

                    System.out.println("Invalid Choice!");
            }

        } while (choice != 5);

        sc.close();
    }
}