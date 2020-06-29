//Sphere Online Judge Problem
#include <iostream>
#include <bitset>
#include <vector>


using namespace std;
using ll = long long;

typedef vector<int> vi;
typedef vector<ll> vll;

ll _sieve_size;
bitset<500010> bs;                             
vll primes;                                      


// first part

void sieve(ll upperbound) {                      
  _sieve_size = upperbound+1;                    
  bs.set(); bs[0] = bs[1] = 0;                   
  for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    primes.push_back(i);                         
  }
}

ll sumDiv(ll N) {
  ll n = N;  
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;  
  while (PF*PF <= N) {
    ll multiplier = PF, total = 1;
    while (N%PF == 0){
      N /= PF;
      total += multiplier;
      multiplier *= PF;
    }
    ans *= total;                                
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= (N+1);                      
  ans -= n;
  return ans;
}

int main () {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int T;
    sieve(500000);
    ll n;
    cin >> T;
    while(T--) {
        cin >> n;    
        cout << sumDiv(n) << "\n";
    }
}