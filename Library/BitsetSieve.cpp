#include "Template.h"

ll _sieve_size;
bitset<109> bs;                    
vll primes;               


void sieve(ll upperbound) {          
  _sieve_size = upperbound+1;                     
  bs.set();                                       
  bs[0] = bs[1] = 0;                              
  primes.emplace_back(2);
  for (ll i = 3; i < _sieve_size; i += 2) if (bs[i]) {
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    primes.emplace_back(i);       
  } 
}                                           

int main() {
  sieve(100);
  for(ll p: primes)
    cout << p << " ";
  cout << "\n";
}
