#include <iostream>
#include <cstring>
#include <vector>


using namespace std;
vector<int> coin;
int m, dp[60000];

//int dp(int id, int rem) {
//    if (id == m || rem == 0) return 0;
//    int &ans = memo[id][rem];
//    if (ans != -1) return ans;
//    if (coin[id] > rem) return ans = dp(id + 1, rem);
//    return ans = max(dp(id + 1, rem), coin[id] + dp(id + 1, rem - coin[id]));
//}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        memset(dp, 0, sizeof dp);
        cin >> m;
        coin.assign(m,0);
        int sum = 0;
        for(int i = 0; i < m; ++i) cin >> coin[i], sum += coin[i];
        int target = sum / 2;
        for (int i = 0; i < m; ++i) {
            for(int j = target; j >= coin[i]; --j) dp[j] = max(dp[j], dp[j-coin[i]] + coin[i]);
            //for(int c = 0; c <= 20; ++c) cout << dp[c] << " ";
            //cout << "\n";
            //for(int j = coin[i]; j <= target; ++j) dp[j] = max(dp[j], dp[j-coin[i]] + coin[i]);
        }
        //cout << "dp[target] is " << dp[target] << "\n";
        cout << sum - dp[target] - dp[target] << "\n";
    }



    return 0;
}