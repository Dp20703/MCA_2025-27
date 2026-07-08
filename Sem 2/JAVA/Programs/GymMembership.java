
import java.io.*;
import java.util.*;

// class

class Member {
    int id;
    String name;
    int months;

    Member(int id, String name, int months) {
        this.id = id;
        this.name = name;
        this.months = months;
    }

    public int calculateFees() {
        return months * 1000;
    }

    void display() {
        System.out.println("\nId:" + id + "\tName:" + name + "\tDuration:" + months + "\tFees:" + calculateFees());

    }
}

public class GymMembership {
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
                        System.out.print("Enter your ID:");
                        int id = sc.nextInt();
                        sc.nextLine();

                        System.out.print("Enter your Name:");
                        String name = sc.nextLine();

                        System.out.print("Enter your duration(Months):");
                        int months = sc.nextInt();

                        if (months <= 0) {
                            throw new Exception("Invaid Duration!");
                        }

                        Member m1 = new Member(id, name, months);

                        FileWriter fw = new FileWriter("gym.txt", true);
                        fw.write(m1.id + "," + m1.name + "," + m1.months + "," + m1.calculateFees() + "\n");
                        fw.close();
                        System.out.println("Added Succcessfully");
                    } catch (Exception e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 2:
                    File file = new File("gym.txt");

                    if (!file.exists()) {
                        System.out.println("File doesn't exist");
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
                    System.out.println("Bye bye");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid option");
            }

        }

    }
}
