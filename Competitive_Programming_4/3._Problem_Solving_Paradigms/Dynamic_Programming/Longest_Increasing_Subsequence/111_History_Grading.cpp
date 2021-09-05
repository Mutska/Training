#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

int dp[25][25], a[25], b[25];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string line;
    int n, s;
    bool flag = false;
    vector<int> A;
    while(getline(cin, line)) {
        A.clear();
        stringstream ss(line);
        while(ss >> s) A.emplace_back(s);
        if(A.size() == 1) {
            n = A[0];
            flag = true;
            continue;
        }
        if (flag) {
           flag = false;
           for(int i = 1; i <= n; ++i) a[A[i-1]] = i;
        } else {
           for(int i = 1; i <= n; ++i) b[A[i-1]] = i;
           //memset(dp, 0, sizeof dp);
           for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <=n; ++j) {
                   if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
                   else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
               }
           }
           cout << dp[n][n] << "\n";
        }
        
    }
}