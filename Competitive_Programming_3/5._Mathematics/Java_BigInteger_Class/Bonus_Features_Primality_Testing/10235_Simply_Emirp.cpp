#include<iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;
using u64 = unsigned long long int;
using u128 = unsigned long long int;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}
bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    string cmp;
    while(cin >> N) {
        if(MillerRabin(N)) {
            string integer = patch::to_string(N);
            cmp = integer;
            reverse(integer.begin(), integer.end());
            int M = stoi(integer);
            if(MillerRabin(M) && cmp != integer) cout << N << " is emirp.\n";
            else cout << N << " is prime.\n";
        } else {
            cout << N << " is not prime.\n";
        }

    }



    return 0;
}
