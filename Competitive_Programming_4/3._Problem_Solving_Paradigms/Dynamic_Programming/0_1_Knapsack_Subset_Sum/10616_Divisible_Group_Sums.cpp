#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
long long dp[21][10][200]; 
vector<long long> nums;
int N, D, M;


long long mod(long long a, long long m) {
  return ((a%m) + m) %m;
}

long long bt(long long sum, int m,int pos){

  if (pos == N+1) return 0;
 
  if(m == M && sum == 0) return 1;

  if(m == M && sum != 0) return 0;



 

  //long long &ans = dp[sum][m][pos];
  //if (ans != -1) return ans;
  int ans = 0;
    // Toma num[pos]
    ans = bt( mod(sum + nums[pos], D), m + 1, pos+1);
    
    // Ignora num[pos]
    ans +=  bt(sum, m, pos + 1);

    return ans;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int Q;
  int i = 1;
  while(cin >> N >> Q, (N || Q)) {
    cout << "SET " << i++ << ":\n";
      nums.assign(N, 0);
      for(int i = 0; i < N; ++i) cin >> nums[i];
     
      for(int p=1; p<=Q; ++p) {
        memset(dp, -1, sizeof dp);
        cin >> D >> M;
        cout << "QUERY " << p << ": ";
        cout << bt(0, 0, 0) << "\n";
      }
  }
  return 0;
}