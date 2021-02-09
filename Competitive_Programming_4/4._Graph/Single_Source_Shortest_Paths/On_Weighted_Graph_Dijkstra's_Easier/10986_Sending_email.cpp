#include <iostream>
#include <vector>
#include<queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    int n, m, s, t, u, v, w, Case = 0;
    while(T--){
        cin >> n >> m >> s >> t;
        vector<vii> AL(n, vii());
        vi dist(n, INF);
        dist[s] = 0;
        while(m--){
           cin >> u >> v >> w; 
           AL[u].push_back({v,w});
           AL[v].push_back({u,w});
        }
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0,s});
        while(!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(d > dist[u]) continue;
            for(auto p: AL[u]){
                int v = p.first;
                int w = p.second;
                if(dist[u] + w >= dist[v]) continue;
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }

        }
        if(dist[t] == INF) cout << "Case #" << ++Case << ": unreachable\n";
        else cout << "Case #" << ++Case << ": " << dist[t] << "\n";

    }


    return 0;
}