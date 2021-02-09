#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
vector<vector<int>> AL;
vector<int> ts;
enum {UNVISITED = 0, VISITED = 1};
vector<int> dfs_num;
vector<int> dist;
const int INF = 1e9;

void toposort(int u) {
  dfs_num[u] = VISITED;
  for (int v : AL[u]){
    if (dfs_num[v] == UNVISITED)
      toposort(v);
  }
  ts.push_back(u);                               
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int V, n, c = 0;
    while(cin >> V){
        if(cin.eof()) break;
        if(c > 0) cout << "\n";
        ++c;
        vector<int> deaths;
        vector<int> num_paths(V,0);
        AL.assign(V, vector<int>());
        dfs_num.assign(V, UNVISITED);
        for(int u = 0; u < V; ++u){
            int n, v;
            cin >> n;
            if(n == 0) {
                deaths.push_back(u);
                continue;
            }
            while(n--){
                cin >> v;
                AL[u].emplace_back(v);
            }
        }
        for (int u = 0; u < V; ++u)                
            if (dfs_num[u] == UNVISITED)
                toposort(u);
        reverse(ts.begin(), ts.end());
        num_paths[0] = 1;
        int size = ts.size();
        for(int i = 0; i < V; ++i){
              int u = ts[i];
              for(int v: AL[u]){
                 num_paths[v] += num_paths[u];
           }
        }
        int total_paths = 0;
        for(int d: deaths) total_paths += num_paths[d];
        cout << total_paths << "\n";
    }




    return 0;
}

