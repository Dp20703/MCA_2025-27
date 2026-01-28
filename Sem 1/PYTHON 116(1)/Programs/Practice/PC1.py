import threading
import time
from queue import Queue

# Shared queue
buffer = Queue(maxsize=5)

# Producer Thread
class Producer(threading.Thread):
    def run(self):
        for i in range(10):
            item = f"Item-{i}"
            buffer.put(item)   # Automatically synchronized
            print(f"Producer produced: {item}")
            time.sleep(1)
        buffer.put(None)  # Signal consumer to stop

# Consumer Thread
class Consumer(threading.Thread):
    def run(self):
        while True:
            item = buffer.get()
            if item is None:   # Stop condition
                break
            print(f"Consumer consumed: {item}")
            time.sleep(1)


# Main program
if __name__ == "__main__":
    p = Producer()
    c = Consumer()

    p.start()
    c.start()

    p.join()
    c.join()

    print("Producer-Consumer execution completed.")