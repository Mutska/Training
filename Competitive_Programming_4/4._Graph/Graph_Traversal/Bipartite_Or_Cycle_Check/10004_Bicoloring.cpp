#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while(cin >> n, n){
        vector<vector<int>> AL(n, vector<int>());
        cin >> m;
        int u, v;
        while(m--){
            cin >> u >> v;
            AL[u].emplace_back(v);
            AL[v].emplace_back(u);
        }
        int s = 0;
        queue<int> q; q.push(s);
        vector<int> color(n, INF); color[s] = 0;
        bool isBipartite = true;
        while(!q.empty() && isBipartite) {
            int u = q.front(); q.pop();
            for(int v: AL[u]){
                if(color[v] == INF){
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if(color[v] == color[u]){
                    isBipartite = false;
                    break;
                }
            }
        }
        if(isBipartite) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }


    return 0;
}