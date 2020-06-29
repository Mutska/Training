//Sphere Online Judge Problem
#include <iostream>
#include <vector>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdint>


using namespace std;
using ll = long long;

typedef vector<int> vi;
typedef vector<ll> vll;
vll pr;
const int64_t L1D_CACHE_SIZE = 32768;

int x = 1;
void segmented_sieve(int64_t limit) {

  int64_t sqrt = (int64_t) std::sqrt(limit);
  int64_t segment_size = max(sqrt, L1D_CACHE_SIZE);
  pr.emplace_back(2);

  int64_t i = 3;
  int64_t n = 3;
  int64_t s = 3;

  vector<char> sieve(segment_size);
  vector<char> is_prime(sqrt + 1, true);
  vector<int64_t> primes;
  vector<int64_t> multiples;

  for (int64_t low = 0; low <= limit; low += segment_size) {
    fill(sieve.begin(), sieve.end(), true);

    int64_t high = low + segment_size - 1;
    high = min(high, limit);

    for (; i * i <= high; i += 2)
      if (is_prime[i])
        for (int64_t j = i * i; j <= sqrt; j += i)
          is_prime[j] = false;

    for (; s * s <= high; s += 2) {
      if (is_prime[s]) {
        primes.push_back(s);
        multiples.push_back(s * s - low);
      }
    }

    for (size_t i = 0; i < primes.size(); i++) {
      int64_t j = multiples[i];
      for (int64_t k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = false;
      multiples[i] = j - segment_size;
    }

    for (; n <= high; n += 2) {
      if (sieve[n - low]) 
        pr.emplace_back(n);
    }
  }

}

int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

ll numDiv(ll N) {
  ll PF_idx = 0, PF = pr[PF_idx], ans = 1;   
  while (PF*PF <= N) {
    ll power = 0;                                
    while (N%PF == 0) { N /= PF; ++power; }
    ans *= (power+1);                            
    PF = pr[++PF_idx];
  }
  return (N != 1) ? 2*ans : ans;                 
}


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    ll n, a, b;
    segmented_sieve(1000000);
    
    cin >> T;
    while(T--) {
        cin >> a >> b;
        n = gcd(a, b);    
        cout << numDiv(n) << "\n";
    } 
}