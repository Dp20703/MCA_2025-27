import java.io.*;
import java.util.*;

// Custom Exception
class InvalidActivityException extends Exception {
    public InvalidActivityException(String msg) {
        super(msg);
    }
}

// Activity Class
class Activity {
    String name;
    int duration; // in minutes
    double caloriesPerMin;

    public Activity(String name, int duration, double caloriesPerMin) throws InvalidActivityException {
        if (duration <= 0 || caloriesPerMin <= 0) {
            throw new InvalidActivityException("Invalid duration or calorie value!");
        }
        this.name = name;
        this.duration = duration;
        this.caloriesPerMin = caloriesPerMin;
    }

    // Calculate Calories Burned
    public double calculateCalories() {
        return duration * caloriesPerMin;
    }

    public void display() {
        System.out.println("Activity: " + name +
                ", Duration: " + duration + " mins" +
                ", Calories Burned: " + calculateCalories());
    }

    public String toFileString() {
        return name + "," + duration + "," + caloriesPerMin + "," + calculateCalories();
    }
}

// Main Class
public class P20 {
    static Scanner sc = new Scanner(System.in);
    static Activity[] activities = new Activity[100];
    static int count = 0;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== Fitness Tracker Menu =====");
            System.out.println("1. Add Activity");
            System.out.println("2. Display Activities");
            System.out.println("3. Calculate Total Calories");
            System.out.println("4. Save to File");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    addActivity();
                    break;

                case 2:
                    displayActivities();
                    break;

                case 3:
                    calculateTotalCalories();
                    break;

                case 4:
                    saveToFile();
                    break;

                case 5:
                    System.out.println("Stay fit! 💪");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 5);
    }

    // Add Activity
    static void addActivity() {
        try {
            System.out.print("Enter Activity Name: ");
            String name = sc.nextLine();

            System.out.print("Enter Duration (minutes): ");
            int duration = sc.nextInt();

            System.out.print("Enter Calories per Minute: ");
            double cal = sc.nextDouble();
            sc.nextLine();

            activities[count++] = new Activity(name, duration, cal);
            System.out.println("Activity added!");

        } catch (InvalidActivityException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    // Display Activities
    static void displayActivities() {
        if (count == 0) {
            System.out.println("No activities recorded!");
            return;
        }

        for (int i = 0; i < count; i++) {
            activities[i].display();
        }
    }

    // Calculate Total Calories
    static void calculateTotalCalories() {
        double total = 0;

        for (int i = 0; i < count; i++) {
            total += activities[i].calculateCalories();
        }

        System.out.println("Total Calories Burned = " + total);
    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("activities.txt");

            for (int i = 0; i < count; i++) {
                fw.write(activities[i].toFileString() + "\n");
            }

            fw.close();
            System.out.println("Data saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}
