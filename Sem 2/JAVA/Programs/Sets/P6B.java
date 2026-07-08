package Sets;
class BankAccount {

    int balance = 1000;

    // Deposit
    synchronized void deposit(int amount) {

        balance += amount;

        System.out.println(Thread.currentThread().getName()
                + " Deposited : " + amount);

        System.out.println("Balance : " + balance);
    }

    // Withdraw
    synchronized void withdraw(int amount) {

        if (balance >= amount) {

            balance -= amount;

            System.out.println(Thread.currentThread().getName()
                    + " Withdraw : " + amount);

            System.out.println("Balance : " + balance);

        } else {

            System.out.println("Insufficient Balance!");

        }

    }
}

class DepositThread extends Thread {

    BankAccount account;

    DepositThread(BankAccount account) {
        this.account = account;
    }

    public void run() {
        account.deposit(500);
    }
}

class WithdrawThread extends Thread {

    BankAccount account;

    WithdrawThread(BankAccount account) {
        this.account = account;
    }

    public void run() {
        account.withdraw(800);
    }
}

public class P6B {

    public static void main(String[] args) {

        BankAccount account = new BankAccount();

        DepositThread t1 = new DepositThread(account);
        WithdrawThread t2 = new WithdrawThread(account);

        t1.setName("Thread-1");
        t2.setName("Thread-2");

        t1.start();
        t2.start();

    }
}