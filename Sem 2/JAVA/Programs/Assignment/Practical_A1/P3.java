import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

interface bankOperations {
    void deposit(double amount);

    void withdraw(double amount) throws Exception;

    void checkBalance();
}

class InsufficientBalanceException extends Exception {
    public InsufficientBalanceException(String msg) {
        super(msg);
    }
}

class Bankaccount implements bankOperations {
    int accNo;
    String name;
    double balance;

    Bankaccount(int accNo, String name, double balance) {
        this.accNo = accNo;
        this.name = name;
        this.balance = balance;
    }

    // deposit
    public void deposit(double amount) {
        if (amount > 0) {
            this.balance += amount;
            System.out.println("Amount Deposited!");
        } else {
            System.out.println("Invalid amount!");
        }
    }

    // withdraw
    public void withdraw(double amount) throws InsufficientBalanceException {
        if (amount > this.balance) {
            throw new InsufficientBalanceException("Not enough balance!");
        } else if (amount < 0) {
            System.out.println("Invalid amount!");
        } else {
            this.balance -= amount;
            System.out.println("withdrawal successfully!");
        }
    }

    // Check Balance
    public void checkBalance() {
        System.out.println("Balance: " + balance);
    }

    // Display Details
    public void display() {
        System.out.println("Acc No: " + accNo + ", Name: " + name + ", Balance: " + balance);
    }

    // Convert to file string
    public String toFileString() {
        return accNo + "," + name + "," + balance;
    }
}

public class P3 {
    static Scanner sc = new Scanner(System.in);
    static Bankaccount[] accounts = new Bankaccount[100];
    static int count = 0;

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("\n===== Banking Menu =====");
            System.out.println("1. Create Account");
            System.out.println("2. Deposit");
            System.out.println("3. Withdraw");
            System.out.println("4. Check Balance");
            System.out.println("5. Display Accounts");
            System.out.println("6. Save to File");
            System.out.println("7. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    createAccount();
                    break;
                case 2:
                    deposit();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    checkBalance();
                    break;
                case 5:
                    displayAccounts();
                    break;
                case 6:
                    saveToFile();
                    break;
                case 7:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        } while (choice != 7);
    }

    // create account
    static void createAccount() {
        System.out.print("Enter Account No: ");
        int accNo = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Name: ");
        String name = sc.nextLine();

        System.out.print("Enter Initial Balance: ");
        double balance = sc.nextDouble();

        accounts[count++] = new Bankaccount(accNo, name, balance);
        System.out.println("Account created!");
    }

    // find account
    static Bankaccount findBankaccount(int accNo) {
        for (int i = 0; i < count; i++) {
            if (accounts[i].accNo == accNo) {
                return accounts[i];
            }
        }
        return null;
    }

    // deposit
    static void deposit() {
        System.out.print("Enter Account No: ");
        int accNo = sc.nextInt();
        Bankaccount acc = findBankaccount(accNo);
        if (acc != null) {
            System.out.print("Enter Amount: ");
            double amount = sc.nextDouble();
            acc.deposit(amount);
        } else {
            System.out.println("Account not found!");
        }
    }

    // withdraw
    static void withdraw() {
        try {
            System.out.print("Enter Account No: ");
            int accNo = sc.nextInt();
            Bankaccount acc = findBankaccount(accNo);
            if (acc != null) {
                System.out.print("Enter Amount: ");
                double amount = sc.nextDouble();
                acc.withdraw(amount);
            } else {
                System.out.println("Account not found!");
            }
        } catch (InsufficientBalanceException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    // check balance
    static void checkBalance() {
        System.out.print("Enter Account No: ");
        int accNo = sc.nextInt();
        Bankaccount acc = findBankaccount(accNo);
        if (acc != null) {
            acc.checkBalance();
        } else {
            System.out.println("Account not found!");
        }
    }

    // display all account
    static void displayAccounts() {
        if (count == 0) {
            System.out.println("No accounts!");
        }
        for (int i = 0; i < count; i++) {
            accounts[i].display();
        }

    }

    // Save to File
    static void saveToFile() {
        try {
            FileWriter fw = new FileWriter("accounts.txt");

            for (int i = 0; i < count; i++) {
                fw.write(accounts[i].toFileString() + "\n");
            }

            fw.close();
            System.out.println("Data saved!");

        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}