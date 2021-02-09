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
unordered_map<string, int> mapper;
unordered_map<int, string> rmapper;
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
      cout << rmapper[v];
      if (u == v) break;
      else cout << ", ";
    }
    cout << "\n";
  }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int V, N, dataset = 0, c = 0;
    while(cin >> V >> N){
        if(V == 0 && N == 0) break;
        if(c > 0){
          cout << "\n";
        }
        c++;
        AL.assign(V, vector<int>());
        int k = N;
        mapper.clear();
        rmapper.clear();
        string u, v;
        int id = 0, idu, idv;
        while(N--){
            cin >> u >> v;
            if(mapper.find(u) != mapper.end()) idu = mapper[u];
            else {
              mapper[u] = idu = id++;
              rmapper[idu] = u;
            }
            if(mapper.find(v) != mapper.end()) idv = mapper[v];
            else {
              mapper[v] = idv = id++;
              rmapper[idv] = v;
            }
            AL[idu].emplace_back(idv);
        }
        dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0); visited.assign(V, 0);
        while (!St.empty()) St.pop();
        dfsNumberCounter = numSCC = 0;
        cout << "Calling circles for data set " << ++dataset << ":\n";
        if(k != 0) {
        for (int u = 0; u < V; ++u)
            if (dfs_num[u] == UNVISITED)
                tarjanSCC(u);
        }
    }



    return 0;
}