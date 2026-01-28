import threading

# Bubble Sort
def bubble_sort(arr):
    a = arr.copy()
    n = len(a)
    for i in range(n):
        for j in range(0, n - i - 1):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
    print("Bubble Sort:", a)

# Selection Sort
def selection_sort(arr):
    a = arr.copy()
    n = len(a)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if a[j] < a[min_idx]:
                min_idx = j
        a[i], a[min_idx] = a[min_idx], a[i]
    print("Selection Sort:", a)

# Insertion Sort
def insertion_sort(arr):
    a = arr.copy()
    for i in range(1, len(a)):
        key = a[i]
        j = i - 1
        while j >= 0 and key < a[j]:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = key
    print("Insertion Sort:", a)

# Main Program
try:
    data = list(map(int, input("Enter numbers separated by space: ").split()))

    if len(data) == 0:
        raise ValueError("List cannot be empty")

    # Create threads
    t1 = threading.Thread(target=bubble_sort, args=(data,))
    t2 = threading.Thread(target=selection_sort, args=(data,))
    t3 = threading.Thread(target=insertion_sort, args=(data,))

    # Start threads
    t1.start()
    t2.start()
    t3.start()

    # Wait for threads to complete
    t1.join()
    t2.join()
    t3.join()

except ValueError as ve:
    print("Input Error:", ve)
except Exception as e:
    print("Error:", e)
