import sys

fibonacci = [0 for i in range(5010)]

fibonacci[0] = 0
fibonacci[1] = 1

for i in range(2, 5010):
    fibonacci[i] = fibonacci[i-1] + fibonacci[i-2]

while(True):
    input = sys.stdin.readline()
    if not input: break
    n = int(input)
    print("The Fibonacci number for {} is {}".format(n, fibonacci[n]))


