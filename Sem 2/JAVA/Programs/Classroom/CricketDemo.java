/* 
Program: Demonstration of Inheritance, Abstract Class, Interfaces,
Default & Static Methods, Functional Interface and Lambda Expression
*/

package cricket;   // package declaration

// Importing Scanner class from java.util package
import java.util.Scanner;

// Importing static method sqrt from Math class
import static java.lang.Math.sqrt;


/*---------------------------------------------------------
 Abstract Class
---------------------------------------------------------*/

abstract class Player {

    // Access specifiers
    private int age;        // private variable
    protected String name;  // protected variable

    // Constructor
    Player(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Concrete method
    void showPlayer() {
        System.out.println("Player Name: " + name);
        System.out.println("Player Age: " + age);
    }

    // Abstract method (no body)
    abstract void play();
}


/*---------------------------------------------------------
 Interface 1
---------------------------------------------------------*/

interface Batsman {

    void batting();

}


/*---------------------------------------------------------
 Interface 2
 Demonstrates Default and Static Methods
---------------------------------------------------------*/

interface Bowler {

    void bowling();

    // Default method
    default void warmup() {
        System.out.println("Player is doing warmup before match");
    }

    // Static method
    static void gameRules() {
        System.out.println("Follow ICC Cricket Rules");
    }
}


/*---------------------------------------------------------
 Functional Interface
---------------------------------------------------------*/

@FunctionalInterface
interface RunCalculator {

    int calculateRuns(int fours, int sixes);

}


/*---------------------------------------------------------
 Child Class
 Demonstrates Inheritance & Multiple Interfaces
---------------------------------------------------------*/

class AllRounder extends Player implements Batsman, Bowler {

    int wickets;

    // Constructor using super keyword
    AllRounder(String name, int age, int wickets) {
        super(name, age);   // calling parent constructor
        this.wickets = wickets;
    }

    // Implementing abstract method
    void play() {
        System.out.println(name + " is playing cricket.");
    }

    // Implementing interface method
    public void batting() {
        System.out.println(name + " is batting.");
    }

    // Implementing interface method
    public void bowling() {
        System.out.println(name + " is bowling.");
        System.out.println("Wickets taken: " + wickets);
    }
}


/*---------------------------------------------------------
 Main Class
---------------------------------------------------------*/

public class CricketDemo {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Player Name:");
        String name = sc.nextLine();

        System.out.println("Enter Age:");
        int age = sc.nextInt();

        System.out.println("Enter Wickets Taken:");
        int wickets = sc.nextInt();


        // Creating object of child class
        AllRounder player = new AllRounder(name, age, wickets);

        System.out.println("\n--- Player Details ---");

        player.showPlayer();   // method from abstract class
        player.play();         // implemented abstract method
        player.batting();      // interface method
        player.bowling();      // interface method
        player.warmup();       // default method


        // Static method of interface
        Bowler.gameRules();


        /*----------------------------------------------
         Functional Interface with Lambda Expression
        ----------------------------------------------*/

        RunCalculator r = (fours, sixes) -> (fours * 4 + sixes * 6);

        System.out.println("\nEnter number of fours:");
        int f = sc.nextInt();

        System.out.println("Enter number of sixes:");
        int s = sc.nextInt();

        int runs = r.calculateRuns(f, s);

        System.out.println("Total Runs = " + runs);


        /*----------------------------------------------
         Demonstrating import static
        ----------------------------------------------*/

        double result = sqrt(16);   // sqrt used directly

        System.out.println("\nSquare root of 16 = " + result);

    }
}