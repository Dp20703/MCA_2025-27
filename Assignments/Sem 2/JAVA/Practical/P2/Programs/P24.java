// Unit-11
// Q1

class Buffer {

    private int data;
    private boolean available = false;

    // Producer method
    public synchronized void produce(int value)
            throws InterruptedException {

        // Wait if data already available
        while (available) {
            wait();
        }

        data = value;

        System.out.println(
                "Produced: " + data);

        available = true;

        // Notify consumer
        notify();
    }

    // Consumer method
    public synchronized void consume()
            throws InterruptedException {

        // Wait if no data available
        while (!available) {
            wait();
        }

        System.out.println(
                "Consumed: " + data);

        available = false;

        // Notify producer
        notify();
    }
}

// Producer Thread using Thread class
class Producer extends Thread {

    Buffer buffer;

    // Constructor
    Producer(Buffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {

        try {

            for (int i = 1; i <= 5; i++) {

                buffer.produce(i);

                // sleep() demonstration
                Thread.sleep(1000);
            }

        } catch (InterruptedException e) {

            System.out.println(e);
        }
    }
}

// Consumer Thread using Runnable interface
class Consumer implements Runnable {

    Buffer buffer;

    // Constructor
    Consumer(Buffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {

        try {

            for (int i = 1; i <= 5; i++) {

                buffer.consume();

                // yield() demonstration
                Thread.yield();
            }

        } catch (InterruptedException e) {

            System.out.println(e);
        }
    }
}

public class P24 {

    public static void main(String[] args)
            throws InterruptedException {

        // Shared Buffer
        Buffer buffer = new Buffer();

        // Producer thread
        Producer producer = new Producer(buffer);

        // Consumer thread
        Thread consumer = new Thread(
                new Consumer(buffer));

        // Assign thread names
        producer.setName("ProducerThread");
        consumer.setName("ConsumerThread");

        // Assign priorities
        producer.setPriority(Thread.MAX_PRIORITY);
        consumer.setPriority(Thread.MIN_PRIORITY);

        // Display thread details
        System.out.println(
                "Producer Thread: "
                        + producer.currentThread());

        System.out.println(
                "Consumer Thread: "
                        + consumer.currentThread());

        // Check thread state before start
        System.out.println(
                "\nBefore Start:");

        System.out.println(
                "Producer Alive: "
                        + producer.isAlive());

        System.out.println(
                "Consumer Alive: "
                        + consumer.isAlive());

        // Start threads
        producer.start();
        consumer.start();

        // Check thread state after start
        System.out.println(
                "\nAfter Start:");

        System.out.println(
                "Producer Alive: "
                        + producer.isAlive());

        System.out.println(
                "Consumer Alive: "
                        + consumer.isAlive());

        // Wait for threads to finish
        producer.join();
        consumer.join();

        // Final thread state
        System.out.println(
                "\nAfter Completion:");

        System.out.println(
                "Producer Alive: "
                        + producer.isAlive());

        System.out.println(
                "Consumer Alive: "
                        + consumer.isAlive());

        System.out.println(
                "\nProgram Finished.");
    }
}