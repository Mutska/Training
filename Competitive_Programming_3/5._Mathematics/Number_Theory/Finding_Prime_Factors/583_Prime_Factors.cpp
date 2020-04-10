
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;
using u64 = unsigned long long int;
using u128 = unsigned long long int;

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

vector<u64> trial_division3(u64 n) {
    vector<u64> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    static array<u64, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (u64 d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long N, M;

    while(cin >> N, (N || 0)) {
        vector<u64> factorization;
        if(N < 0) M = (u64) (N*-1);
        else M = (u64) N;
        if(MillerRabin(M) && N < 0) cout << N  << " = -1 x " << M << "\n";
        if(MillerRabin(M) && N > 0) cout << M  << " = " << M << "\n"; 
        if(!MillerRabin(M) && N > 0) {
            factorization = trial_division3(M);
            cout << M << " = ";
            int size = factorization.size();
            for(int i = 0; i < size; i++) {
                cout << factorization[i];
                if(i + 1 != size) cout << " x ";
            }
            cout << "\n";

        }
        if(!MillerRabin(M) && N < 0) {
            factorization = trial_division3(M);
            cout << "-" << M << " = -1 x ";
            int size = factorization.size();
            for(int i = 0; i < size; i++) {
                cout << factorization[i];
                if(i + 1 != size) cout << " x ";
            }
            cout << "\n";
        }
    }

    return 0;

}