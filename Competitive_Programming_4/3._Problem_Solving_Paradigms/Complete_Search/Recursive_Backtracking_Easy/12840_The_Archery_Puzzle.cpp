#include <iostream>
#include <vector>

using namespace std;
vector<int> P;
vector<int> sol;
vector<int> mini_sol;
int N, score;
bool ok;
int min_sol;

void backtrack(int sum) {
  if(sol.size() > min_sol) return;
  if (sum == score) {
    if(min_sol > sol.size()){mini_sol=sol; min_sol = sol.size();} 
    ok  = true;
   // cout << min_sol << "\n";
    return;
  } 
  for (int i = 0; i < N; ++i) {
    if (sum + P[i] <= score) {
      sol.emplace_back(P[i]);
      backtrack(sum + P[i]);
      sol.pop_back();
    }
  }
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, n, Case = 0;
  cin >> T;
  while(T--) {
    min_sol = 1e9;
    cin >> N >> score;
    ok = false;
    P.clear();
    sol.clear();
    P.assign(N,0);
    for(int i = N - 1; i >= 0; --i) {
      cin >> P[i];
    }
    backtrack(0);
    cout << "Case " << ++Case << ": ";
    if (ok) {
      cout << "[" << min_sol  << "]";
      for(int &s: mini_sol) cout << " " << s;
      cout << "\n";

    } else cout << "impossible\n";

  }
}