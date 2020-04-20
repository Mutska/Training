#include "Template.h"
//Extending the wheel factorization with more and more primes 
//will leave exactly the primes to check.
//So a good way of checking is just to precompute all 
//prime numbers with the Sieve of Eratosthenes until
// root of n and test them individually.
vector<long long> primes;

vector<long long> precomputed_factorization(long long n) {
    vector<long long> factorization;
    for (long long d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main() {

    return 0;
}