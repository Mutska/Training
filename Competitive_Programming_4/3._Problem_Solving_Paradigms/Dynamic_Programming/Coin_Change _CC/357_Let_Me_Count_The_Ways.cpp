#include <iostream>

using namespace std;
int coins[5] = {1, 5, 10, 25, 50};
long long dp[30005];

int main() {    
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[0] = 1;
    for(int c = 0; c < 5; ++c){
        for (int i = coins[c]; i <= 30000; ++i) dp[i] += dp[i-coins[c]];
    }
    long long cents;
    while(cin >> cents) {
        if (dp[cents] == 1) cout << "There is only 1 way to produce " << cents << " cents change.\n";
        else cout << "There are " << dp[cents] << " ways to produce " << cents << " cents change.\n";
    }
    return 0;
}