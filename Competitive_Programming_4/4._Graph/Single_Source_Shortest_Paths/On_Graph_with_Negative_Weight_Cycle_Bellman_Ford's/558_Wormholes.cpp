
#include <iostream>
#include <vector>


using namespace std;


typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<int> dist;
vector<vii> AL;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int V, T, E;
    cin >> T; 
    while(T--){
    cin >> V >> E;
    AL.assign(V, vii());
    int u, v, w;
    while(E--){
        cin >> u >> v >> w; 
        AL[u].emplace_back(v,w);
    }
    dist.assign(V, INF);
    dist[0] = 0;
    for(int i = 0; i < V - 1; ++i){
        bool modified = false;
        for(int u = 0; u < V; ++u){
            if(dist[u] != INF){
                for(auto p: AL[u]){
                    int v = p.first;
                    int w = p.second;
                    if(dist[u]+ w >= dist[v]) continue;
                    dist[v] = dist[u] + w;
                   modified = true; 
                }
            }
        }
        if(!modified) break;
    }
    bool  cycle = false;
    for (int u = 0; u < V; ++u){                   
        if (dist[u] != INF)
            for (auto p: AL[u]) {  
                int v = p.first;
                int w = p.second;
                if (dist[v] > dist[u]+w) cycle = true;       
            }
    }
    if(cycle) cout << "possible\n";
    else cout << "not possible\n";
    }

    return 0;
}