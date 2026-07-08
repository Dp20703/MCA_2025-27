package Sets;
class Download extends Thread {

    static int count = 0;

    Download(String name) {
        super(name);
    }

    public void run() {

        synchronized (Download.class) {

            while (count >= 2) {
                try {
                    Download.class.wait();
                } catch (Exception e) {
                }
            }

            count++;
        }

        System.out.println(getName() + " Download Started");

        try {
            Thread.sleep(2000);
        } catch (Exception e) {
        }

        System.out.println(getName() + " Download Completed");

        synchronized (Download.class) {
            count--;
            Download.class.notify();
        }

    }
}

public class P5B {

    public static void main(String[] args) {

        Download d1 = new Download("File1");
        Download d2 = new Download("File2");
        Download d3 = new Download("File3");
        Download d4 = new Download("File4");

        d1.start();
        d2.start();
        d3.start();
        d4.start();

    }
}