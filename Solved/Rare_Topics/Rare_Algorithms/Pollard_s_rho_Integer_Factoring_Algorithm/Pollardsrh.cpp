#include <iostream>
#include <map>

using namespace std;

typedef unsigned long long ULL;

map<ULL, int> factorization;

ULL modular_mul(ULL a, ULL b, ULL modulus)
{
    ULL result = 0;
    a %= modulus;

    while(b > 0) {
        if(b & 1) {
            result = (result + a) % modulus;
        }

        a = (a << 1) % modulus;             // a = (a * 2) % modulus.
        b >>= 1;                            // b /= 2.
    }

    return result % modulus;
}

ULL binpower(ULL base, ULL exponent, ULL modulus)
{
    if(modulus == 1) return 0;

    ULL result = 1;
    base %= modulus;

    while(exponent > 0) {
        if(exponent & 1) {
            result = modular_mul(result, base, modulus);
        }

        exponent >>= 1;
        base = modular_mul(base, base, modulus);
    }

    return result;
}

bool isPrime(ULL n, int iteration)
{
    if(n < 2) return false;
    if(n <= 3) return true;
    if(!(n & 1)) return false;              // If n is even.

    ULL d = n-1;                            // d * 2^r = n-1 where d is odd and r > 0.
    while(!(d & 1))
        d >>= 1;

    while(iteration--) {                    // Witness loop.
        ULL a = rand() % (n-1) + 1;
        ULL x = binpower(a, d, n);       // x = a^d % n
        ULL d1 = d;

        while(d1 != n-1 && x != 1 && x != n-1) {
            x = modular_mul(x, x, n);       // x = (x * x) % n.
            d1 <<= 1;
        }

        if(x != n-1 && !(d1 & 1)) {
            return false;
        }
    }

    return true;
}

ULL gcd (ULL a, ULL b) {
    return b ? gcd (b, a % b) : a;
}

ULL f(ULL x, ULL b, ULL n){
    return (binpower(x,2,n) + b) % n; // x = (x^2 % n + b) %n
}


ULL rho(ULL n){
    if(!(n&1)) return 2;
    ULL b = rand() % n + 1;
    ULL x = rand() % n + 1;
    ULL y = x;
    ULL d = 1;
    while(true){
        x = f(x, b, n);
        y = f(f(y,b,n), b, n);
        d = (x > y) ? gcd(x - y, n ): gcd(y - x, n);
        if(d != 1) return d;
    }
}

void pollard_rho(ULL n){
    if(n == 1) return;
    if(isPrime(n, 20)){
        factorization[n]++;
        return;
    }
    ULL divisor = rho(n);
    pollard_rho(divisor);
    pollard_rho(n/divisor);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    ULL n;
   cin >> T;
   while(T--){
       cin >> n;
       pollard_rho(n);
       cout << n << " = ";
       if(factorization.size() == 1) {
           auto first = *(factorization.begin());
           cout << first.first;
           if(first.second != 1) cout << "^" << first.second; 
           cout << "\n";
       }
       else{
           auto first = *(factorization.begin());
           cout << first.first;
           if(first.second != 1) cout << "^" << first.second; 
           int c = 0;
           for(auto f: factorization){
               if(c == 0){
                   ++c;
                   continue;
               }
               cout << " * " << f.first;
               if(f.second != 1) cout << "^" << f.second;
           }
           cout << "\n";
       }
       factorization.clear();
   }

    return 0;
}