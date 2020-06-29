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

ll sumDiv(ll N) {
  ll n = N;  
  ll PF_idx = 0, PF = pr[PF_idx], ans = 1;  
  while (PF*PF <= N) {
    ll multiplier = PF, total = 1;
    while (N%PF == 0){
      N /= PF;
      total += multiplier;
      multiplier *= PF;
    }
    ans *= total;                                
    PF = pr[++PF_idx];
  }
  if (N != 1) ans *= (N+1);                      
  ans -= n;
  return ans;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    ll n;
    segmented_sieve(100000000);
    cin >> T;
    while(T--) {
        cin >> n;    
        cout << sumDiv(n) << "\n";
    }
}