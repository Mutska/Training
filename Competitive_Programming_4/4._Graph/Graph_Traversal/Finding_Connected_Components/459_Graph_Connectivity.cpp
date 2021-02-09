#include <iostream>
#include <vector>

using namespace std;


enum {UNVISITED = 0, VISITED = 1};
vector<vector<int>> AL;
vector<int> dfs_num;

void dfs(int u) {
    dfs_num[u] = VISITED;
    for(int v: AL[u]) 
        if(dfs_num[v] == UNVISITED) dfs(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N;
    string edge, num_nodes;
    cin >> T;
    while(T--){
        cin >> num_nodes;
        int V = num_nodes[0] - 64;
        AL.assign(V, vector<int>());
        dfs_num.assign(V, UNVISITED);
        cin.ignore();
        while(getline(cin, edge)) {
            if(edge.empty()) break;
            AL[(edge[0] - 65)].push_back(edge[1] - 65);
            AL[(edge[1] - 65)].push_back(edge[0] - 65);
        }
        int numCC = 0;
        for(int u = 0; u < V; ++u){
            if(dfs_num[u] == UNVISITED){
                ++numCC;
                dfs(u);
            }
        }
        cout << numCC << "\n";
        if(T) cout << "\n";

    }


    return 0;
}