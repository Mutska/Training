#include <iostream>
#include <string>
#include <unordered_map>

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




unordered_map<char, int> word_index;

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
word_index['a'] = 1; 
word_index['b'] = 2; 
word_index['c'] = 3; 
word_index['d'] = 4; 
word_index['e'] = 5; 
word_index['f'] = 6; 
word_index['g'] = 7; 
word_index['h'] = 8; 
word_index['i'] = 9; 
word_index['j'] = 10;
word_index['k'] = 11;
word_index['l'] = 12;
word_index['m'] = 13;
word_index['n'] = 14;
word_index['o'] = 15;
word_index['p'] = 16;
word_index['q'] = 17;
word_index['r'] = 18;
word_index['s'] = 19;
word_index['t'] = 20;
word_index['u'] = 21;
word_index['v'] = 22;
word_index['w'] = 23;
word_index['x'] = 24;
word_index['y'] = 25;
word_index['z'] = 26;
word_index['A'] = 27; 
word_index['B'] = 28; 
word_index['C'] = 29; 
word_index['D'] = 30; 
word_index['E'] = 31; 
word_index['F'] = 32; 
word_index['G'] = 33; 
word_index['H'] = 34; 
word_index['I'] = 35; 
word_index['J'] = 36;
word_index['K'] = 37;
word_index['L'] = 38;
word_index['M'] = 39;
word_index['N'] = 40;
word_index['O'] = 41;
word_index['P'] = 42;
word_index['Q'] = 43;
word_index['R'] = 44;
word_index['S'] = 45;
word_index['T'] = 46;
word_index['U'] = 47;
word_index['V'] = 48;
word_index['W'] = 49;
word_index['X'] = 50;
word_index['Y'] = 51;
word_index['Z'] = 52;

    string word;
    int sum;
    while(cin >> word) {
        sum = 0;
        if(word == "a") {cout << "It is a prime word.\n"; continue;}
        for(auto l: word)
            sum+= word_index[l];
        if(MillerRabin(sum)) cout << "It is a prime word.\n";
        else cout << "It is not a prime word.\n";    

    }
    return 0;
}