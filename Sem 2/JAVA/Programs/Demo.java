
class MyThread implements Runnable {
    public void run() {
        System.out.println("Thread is Running...");
    }
}

public class demo {
    public static void main(String[] args) {
        MyThread obj1 = new MyThread();
        Thread t1 = new Thread(obj1);
        t1.start();
    }
}