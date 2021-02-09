#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>



using namespace std;

const int INF = 1e9;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, P, D;
    cin >> T;
    while(T--){
        cin >> P >> D;
        vector<vector<int>> AL(P, vector<int>());
        map<pair<int,int>, bool> check;
        int u, v;
        while(D--){
            cin >> u >> v;
            if(check.find({u,v}) == check.end()){
                check[{u,v}] = true;
                AL[u].emplace_back(v);
                AL[v].emplace_back(u);
            }
        }
        vector<int> dist(P, INF);
        queue<int> q; q.push(0);
        dist[0] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v: AL[u]){
                if(dist[v] == INF){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        for(int u = 1; u < P; ++u) {
            cout << dist[u] << "\n";
        }
        if(T) cout << "\n";

    }





    return 0;
}