#include <iostream>
#include <vector>
using namespace std;

int n, k, M = 0;
vector<string> mutations;
string s;

string change = "ACGT"; 


void backtrack(int moves, string actual){
  int  tamanio = actual.size(); 
  if( moves > k) return; 
  if( tamanio == s.size()){
    mutations.emplace_back(actual); 
    return; 
  }
  for(int i=0; i< change.size(); ++i){
    backtrack(moves+(int)(change[i]!=s[tamanio]) , actual+change[i]); 
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while(t--){
    mutations.clear();
    cin >> n >> k;
    cin >> s;
    backtrack(0, "");
    cout << mutations.size() << "\n";
    for(auto x: mutations) cout << x << "\n";
  }
}