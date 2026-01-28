# Creating sets
A = {1, 2, 3, 4, 5}
B = {4, 5, 6, 7, 8}

print("Set A:", A)
print("Set B:", B)

# Union
print("\nUnion of A and B:", A | B)          # or A.union(B)

# Intersection
print("Intersection of A and B:", A & B)     # or A.intersection(B)

# Difference
print("Difference (A - B):", A - B)          # or A.difference(B)
print("Difference (B - A):", B - A)

# Symmetric Difference
print("Symmetric Difference:", A ^ B)        # or A.symmetric_difference(B)

# Membership Test
print("\nMembership Test:")
print("Is 3 in set A?", 3 in A)
print("Is 9 in set B?", 9 in B)

# Adding and Removing Elements
print("\nAdding and Removing Elements:")
A.add(10)
print("After adding 10 to A:", A)
A.remove(2)
print("After removing 2 from A:", A)

# Subset, Superset, and Disjoint Tests
print("\nSet Relations:")
C = {4, 5}
print("C:", C)
print("Is C subset of A?", C.issubset(A))
print("Is A superset of C?", A.issuperset(C))
print("Are A and B disjoint?", A.isdisjoint(B))

# Copying a set
D = A.copy()
print("\nCopy of A (D):", D)

# Clearing a set
D.clear()
print("After clearing D:", D)
