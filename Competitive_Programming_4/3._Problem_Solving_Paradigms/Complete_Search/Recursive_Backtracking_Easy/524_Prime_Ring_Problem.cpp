#include <iostream>
#include <vector>
using namespace std;
int N, Case = 0;
vector<int> solutions;

using u64 = unsigned long long int;
u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u64)result * base % mod;
        base = (u64)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u64)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};


bool  MillerRabinDeterministic(u64 n) { 
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

bool canAdd(int n) {
    for(auto &s: solutions)
        if(s == n) return false;
    int possible_prime = n + solutions.back();
    cout << "possible prime is: " << possible_prime << "\n";
    if(MillerRabinDeterministic(possible_prime)) return true;
    return false;
}

void backtrack() {
    cout << "N is: " << N << "\n";
    cout << "size is: " << solutions.size() << "\n";
    if(solutions.size() == N) {
        int check = solutions.back() + 1;
        if(!(MillerRabinDeterministic(check))) return;
        cout << solutions[0];
        for(int i = 1; i < N; ++i) cout << " " << solutions[i];
        cout << "\n";
    }
    for(int i = 2; i <= N; ++i) {
        cout << "i is: " << i << "\n";
        if(canAdd(i)){
            cout << "in fact " << i  << " with " << solutions.back() << " is prime\n";
            solutions.push_back(i);
            backtrack();
            solutions.pop_back();
        }
    }
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> N;
    solutions.push_back(1);
    cout << "Case " << ++Case << ":\n";
    backtrack();
    solutions.clear();
    while(cin >> N) {
        if(!cin.eof()) cout << "\n";
        solutions.push_back(1);
        cout << "Case " << ++Case << ":\n";
        backtrack();
        solutions.clear();
    }

    return 0;
}