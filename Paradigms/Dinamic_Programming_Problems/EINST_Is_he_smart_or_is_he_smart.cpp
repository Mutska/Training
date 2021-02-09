#include <iostream>
#include <cstring>

using namespace std;
int coinValue[110];
int coins;
long long memo[10010];

long long dp(int value){
    //if value is 0 then there is nothing to do, return 0
    if(value == 0) return 0;
    long long &ans = memo[value];
    //Check if I calculated before the num of coins for this value
    if(ans != -1) return ans;
    //Iterate through all coins and see which one gives the best result
    long long minimum = INT32_MAX;
    for(int i = 0; i < coins; ++i) {
      //If value of coin is greater than total we are looking for just continue
      if(coinValue[i] > value) continue;
      //recurse with value - coinValue[i] as new value
      long long val = dp(value - coinValue[i]);
      //If val we get from taking coinValue[i] as the first coin is less than minimum, change minimum
      minimum = min(minimum, val);
    }
   return ans = (minimum == INT32_MAX) ? minimum : minimum + 1;
}

int main() {
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   int T;
   cin >> T;
   while(T--) {
      int value;
      cin >> value;      
      cin >> coins;
      for(int i = 0; i < coins; ++i) cin >> coinValue[i];
      memset(memo, -1, sizeof memo);
      long long ans = dp(value);
      if(ans != INT32_MAX) cout << ans << "\n";
      else cout << "No solution\n";
   }

   return 0;
}