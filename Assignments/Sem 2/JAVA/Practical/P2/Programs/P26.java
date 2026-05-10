// Unit-11
// Q3

class MyThread extends Thread {

    @Override
    public void run() {

        try {

            for (int i = 1; i <= 5; i++) {

                System.out.println(
                        getName()
                        + " is running : "
                        + i
                );

                // sleep() demonstration
                Thread.sleep(1000);
            }

        } catch (InterruptedException e) {

            System.out.println(e);
        }
    }
}

public class P26 {

    public static void main(String[] args)
            throws InterruptedException {

        // Display current main thread
        System.out.println(
                "Current Main Thread: "
                + Thread.currentThread()
        );

        // Rename main thread
        Thread.currentThread()
                .setName("MainThread");

        System.out.println(
                "\nRenamed Main Thread: "
                + Thread.currentThread()
        );

        // Create thread
        MyThread t1 = new MyThread();

        // Assign thread name
        t1.setName("ChildThread");

        // Thread state before start
        System.out.println(
                "\nBefore start(): "
                + t1.getState()
        );

        // Check isAlive before start
        System.out.println(
                "Is Thread Alive? "
                + t1.isAlive()
        );

        // Start thread
        t1.start();

        // Thread state after start
        System.out.println(
                "\nAfter start(): "
                + t1.getState()
        );

        // Check isAlive after start
        System.out.println(
                "Is Thread Alive? "
                + t1.isAlive()
        );

        // Wait for thread completion
        t1.join();

        // Thread state after completion
        System.out.println(
                "\nAfter completion: "
                + t1.getState()
        );

        // Check isAlive after completion
        System.out.println(
                "Is Thread Alive? "
                + t1.isAlive()
        );

        System.out.println(
                "\nProgram Finished."
        );
    }
}
