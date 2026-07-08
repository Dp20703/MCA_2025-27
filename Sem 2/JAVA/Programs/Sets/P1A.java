package Sets;
import java.io.*;
import java.util.*;

class Member {
    int id;
    String name;
    int months;

    // Constructor
    Member(int id, String name, int months) {
        this.id = id;
        this.name = name;
        this.months = months;
    }

    // Calculate membership fee
    int calculateFee() {
        return months * 1000;   // Rs.1000 per month
    }

    // Display details
    void display() {
        System.out.println("ID : " + id);
        System.out.println("Name : " + name);
        System.out.println("Duration : " + months + " months");
        System.out.println("Fee : Rs." + calculateFee());
        System.out.println("------------------------");
    }
}

public class P1A {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        while (true) {

            System.out.println("\n1. Add Member");
            System.out.println("2. Display Members");
            System.out.println("3. Exit");
            System.out.print("Enter Choice : ");

            int choice = sc.nextInt();

            switch (choice) {

                case 1:

                    try {

                        System.out.print("Enter ID : ");
                        int id = sc.nextInt();

                        sc.nextLine();

                        System.out.print("Enter Name : ");
                        String name = sc.nextLine();

                        System.out.print("Enter Membership Duration (Months) : ");
                        int months = sc.nextInt();

                        if (months <= 0) {
                            throw new Exception("Invalid Duration!");
                        }

                        Member m = new Member(id, name, months);

                        FileWriter fw = new FileWriter("gym.txt", true);

                        fw.write(m.id + "," + m.name + "," + m.months + "," + m.calculateFee() + "\n");

                        fw.close();

                        System.out.println("Member Added Successfully!");

                    } catch (Exception e) {
                        System.out.println(e.getMessage());
                    }

                    break;

                case 2:

                    File file = new File("gym.txt");

                    if (!file.exists()) {
                        System.out.println("No Records Found.");
                        break;
                    }

                    BufferedReader br = new BufferedReader(new FileReader(file));

                    String line;

                    while ((line = br.readLine()) != null) {

                        String data[] = line.split(",");

                        System.out.println("ID : " + data[0]);
                        System.out.println("Name : " + data[1]);
                        System.out.println("Duration : " + data[2] + " months");
                        System.out.println("Fee : Rs." + data[3]);
                        System.out.println("----------------------");
                    }

                    br.close();

                    break;

                case 3:
                    System.out.println("Thank You");
                    System.exit(0);

                default:
                    System.out.println("Invalid Choice");
            }

        }

    }
}