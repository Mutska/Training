#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

enum {UNVISITED = 0, VISITED = 1};
vector<vector<int>> AL;
vector<int> dfs_num;
vector<int> ts;

void toposort(int u){
    dfs_num[u] = VISITED;
    for(int v: AL[u])
        if(dfs_num[v] == UNVISITED) toposort(v);
    ts.push_back(u);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int V, E;
    while(cin >> V >> E, (V || E)){
        AL.assign(V, vector<int>());
        dfs_num.assign(V, UNVISITED);
        int u, v;
        while(E--){
            cin >> u >> v;
            --u, --v;
            AL[u].emplace_back(v);
        }
        for(int u = 0; u < V; ++u)
            if(dfs_num[u] == UNVISITED) toposort(u);

        reverse(ts.begin(), ts.end());
        cout << ts[0] + 1;
        for(int i = 1; i < V; ++i) cout << " " << ts[i] + 1;
        cout << "\n";
        ts.clear();
    }

    return 0;
}