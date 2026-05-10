// Unit-11
// Q2

class MyThread extends Thread {

    // Constructor
    MyThread(String name) {
        super(name);
    }

    @Override
    public void run() {

        try {

            for (int i = 1; i <= 5; i++) {

                System.out.println(
                        getName()
                                + " is running : "
                                + i);

                // sleep() demonstration
                Thread.sleep(1000);

                // yield() demonstration
                Thread.yield();
            }

        } catch (InterruptedException e) {

            System.out.println(e);
        }
    }
}

public class P25 {

    public static void main(String[] args)
            throws InterruptedException {

        // Create three threads
        MyThread t1 = new MyThread("Thread-1");

        MyThread t2 = new MyThread("Thread-2");

        MyThread t3 = new MyThread("Thread-3");

        // Set priorities
        t1.setPriority(Thread.MAX_PRIORITY);
        t2.setPriority(Thread.NORM_PRIORITY);
        t3.setPriority(Thread.MIN_PRIORITY);

        // Display thread details
        System.out.println(
                "Thread Name: "
                        + t1.getName()
                        + ", Priority: "
                        + t1.getPriority());

        System.out.println(
                "Thread Name: "
                        + t2.getName()
                        + ", Priority: "
                        + t2.getPriority());

        System.out.println(
                "Thread Name: "
                        + t3.getName()
                        + ", Priority: "
                        + t3.getPriority());

        // Check thread status before start
        System.out.println(
                "\nBefore Start:");

        System.out.println(
                "t1 Alive: "
                        + t1.isAlive());

        System.out.println(
                "t2 Alive: "
                        + t2.isAlive());

        System.out.println(
                "t3 Alive: "
                        + t3.isAlive());

        // Start threads
        t1.start();

        // join() demonstration
        t1.join();

        t2.start();
        t3.start();

        // Check thread status after start
        System.out.println(
                "\nAfter Start:");

        System.out.println(
                "t1 Alive: "
                        + t1.isAlive());

        System.out.println(
                "t2 Alive: "
                        + t2.isAlive());

        System.out.println(
                "t3 Alive: "
                        + t3.isAlive());

        // Wait for threads to finish
        t2.join();
        t3.join();

        // Final status
        System.out.println(
                "\nAfter Completion:");

        System.out.println(
                "t1 Alive: "
                        + t1.isAlive());

        System.out.println(
                "t2 Alive: "
                        + t2.isAlive());

        System.out.println(
                "t3 Alive: "
                        + t3.isAlive());

        System.out.println(
                "\nProgram Finished.");
    }
}
