#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


int n, w;
vector<int> V, W;
int dp[32][1002];
vector <pair<int, int>> solution;


void backtrack(int n, int t, int res) {

    for(int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i-1][t]) continue;
        solution.push_back({W[i-1]/(3*w), V[i-1]});
        res -= V[i-1];
        t -= W[i-1];
  }

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, c = 0;
    while(cin >> t >> w) {
        if (c > 0) cout << "\n";
        cin >> n;
        V.assign(n, 0), W.assign(n, 0);
        for(int i=0; i<n; ++i ){
            int d,v;
            cin >> d >> v;
            d = 3*d*w;
            V[i] = v;
            W[i] = d;
        }

        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= t; ++j) {
              if (i == 0 || j == 0) dp[i][j] = 0;
              else if (W[i-1] > j) dp[i][j] = dp[i-1][j];
              else dp[i][j] = max(dp[i-1][j], V[i-1] + dp[i-1][j - W[i-1]]);
            }
        }

        cout << dp[n][t] << "\n";
        backtrack(n, t, dp[n][t]);
        cout << solution.size() << "\n";
        reverse(solution.begin(), solution.end());
        for(auto k: solution){
            cout << k.first << " " << k.second << "\n";
        }
        solution.clear();
        ++c;
    }

  
  return 0;
}