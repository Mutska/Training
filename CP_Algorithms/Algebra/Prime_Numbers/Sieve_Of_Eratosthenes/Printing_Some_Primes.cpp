//Sphere Online Judge Problem
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

using ll = long long;

ll _sieve_size;
bitset<100000010> bs;                     


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << "2\n";
    int j = 1;                              
    _sieve_size = 100000001;                     
     bs.set();                                       
    for (ll i = 3; i < _sieve_size; i+=2) if (bs[i]) {
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    if(j % 100 == 0)
      cout << i << "\n";
    ++j;
  } 


}
  