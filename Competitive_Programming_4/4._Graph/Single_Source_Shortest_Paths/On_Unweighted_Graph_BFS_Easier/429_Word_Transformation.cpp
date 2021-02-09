#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <queue>


using namespace std;

const int INF = 1e9;

bool connect(string &a, string &b){
   if(a.size() != b.size()) return false;
   int s = a.size();
   int c = 0;
   for(int i = 0; i < s; ++i){
       if(a[i] != b[i]) ++c;
       if(c > 1) return false;
   }
   return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    cin.ignore();
    string line;
    while(T--) {
        vector<string> words;
        unordered_map<string, int> mapper;
        unordered_map<int, string> rmapper;
        int idx = 0;
        while(getline(cin, line)){
            if(line == "*") break;
            if(line.empty()) continue; 
            mapper[line] = idx;
            rmapper[idx] = line;
            ++idx;
            words.emplace_back(line);
        }
        int V = words.size();
        vector<vector<int>> AL(V, vector<int>());
        for(int u = 0; u < V;++u){
            for(int v = u + 1; v < V; ++v){
                if(connect(words[u], words[v])){
                    AL[u].emplace_back(v);
                    AL[v].emplace_back(u); 
                }
            }
        }
        string source, target;
        while(getline(cin, line)){
            if(line.empty()) break;
            stringstream ss(line);
            ss >> source >> target;
            int s = mapper[source];
            int t = mapper[target];
            vector<int> dist(V, INF); 
            bool ok = false;
            dist[s] = 0;
            queue<int> q; q.push(s);
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int v: AL[u]){
                    if(dist[v] == INF){
                        dist[v] = dist[u] + 1;
                        if(rmapper[v] == target) {
                            ok = true;
                            break;
                        }
                        q.push(v);
                    }
                }
                if(ok) break;
            }
            cout << source << " " << target << " " << dist[t] << "\n";
        }
        if(T) cout << "\n";
    }







    return 0;
}