import java.io.*;
import java.util.*;

// Custom Exception
class SeatNotAvailableException extends Exception {
    public SeatNotAvailableException(String msg) {
        super(msg);
    }
}

// Movie Class
class Movie {
    int id;
    String name;
    int availableSeats;

    public Movie(int id, String name, int seats) {
        this.id = id;
        this.name = name;
        this.availableSeats = seats;
    }

    public void display() {
        System.out.println("ID: " + id + ", Movie: " + name +
                ", Available Seats: " + availableSeats);
    }
}

// Ticket Class
class Ticket {
    int ticketId;
    String customerName;
    Movie movie;
    int seatsBooked;

    public Ticket(int ticketId, String customerName, Movie movie, int seatsBooked) {
        this.ticketId = ticketId;
        this.customerName = customerName;
        this.movie = movie;
        this.seatsBooked = seatsBooked;
    }

    public void display() {
        System.out.println("Ticket ID: " + ticketId +
                ", Name: " + customerName +
                ", Movie: " + movie.name +
                ", Seats: " + seatsBooked);
    }

    public String toFileString() {
        return ticketId + "," + customerName + "," +
                movie.name + "," + seatsBooked;
    }
}

// Main Class
public class P13 {
    static Scanner sc = new Scanner(System.in);

    static Movie[] movies = {
            new Movie(1, "Avengers", 50),
            new Movie(2, "Inception", 40),
            new Movie(3, "Interstellar", 30)
    };

    static Ticket[] tickets = new Ticket[100];
    static int tCount = 0;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== Movie Booking Menu =====");
            System.out.println("1. Display Movies");
            System.out.println("2. Book Ticket");
            System.out.println("3. Cancel Ticket");
            System.out.println("4. Display Bookings");
            System.out.println("5. Save to File");
            System.out.println("6. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            try {
                switch (choice) {
                    case 1:
                        displayMovies();
                        break;

                    case 2:
                        bookTicket();
                        break;

                    case 3:
                        cancelTicket();
                        break;

                    case 4:
                        displayTickets();
                        break;

                    case 5:
                        saveToFile();
                        break;

                    case 6:
                        System.out.println("Exiting...");
                        break;

                    default:
                        System.out.println("Invalid choice!");
                }
            } catch (SeatNotAvailableException e) {
                System.out.println("Error: " + e.getMessage());
            }

        } while (choice != 6);
    }

    // Display Movies
    static void displayMovies() {
        for (Movie m : movies) {
            m.display();
        }
    }

    // Find Movie
    static Movie findMovie(int id) {
        for (Movie m : movies) {
            if (m.id == id)
                return m;
        }
        return null;
    }

    // Book Ticket
    static void bookTicket() throws SeatNotAvailableException {
        System.out.print("Enter Movie ID: ");
        int id = sc.nextInt();

        Movie m = findMovie(id);
        if (m == null) {
            System.out.println("Movie not found!");
            return;
        }

        System.out.print("Enter Customer Name: ");
        sc.nextLine();
        String name = sc.nextLine();

        System.out.print("Enter Seats to Book: ");
        int seats = sc.nextInt();

        if (seats > m.availableSeats) {
            throw new SeatNotAvailableException("Not enough seats available!");
        }

        m.availableSeats -= seats;

        tickets[tCount++] = new Ticket(tCount, name, m, seats);
        System.out.println("Ticket booked successfully!");
    }

    // Cancel Ticket
    static void cancelTicket() {
        System.out.print("Enter Ticket ID: ");
        int tid = sc.nextInt();

        for (int i = 0; i < tCount; i++) {
            if (tickets[i].ticketId == tid) {
                tickets[i].movie.availableSeats += tickets[i].seatsBooked;

                // Remove ticket
                for (int j = i; j < tCount - 1; j++) {
                    tickets[j] = tickets[j + 1];
                }
                tCount--;

                System.out.println("Ticket cancelled!");
                return;
            }
        }

        System.out.println("Ticket not found!");
    }

    // Display Tickets
    static void displayTickets() {
        if (tCount == 0) {
            System.out.println("No bookings!");
            return;
        }

        for (int i = 0; i < tCount; i++) {
            tickets[i].display();
        }
    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("tickets.txt");

            for (int i = 0; i < tCount; i++) {
                fw.write(tickets[i].toFileString() + "\n");
            }

            fw.close();
            System.out.println("Data saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}