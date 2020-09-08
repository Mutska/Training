#include <iostream>
#include <string>

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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string temp, check;
    u64 prime, max;
    while(cin >> check) {
        if(check == "0") break;
        max = 0ULL;
        for(int i = 0; i < (int) check.length(); i++) {
            for(int len = 1; len <= ((int) check.length())-i; len++) {
                if(len > 5) break;
                temp = check.substr(i, len);
                prime = stoull(temp);
                if(MillerRabin(prime)) 
                  if(prime > max) max = prime;
                
            }
        }
        cout << max << "\n";


    }




    return 0;
}