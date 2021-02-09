#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

enum {UNVISITED = -1};

vector<vector<int>> AL;
vector<int>  dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren, articulation_points;



void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;  // dfs_low[u]<=dfs_num[u]
  for (auto v : AL[u]) {
    if (dfs_num[v] == UNVISITED) {               // a tree edge
      dfs_parent[v] = u;
      if (u == dfsRoot) ++rootChildren;          // special case, root

      articulationPointAndBridge(v);

      if (dfs_low[v] >= dfs_num[u])              // for articulation point
        articulation_vertex[u] = 1;              // store this info first
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);  // subtree, always update
    }
    else if (v != dfs_parent[u])                 // if a non-trivial cycle
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);  // then can update
  }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int V;
    while(cin >> V, V){
        AL.assign(V, vector<int>());
        cin.ignore();
        string line;
        while(getline(cin, line)) {
            int u, v;
            if(line == "0") break;
            stringstream ss(line);
            ss >> v;
            --v;
            while(ss >> u){
                --u;
                AL[u].emplace_back(v);
                AL[v].emplace_back(u);
            }
        }
        dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0);
        dfs_parent.assign(V, -1); articulation_vertex.assign(V, 0);
        dfsNumberCounter = articulation_points = 0;
        for (int u = 0; u < V; ++u)
            if (dfs_num[u] == UNVISITED) {
                dfsRoot = u; rootChildren = 0;
                articulationPointAndBridge(u);
                articulation_vertex[dfsRoot] = (rootChildren > 1); // special case
            }
        for (int u = 0; u < V; ++u)
            if (articulation_vertex[u]){
                 ++articulation_points;
            }
        cout << articulation_points << "\n";
    }
    return 0;
}