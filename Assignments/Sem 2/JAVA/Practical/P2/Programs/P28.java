// Unit-11
// Q5

class BankAccount {

        private int balance = 5000;

        // Deposit Method
        public synchronized void deposit(
                        int amount) {

                System.out.println(
                                Thread.currentThread().getName()
                                                + " is depositing ₹"
                                                + amount);

                balance = balance + amount;

                System.out.println(
                                "Updated Balance: ₹"
                                                + balance);
        }

        // Withdrawal Method
        public synchronized void withdraw(
                        int amount) {

                System.out.println(
                                Thread.currentThread().getName()
                                                + " is withdrawing ₹"
                                                + amount);

                // Check sufficient balance
                if (balance >= amount) {

                        balance = balance - amount;

                        System.out.println(
                                        "Withdrawal Successful.");

                        System.out.println(
                                        "Updated Balance: ₹"
                                                        + balance);

                } else {

                        System.out.println(
                                        "Insufficient Balance!");

                        System.out.println(
                                        "Current Balance: ₹"
                                                        + balance);
                }
        }
}

// Deposit Thread using Runnable
class DepositTask implements Runnable {

        BankAccount account;
        int amount;

        // Constructor
        DepositTask(
                        BankAccount account,
                        int amount) {

                this.account = account;
                this.amount = amount;
        }

        @Override
        public void run() {

                account.deposit(amount);
        }
}

// Withdrawal Thread using Runnable
class WithdrawTask implements Runnable {

        BankAccount account;
        int amount;

        // Constructor
        WithdrawTask(
                        BankAccount account,
                        int amount) {

                this.account = account;
                this.amount = amount;
        }

        @Override
        public void run() {

                account.withdraw(amount);
        }
}

public class P28 {

        public static void main(String[] args) {

                // Shared Bank Account
                BankAccount account = new BankAccount();

                // Create threads
                Thread t1 = new Thread(
                                new DepositTask(account, 2000),
                                "Thread-Deposit-1");

                Thread t2 = new Thread(
                                new WithdrawTask(account, 3000),
                                "Thread-Withdraw-1");

                Thread t3 = new Thread(
                                new WithdrawTask(account, 6000),
                                "Thread-Withdraw-2");

                Thread t4 = new Thread(
                                new DepositTask(account, 5000),
                                "Thread-Deposit-2");

                // Start threads
                t1.start();
                t2.start();
                t3.start();
                t4.start();
        }
}
