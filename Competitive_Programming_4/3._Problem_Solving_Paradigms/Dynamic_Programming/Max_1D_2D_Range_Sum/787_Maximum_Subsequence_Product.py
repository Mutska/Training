import sys

for line in sys.stdin.readlines():
    S = line.split()
    A = [int(x) for x in S]

    minimum = A[0]
    maximum = A[0]
    result = A[0]
    for i in range(1,len(A)-1):
        candidate = max(A[i]* maximum, A[i]*minimum, A[i])
        minimum = min(A[i]* maximum, A[i]*minimum, A[i])
        maximum = candidate
        result = max(result, maximum)
    print(result)
