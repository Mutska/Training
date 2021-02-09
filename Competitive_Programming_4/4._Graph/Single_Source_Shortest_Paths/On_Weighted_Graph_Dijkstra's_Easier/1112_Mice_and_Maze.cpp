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
    int N, E, D, M, u, v, w, Case = 0;
    while(T--){
        cin >> N >> E >> D >> M;
        vector<vii> AL(N, vii());
        vi dist(N, INF);
        int s = E;
        --s;
        dist[s] = 0;
        while(M--){
           cin >> u >> v >> w;
           --u;--v;
           AL[v].emplace_back(u,w);
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
        int mice = 0;
        for(int u = 0; u < N; ++u){
            if(dist[u] <= D) ++mice;
        }
        cout << mice << "\n";
        if(T) cout << "\n";

    }


    return 0;
}