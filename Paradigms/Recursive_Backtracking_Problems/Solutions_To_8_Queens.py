import itertools as it
a = 0
def is_solution(perm):
    for (i1, i2) in it.combinations(range(len(perm)), 2):
        if abs(i1 - i2) == abs(perm[i1] - perm[i2]):
            return False

    return True

for perm in it.permutations(range(8)):
    if is_solution(perm):
        print(perm)
        a = a + 1

print(a)