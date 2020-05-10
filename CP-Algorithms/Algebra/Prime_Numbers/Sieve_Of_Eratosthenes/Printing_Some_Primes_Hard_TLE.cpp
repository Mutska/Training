//Sphere Online Judge Problem
#include <iostream>
#include <bitset>

using namespace std;

using ll = long long;
ll _sieve_size;
bitset<1000000002> bs;                     


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    _sieve_size = 1000000001;                     
     bs.set();                                       
     cout << "2\n";
     int f = 3, d = 0, increments[8] = {4, 2, 4, 2, 4, 6, 2, 6};
    for (ll i = 7; i < _sieve_size; i += increments[d++]) {if (bs[i]) {
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
        if(f % 500 == 0)
            cout << i << "\n";
        ++f;
    }
    if(d == 8) d = 0;
    }


}
  
