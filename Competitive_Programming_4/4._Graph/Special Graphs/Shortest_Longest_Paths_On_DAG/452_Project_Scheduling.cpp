#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <queue>


using namespace std;
vector<vector<pair<int, int>>> AL;
vector<int> ts;
enum {UNVISITED = 0, VISITED = 1};
vector<int> dfs_num;
vector<int> dist;

void toposort(int u) {
  dfs_num[u] = VISITED;
  for (auto p : AL[u]){
    int v = p.first;
    if (dfs_num[v] == UNVISITED)
      toposort(v);
  }
  ts.push_back(u);                               
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, sw;
    cin >> T;
    cin.ignore();
    string dummy;
    getline(cin, dummy);
    string s;
    while(T--){
        string line;
        unordered_map<char, int> mapper, dmapper, in_degree;
        unordered_map<int, char> rmapper;
        unordered_map<char, vector<int>> vlist;
        int index = 0, w;
        char v;
        while(getline(cin, line)){
            if(line.empty()) break;
            stringstream ss(line);
            ss >> v >> w;
            if(mapper.find(v) == mapper.end()) {
                mapper[v] = index;
                rmapper[index] = v;
                in_degree[v] = 0;
                ++index;
            }
            dmapper[v] = w;
            string us;
            ss >> us;
            int n = us.size();
            for(int i = 0; i < n; ++i){
                if(mapper.find(us[i]) == mapper.end()) {
                    mapper[us[i]] = index;
                    rmapper[index] = us[i];
                    ++index;
                }
                in_degree[v]++;
                vlist[mapper[v]].push_back(mapper[us[i]]);
            }

        }
        int V =  mapper.size();
        dfs_num.assign(V, UNVISITED);
        vector<int> dist(V, 0);
        AL.assign(V, vector<pair<int, int>>());
        for(auto m : mapper){
            int v = m.second;
            int w = dmapper[m.first];
            for(int u: vlist[v]){
                AL[u].emplace_back(v, -w);
            }
        }

        for(auto p: mapper){
            char c = p.first;
            if(in_degree[c] == 0){
                dist[mapper[c]] = -dmapper[c];
            }
        }
        toposort(0);
        reverse(ts.begin(),ts.end());
        for(int u = 0; u < V; ++u){
            //int u = mapper[rmapper[ts[i]]];
            for(auto p: AL[u]){
                int v = p.first;
                int w = p.second;
                if(dist[v] > dist[u] + w)
                    dist[v] = dist[u] + w;
            }
        }
        int minimum = dist[0];
        for(int i = 0; i < V; ++i){
            minimum = min(minimum, dist[i]);
        }
        cout << -minimum << "\n";
        if(T)  cout << "\n";
    }



    return 0;
}