# 1) Create a set
s = {1, 2, 3}
print(s)
# Output
{1, 2, 3}

# 2) Add element
s = {10, 20}
s.add(30)
print(s)
# Output
{10, 20, 30}

# 3) Remove element
s = {10, 20, 30}
s.remove(20)
print(s)
# Output
{10, 30}

# 4) Union of sets
a = {1, 2, 3}
b = {3, 4, 5}
print(a.union(b))
# Output
{1, 2, 3, 4, 5}

# 5) Intersection
a = {1, 2, 3}
b = {2, 3, 4}
print(a.intersection(b))
# Output
{2, 3}

# 6) Discard item
s = {5,6,7}
s.discard(6)
print(s)
# Output:
# {5, 7}

# 7) Clear set
s = {1,2,3}
s.clear()
print(s)
# Output:
# set()

# 8) Difference
a = {1,2,3,4}
b = {3,4}
print(a.difference(b))
# Output:
# {1, 2}

# 9) Symmetric difference
a = {1,2,3}
b = {3,4,5}
print(a.symmetric_difference(b))
# Output:
# {1, 2, 4, 5}


# 10) Loop through set
s = {"a","b","c"}
for x in s:
    print(x)
# Output:
# c
# a
# b



