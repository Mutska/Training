#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;



int dfsNumberCounter, numSCC;
vector<vector<int>> AL;
vector<int> dfs_num, dfs_low, S, visited;                 // global variables
stack<int> St;

enum {UNVISITED = -1};
void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter;    // dfs_low[u]<=dfs_num[u]
  dfsNumberCounter++;                            // increase counter
  St.push(u);                                    // remember the order
  visited[u] = 1;
  for (auto v : AL[u]) {
    if (dfs_num[v] == UNVISITED)
      tarjanSCC(v);
    if (visited[v])                              // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if (dfs_low[u] == dfs_num[u]) {                // a root/start of an SCC
    ++numSCC;                                    // when recursion unwinds
    while (1) {
      int v = St.top(); St.pop(); visited[v] = 0;
      if (u == v) break;
    }
  }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int V, N, dataset = 0, c = 0;
    while(cin >> V >> N,(V || N)){
        AL.assign(V, vector<int>());
        int u, v, p;
        while(N--){
            cin >> u >> v >> p;
            --u, --v;
            AL[u].emplace_back(v);
            if(p == 2) AL[v].emplace_back(u);
        }
        dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0); visited.assign(V, 0);
        while (!St.empty()) St.pop();
        dfsNumberCounter = numSCC = 0;
        for (int u = 0; u < V; ++u)
            if (dfs_num[u] == UNVISITED)
                tarjanSCC(u);
        if(numSCC == 1) cout << "1\n";
        else cout << "0\n";
    }


    return 0;
}