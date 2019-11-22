
def pow_mod(x, y, z):
    n = 1
    while y:
        if y & 1:
            n = n * x % z
        y >>= 1
        x = x * x % z
    return n

print(10 * pow_mod(9,10,1000000007))
