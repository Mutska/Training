#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>



using namespace std;

vector<int> p;
const int INF = 1e9;
unordered_map<string, int> mapper;
unordered_map<int, string> rmapper;
void printPath(int u){
    if(p[u] == -1){
        cout << rmapper[u][0];
        return;
    }
    printPath(p[u]);
    cout << rmapper[u][0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, m, n;
    cin >> T;
    while(T--){
        cin >> m >> n;
        int u, v;
        mapper.clear();
        rmapper.clear();
        vector<string> cities;
        string A, B;
        int idx = 0;
        for(int i = 0; i < m; ++i){
            cin >> A >> B;
            if(mapper.find(A) == mapper.end()){
                mapper[A] = idx;
                rmapper[idx] = A;
                ++idx;
            } 
            if(mapper.find(B) == mapper.end()){
                mapper[B] = idx;
                rmapper[idx] = B;
                ++idx;
            } 
            cities.emplace_back(A);
            cities.emplace_back(B);
        }
        int V = mapper.size();
        vector<vector<int>> AL(V, vector<int>());
        for(int i = 0; i < 2*m ; i += 2){
            int u = mapper[cities[i]];
            int v = mapper[cities[i+1]];
            AL[u].emplace_back(v);
            AL[v].emplace_back(u);

        }
        while(n--){
            cin >> A >> B;
            int s = mapper[A];
            int t = mapper[B];
            vector<int> dist(V, INF);
            p.assign(V, -1);
            queue<int> q; q.push(s);
            bool found = false;
            dist[s] = 0;
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int v: AL[u]){
                    if(dist[v] == INF){
                        dist[v] = dist[u] + 1;
                        p[v] = u;
                        if(v == t){
                            found = true;
                            break;
                        }
                        q.push(v);
                    }
                }
                if(found) break;
            }
            printPath(t);
            cout << "\n";
        }
        if(T) cout << "\n";

    }





    return 0;
}