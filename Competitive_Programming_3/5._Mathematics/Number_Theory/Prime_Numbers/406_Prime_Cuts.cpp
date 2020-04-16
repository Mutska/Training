#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll _sieve_size;
bitset<10001> bs;                     


void  sieve(ll upperbound, vll & primes) {          
  _sieve_size = upperbound+1;                     
  bs.set();                                       
  bs[0] = bs[1] = 0;                              
  primes.push_back(1);
  for (ll i = 2; i < _sieve_size; i++) if (bs[i]) {
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    primes.push_back(i);       
  } 
}                                           
  
int main() {
    int N, C;
    int left, right, mid, cut;
    while(cin >> N >> C){
        vll primes;
        sieve(N, primes);
        if((int)primes.size() % 2) {
            cout << N << " " << C << ":";
            if((2*C-1) > primes.size()){
                for(int p: primes)
                    cout <<" " << p;
                cout << "\n\n";
                continue; 
            }
            mid = ((int) primes.size() - 1) / 2;
            cut = 2*C - 2;
            cut /= 2;
            left = mid - cut;
            right = mid + cut;
            for(int i = left; i <= right; i++)
                cout << " "<< primes[i] ;
            cout << "\n\n";

        }else{
            cout << N << " " << C << ":";
            if((2*C) > primes.size()){
                for(int p: primes)
                    cout <<" " << p;
                cout << "\n\n";
                continue; 
            }
            mid = ceil((double)  (primes.size() - 1) / 2);
            cut = 2*C - 1;
            cut = (int) ceil(((double) cut / 2));
            left = mid - cut;
            right = mid + cut - 1;
            for(int i = left; i <= right; i++)
                cout << " "<< primes[i] ;
            cout << "\n\n";
        }

    }


    return 0;
}