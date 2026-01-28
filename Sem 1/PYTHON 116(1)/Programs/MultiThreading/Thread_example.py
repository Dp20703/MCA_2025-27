import threading

# (a) Find prime numbers from 1 to 1000
def find_primes():
    print("\nPrime numbers from 1 to 1000:")
    for num in range(2, 1001):
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                break
        else:
            print(num, end=" ")
    print()

# (b) Calculate sum of first n natural numbers
def sum_n(n):
    if n < 1:
        print("\nSum: Invalid input")
    else:
        total = n * (n + 1) // 2
        print(f"\nSum of first {n} natural numbers =", total)

# (c) Calculate factorial of n
def factorial(n):
    fact = 1
    for i in range(2, n + 1):
        fact *= i
    print(f"\nFactorial of {n} =", fact)

# (d) Generate Fibonacci series till n terms
def fibonacci_series(n):
    print(f"\nFibonacci series till {n} terms:")
    a, b = 0, 1
    for _ in range(n):
        print(a, end=" ")
        a, b = b, a + b
    print()

# -------- Main Program (Multithreading) --------

t1 = threading.Thread(target=find_primes)
t2 = threading.Thread(target=sum_n, args=(4,))
t3 = threading.Thread(target=factorial, args=(20,))
t4 = threading.Thread(target=fibonacci_series, args=(10,))

t1.start()
t2.start()
t3.start()
t4.start()

t1.join()
t2.join()
t3.join()
t4.join()
