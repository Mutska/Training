#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <set>


using namespace std;

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int P, Case = 0;
    while(cin >> P, P){
        vector<pair<int, int>> l;
        set<int> S;
        int u, v;
        while(P--){
            cin >> u >> v;
            l.push_back({u,v});
            S.insert(u);
            S.insert(v);
        }
        unordered_map<int, int> mapper;
        int idx = 0;
        for(auto s: S){
            mapper[s] = idx++;
        }
        int V = S.size();
        vector<vector<int>> AL(V, vector<int>());
        for(auto p: l){
            u = mapper[p.first];
            v = mapper[p.second];
            AL[u].emplace_back(v);
            AL[v].emplace_back(u);
        }
        int node, TTL;
        while(cin >> node >> TTL,(node || TTL)){
            if(mapper.find(node) == mapper.end()) {
                cout << "Case " << ++Case << ": " << V << " nodes not reachable from node "
                 << node << " with TTL = " << TTL << ".\n";
                 continue;
            }
            int s = mapper[node];
            vector<int> dist(V, INF); dist[s] = 0;
            queue<int> q; q.push(s);
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int v: AL[u]){
                    if(dist[v] == INF){
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            int unreachable = 0;
            if(TTL == 0) unreachable = V - 1;
            else{
                for(int u = 0; u < V; ++u)
                    if(TTL - dist[u] < 0) ++unreachable;
            }
            cout << "Case " << ++Case << ": " << unreachable << " nodes not reachable from node "
                 << node << " with TTL = " << TTL << ".\n";

        }



    }






    return 0;
}