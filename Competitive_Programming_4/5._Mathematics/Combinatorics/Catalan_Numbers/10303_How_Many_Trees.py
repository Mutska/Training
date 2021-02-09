import sys

def Cat(n):
    K = n
    N = 2*n
    C = 1
    for i in range(0,K):
        C = C*(N-i)
        C = C // (i+1)
    Cat = C // (n + 1)
    return Cat

while True:
  input = sys.stdin.readline()
  if not input: break
  n = int(input)
  print(Cat(n))
    
