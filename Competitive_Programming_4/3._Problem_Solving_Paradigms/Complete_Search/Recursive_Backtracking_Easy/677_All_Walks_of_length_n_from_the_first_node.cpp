#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> AL;

int steps, n;
vector <int> nums;
vector <bool> b;
bool  NoPaths = false; 

void dfs(int u){
  if(steps == 0){
    NoPaths=true; 
    cout << "(";
    cout << nums.front();
    for(int h = 1; h < nums.size(); ++h){
      cout << "," << nums[h]; 
    }
    cout << ")\n";
    return;
  }

  b[u] = true;
  for(auto v: AL[u]){
    steps--;
    nums.push_back(v + 1);
    if(!b[v]) dfs(v);
    nums.pop_back();
    steps++;
  }
  b[u] = false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int d;
  while(cin >> d){
    if (d == -9999){
      cout << "\n";
      continue;
    }
    AL.assign(d, vector<int>());
    b.assign(d, false);
    cin >> n;
    steps = n;
    int a;
    for(int i =0; i < d; ++i){
      for(int j = 0 ; j < d; ++j){
        cin >> a;
        if(a) AL[i].push_back(j);
      }
    }
    nums.push_back(1);
    dfs(0);
    if(!NoPaths) cout<<"no walk of length " << n <<"\n";
    NoPaths = false;
    nums.clear();
    b.clear();
  }
}