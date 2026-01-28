import threading
from statistics import mean, median, mode, StatisticsError

# Functions to calculate mean, median, and mode
def calculate_mean(data):
    try:
        print("Mean:", mean(data))
    except Exception as e:
        print("Error calculating mean:", e)

def calculate_median(data):
    try:
        print("Median:", median(data))
    except Exception as e:
        print("Error calculating median:", e)

def calculate_mode(data):
    try:
        print("Mode:", mode(data))
    except StatisticsError:
        print("Mode: No unique mode found")
    except Exception as e:
        print("Error calculating mode:", e)

# Main program
try:
    data = list(map(int, input("Enter numbers separated by space: ").split()))

    if len(data) == 0:
        raise ValueError("Empty list is not allowed")

    # Creating threads
    t1 = threading.Thread(target=calculate_mean, args=(data,))
    t2 = threading.Thread(target=calculate_median, args=(data,))
    t3 = threading.Thread(target=calculate_mode, args=(data,))

    # Starting threads
    t1.start()
    t2.start()
    t3.start()

    # Waiting for threads to complete
    t1.join()
    t2.join()
    t3.join()

except ValueError as ve:
    print("Input Error:", ve)
except Exception as e:
    print("Unexpected Error:", e)
