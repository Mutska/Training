while True:
    n = int(input())
    if n == 0: break
    trees = 1
    for i in range(n+2, 2*n+1):
        trees *= i
    print(trees)