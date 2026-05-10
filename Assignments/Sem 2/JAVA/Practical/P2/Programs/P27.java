// Unit-11
// Q4

class DownloadManager {

    // Maximum downloads allowed at same time
    private int availableSlots = 2;

    // Start download
    public synchronized void startDownload(
            String fileName
    ) throws InterruptedException {

        // Wait if no slot available
        while (availableSlots == 0) {

            System.out.println(
                    fileName
                    + " is waiting for download slot..."
            );

            wait();
        }

        // Occupy slot
        availableSlots--;

        System.out.println(
                "\nDownload Started: "
                + fileName
        );

        // Simulate download time
        Thread.sleep(3000);

        System.out.println(
                "Download Completed: "
                + fileName
        );

        // Release slot
        availableSlots++;

        // Notify waiting threads
        notifyAll();
    }
}

// Thread class for file download
class FileDownload extends Thread {

    DownloadManager manager;
    String fileName;

    // Constructor
    FileDownload(
            DownloadManager manager,
            String fileName
    ) {

        this.manager = manager;
        this.fileName = fileName;
    }

    @Override
    public void run() {

        try {

            manager.startDownload(fileName);

        } catch (InterruptedException e) {

            System.out.println(e);
        }
    }
}

public class P27 {

    public static void main(String[] args) {

        // Shared Download Manager
        DownloadManager manager =
                new DownloadManager();

        // Create multiple download threads
        FileDownload f1 =
                new FileDownload(
                        manager,
                        "JavaNotes.pdf"
                );

        FileDownload f2 =
                new FileDownload(
                        manager,
                        "Movie.mp4"
                );

        FileDownload f3 =
                new FileDownload(
                        manager,
                        "Music.mp3"
                );

        FileDownload f4 =
                new FileDownload(
                        manager,
                        "Project.zip"
                );

        // Start downloads
        f1.start();
        f2.start();
        f3.start();
        f4.start();
    }
}

