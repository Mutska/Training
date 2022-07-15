#include <iostream>
#include <vector>

using namespace std;
long long dp[10005];

int main() {    
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> coins;
    for(int i = 1; i <= 21; ++i) coins.push_back(i*i*i);
    dp[0] = 1;
    for(int c = 0; c < 21; ++c){
        for (int i = coins[c]; i <= 10005; ++i) dp[i] += dp[i-coins[c]];
    }
    long long cents;
    while(cin >> cents) {
        cout << dp[cents] << "\n";
    }
    return 0;
}