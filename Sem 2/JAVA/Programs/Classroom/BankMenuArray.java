//Menu Driven Bank Account System Using ARRAY
import java.util.Scanner;

class BankAccount {

    int accno;
    String name;
    double balance;

    // Constructor
    BankAccount(int accno, String name, double balance) {
        this.accno = accno;
        this.name = name;
        this.balance = balance;
    }

    void display() {
        System.out.println("\nAccount No: " + accno);
        System.out.println("Name: " + name);
        System.out.println("Balance: ₹" + balance);
    }

    void deposit(double amount) {
        balance += amount;
        System.out.println("₹" + amount + " Deposited Successfully!");
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            System.out.println("₹" + amount + " Withdrawn Successfully!");
        } else {
            System.out.println("Insufficient Balance!");
        }
    }
}

public class BankMenuArray {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        BankAccount[] accounts = new BankAccount[5];   // Array of objects
        int count = 0;

        while (true) {
            System.out.println("\n------ BANK MENU ------");
            System.out.println("1. Create Account");
            System.out.println("2. Deposit");
            System.out.println("3. Withdraw");
            System.out.println("4. Display Account");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            int choice = sc.nextInt();

            switch (choice) {

                case 1:
                    if (count < accounts.length) {
                        System.out.print("Enter Account No: ");
                        int accno = sc.nextInt();
                        sc.nextLine();

                        System.out.print("Enter Name: ");
                        String name = sc.nextLine();

                        System.out.print("Enter Initial Balance: ");
                        double balance = sc.nextDouble();

                        accounts[count] = new BankAccount(accno, name, balance);
                        count++;

                        System.out.println("Account Created Successfully!");
                    } else {
                        System.out.println("Account limit reached!");
                    }
                    break;

                case 2:
                    System.out.print("Enter Account No: ");
                    int dAcc = sc.nextInt();

                    for (int i = 0; i < count; i++) {
                        if (accounts[i].accno == dAcc) {
                            System.out.print("Enter Deposit Amount: ");
                            double amt = sc.nextDouble();
                            accounts[i].deposit(amt);
                        }
                    }
                    break;

                case 3:
                    System.out.print("Enter Account No: ");
                    int wAcc = sc.nextInt();

                    for (int i = 0; i < count; i++) {
                        if (accounts[i].accno == wAcc) {
                            System.out.print("Enter Withdraw Amount: ");
                            double amt = sc.nextDouble();
                            accounts[i].withdraw(amt);
                        }
                    }
                    break;

                case 4:
                    System.out.print("Enter Account No: ");
                    int sAcc = sc.nextInt();

                    for (int i = 0; i < count; i++) {
                        if (accounts[i].accno == sAcc) {
                            accounts[i].display();
                        }
                    }
                    break;

                case 5:
                    System.out.println("Thank You!");
                    return;

                default:
                    System.out.println("Invalid Choice!");
            }
        }
    }
}
