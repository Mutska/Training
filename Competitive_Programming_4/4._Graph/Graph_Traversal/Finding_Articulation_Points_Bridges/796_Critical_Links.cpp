#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdio>
#include <algorithm>

using namespace std;

enum {UNVISITED = -1};

vector<vector<int>> AL;
vector<int>  dfs_num, dfs_low, dfs_parent;
int dfsNumberCounter;
vector<pair<int, int>> edges;


void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;  // dfs_low[u]<=dfs_num[u]
  for (auto v: AL[u]) {
    if (dfs_num[v] == UNVISITED) {               // a tree edge
      dfs_parent[v] = u;
      articulationPointAndBridge(v);

      if (dfs_low[v] > dfs_num[u]){               // for bridge
        if(u < v) edges.push_back({u,v});
        else edges.push_back({v,u});

      }
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);  // subtree, always update
    }
    else if (v != dfs_parent[u])                 // if a non-trivial cycle
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);  // then can update
  }
}



int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int V, B;
    while(cin >> V){
        B = V;
        if(V == 0) {
            cout << "0 critical links\n\n";
            continue;
        }
        dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0);
        dfs_parent.assign(V, -1);
        edges.clear();
        AL.assign(V, vector<int>());
        cin.ignore();
        string line;
        while(V--) {
            getline(cin, line);
            int u, v;
            string num;
            stringstream ss(line);
            ss >> u;
            ss >> num;
            while(ss >> v){
                AL[u].emplace_back(v);
            }
        }
        dfsNumberCounter = 0;
        for (int u = 0; u < B; ++u)
            if (dfs_num[u] == UNVISITED) {
            articulationPointAndBridge(u);
        }
        sort(edges.begin(), edges.end());
        cout << edges.size() << " critical links\n";
        for(auto e: edges) cout << e.first << " - " << e.second << "\n";
        cout << "\n";
    }
    return 0;
}