class Shared {
    boolean hasData = false;

    synchronized void produce() {
        System.out.println("Producer started");

        hasData = true;
        System.out.println("Data produced");

        notify(); // wake up consumer
    }

    synchronized void consume() {
        if (!hasData) {
            try {
                wait(); // wait until producer gives data
            } catch (Exception e) {}
        }

        System.out.println("Data consumed");
    }
}

class Producer extends Thread {
    Shared s;

    Producer(Shared s) {
        this.s = s;
    }

    public void run() {
        s.produce();
    }
}

class Consumer extends Thread {
    Shared s;

    Consumer(Shared s) {
        this.s = s;
    }

    public void run() {
        s.consume();
    }
}

public class prod_cons {
    public static void main(String[] args) {

        Shared s = new Shared();

        Consumer c = new Consumer(s);
        Producer p = new Producer(s);

        c.start(); // start consumer first (it will wait)
        p.start(); // then producer runs
    }
}