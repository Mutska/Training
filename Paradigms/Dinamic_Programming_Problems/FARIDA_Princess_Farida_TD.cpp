#include <iostream>
#include <cstring>
//Spoj
int N;
//Maximum sum such that no two elements are adjacent 

using namespace std;
long long monster[10010];
long long memo[10010];

long long dp(int i) {
    if(i < 0) return 0;
    long long &ans = memo[i];
    if(ans != -1) return ans;
    return ans = max(dp(i-1), monster[i] + dp(i-2));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T,Cases = 0;
    cin >> T;
    while(T--) {
       cin >> N;
       memset(memo, -1, sizeof memo);
       for(int i = 0; i < N; ++i) cin >> monster[i];
       cout << "Case " << ++Cases << ": " << dp(N - 1) << "\n";
    }

    return 0;
}

