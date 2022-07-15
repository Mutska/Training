#include <bits/stdc++.h>

using namespace std;
int N;




bool order(string x, string y){
  return x.size() < y.size();
}

set<string> ans;
//vector<string> ans; 
vector<string> table;

bool used[20][20]; 

vector<int> dir1 = {0,0, 1, 1, 1, -1, -1, -1};
vector<int> dir2 = {-1,1,-1,0, 1,  -1, 0, 1};

string word; 

void bactrack(int i, int j, int it){
  if(it >=3) ans.insert(word);
  if(i < 0  || j <0  || i >= N || j>= N) return; 
  if(it>0 &&  word[it-1] >= table[i][j]) return; 
  if(used[i][j]) return; 
  
  word += table[i][j]; 
  used[i][j]=1; 
  for(int x=0; x< 8;  ++x ){
    bactrack(i + dir1[x], j +dir2[x], it+1); 
  }
  word.pop_back(); 
  used[i][j]=0; 
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    ans.clear();
    cin >> N;
    table.assign(N, "");
    memset(used, 0, sizeof used);
    for (int i = 0; i < N; ++i) cin >> table[i];
    
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        bactrack(i, j, 0);
      }
    }
    vector<string> fin(ans.begin(), ans.end());
    
    stable_sort(fin.begin(), fin.end(), order);

    for(string &f: fin) cout << f << "\n"; 
    if (T) cout << "\n";
  }
}