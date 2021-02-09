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
    int V;
    while(cin >> V){
    AL.assign(V, vii());
    string w;
    for(int u = 1; u <= V; ++u){
        for(int v = 1 ; v <= V, u != v; ++v){
            if(u < v) ;
            else{ //cout << "(" << u <<  "," << v << ")" << " ";
                cin >> w;
                if(w != "x"){
                    AL[u-1].push_back({v-1 ,stoi(w)});
                    AL[v-1].push_back({u-1 ,stoi(w)});
                }
            }
        }
    }
    dist.assign(V, INF);
    dist[0] = 0;
    for(int i = 0; i < V - 1; ++i){
        for(int u = 0; u < V; ++u){
            if(dist[u] != INF){
                for(auto p: AL[u]){
                    int v = p.first;
                    int w = p.second;
                    dist[v] = min(dist[v], dist[u] + w);
                }
            }
        }
    }
    int minimum = INT32_MIN;
    for(int u = 1; u < V; ++u) {
        minimum = max(minimum, dist[u]);
    }
    if(minimum == INT32_MIN) cout << "0\n";
    else cout << minimum << "\n";
    }




    return 0;
}