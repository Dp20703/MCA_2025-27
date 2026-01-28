import cProfile

def sum():
    total=0
    for i in range(1000000):
        total+=i
    return total

cProfile.run("sum()")