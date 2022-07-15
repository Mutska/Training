#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>


using namespace std;
vector<int> suitcase;
int m, dp[205];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
  
        suitcase.clear();
        memset(dp, 0, sizeof dp);
        string line;
        getline(cin, line);
        stringstream ss(line);
        int sw; 
        int sum = 0;
        while(ss  >> sw){
          suitcase.push_back(sw);
          sum += sw;
        }
        int m = suitcase.size();
        int target = sum / 2;
        if (sum & 1 ) {
          cout << "NO\n";
        } else {
          for (int i = 0; i < m; ++i) {
              for(int j = target; j >= suitcase[i]; --j) dp[j] = max(dp[j], dp[j-suitcase[i]] + suitcase[i]);
          }
          
          if(dp[target]==target) cout << "YES\n";
          else cout << "NO\n";
        }
        

      
    }
    return 0;
}