import threading
import time

# Define a class that extends Thread
class MyThread(threading.Thread):
    def __init__(self, name):
        super().__init__()
        self.name = name

    def run(self):
        for i in range(5):
            print(f"{self.name} is running... {i}")
            time.sleep(1)   # Simulate work


# Main program
if __name__ == "__main__":
    # Create thread objects
    t1 = MyThread("Thread-1")
    t2 = MyThread("Thread-2")

    # Start the threads
    t1.start()
    t2.start()

    # Wait for both threads to finish
    t1.join()
    t2.join()

    print("Both threads have finished execution.")