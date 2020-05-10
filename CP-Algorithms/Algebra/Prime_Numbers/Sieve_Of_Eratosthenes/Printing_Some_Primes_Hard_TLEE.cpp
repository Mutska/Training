//Sphere Online Judge Problem
#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

using ll = long long;


    ll lim = sqrtl(1000000000LL);
    vector<bool> mark(31623, false);
    vector<ll> primes;
    int x = 0;
    void segmentedSieve(ll L, ll R) {

    vector<bool> isPrime(R - L + 1, true);
    ll limit = sqrtl(R);
    for (long long i : primes) {
        if(i > limit) break;
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    }
    
    int  j = 0;
    for( ll i = L; i <= R; ++i) {
        if(isPrime[j]) {
            if(x % 500 == 0)
                cout << i << "\n";
            ++x;
        }
        ++j;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int d = 0;
    primes.emplace_back(2);
    primes.emplace_back(3);
    primes.emplace_back(5);
    primes.emplace_back(7);
    static array<ll, 48> increments = { 2LL,  4LL,  2LL,  4LL,  6LL,  2LL,  6LL,  4LL,  
    2LL,  4LL,  6LL,  6LL,  2LL,  6LL,  4LL,  2LL,  6LL,  4LL,  6LL,  8LL,  4LL,  2LL,  4LL,  2LL,  4LL,  8LL,  6LL,  4LL,  6LL,  2LL,  4LL,  6LL,  2LL,  6LL,  6LL,  4LL,  
    2LL,  4LL,  6LL,  2LL,  6LL,  4LL,  2LL,  4LL,  2LL,  10LL,  2LL,  10LL};
    // generate all primes up to sqrt(R)
    for (ll i = 11; i <= lim; i+= increments[d++]) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (ll j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
        if(d == 48) d = 0;
    }
    //1 a 100000000
    ll L = 2LL;
    ll R = 50000000LL;
    segmentedSieve(L, R);
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);

    //100000001 a 200000000
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);


    //200000001 a 300000000
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);
    
    //300000001 a 400000000
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);


    //400000001 a 500000000
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);


    //500000001 a 600000000
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);


    //600000001 a 700000000
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);


    //700000001 a 800000000
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);
    //800000001 a 900000000
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);
    //900000001 a 1000000000
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);
    L = R + 1LL;
    R += 50000000LL;
    segmentedSieve(L, R);

    return 0;
}
