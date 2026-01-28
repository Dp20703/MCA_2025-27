import time

# Function to check if a number is prime
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):  # Check divisibility up to sqrt(n)
        if n % i == 0:
            return False
    return True

# Function to find all prime numbers up to a given limit
def compute_primes(limit):
    primes = []
    for num in range(2, limit + 1):
        if is_prime(num):
            primes.append(num)
    return primes

# Heavy computation: Find primes up to a big number
start = time.time()
limit = 2000000  # You can increase this for heavier load
primes = compute_primes(limit)
end = time.time()

print(f"Total primes found up to {limit}: {len(primes)}")
print(f"Time taken: {end - start:.2f} seconds")