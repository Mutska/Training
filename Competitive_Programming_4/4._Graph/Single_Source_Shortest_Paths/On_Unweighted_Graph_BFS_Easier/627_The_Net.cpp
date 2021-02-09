#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>



using namespace std;

vector<int> p;

void printPath(int u) {
    if (p[u] == -1) {
        cout << u + 1;
        return;
    }
    printPath(p[u]);                              
    cout << " " <<  u + 1;
}


int main() {

    int V;
    while(cin >> V) {
        if(cin.eof()) break;
        cout << "-----\n";
        vector<vector<int>> AL(V, vector<int>());
        cin.ignore();
        string line;
        for(int i = 0 ; i < V; ++i){
            getline(cin , line);
            replace(line.begin(), line.end(), '-', ' ');
            replace(line.begin(), line.end(), ',', ' ');
            stringstream ss(line);
            int u;
            string f;
            ss >> u;
            ss >> f;
            if(f.size() == 0) continue;
            int v = stoi(f);
            --u;--v;
            AL[u].emplace_back(v);
            while(ss >> v){
                --v;
                AL[u].emplace_back(v);
            }
        }
        int Q, s, t;
        cin >> Q;
        while(Q--){
            cin >> s >> t;
            --s; --t;
            p.assign(V, -1);
            vector<bool> visited(V, false);
            bool found = false;
            queue<int> q; q.push(s);
            visited[s] = true;
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int v: AL[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        p[v] = u;
                        if(v == t){ found = true; break;}
                        q.push(v);
                    }

                }
                if(found) break;
            }
            if(found){
                printPath(t);
                cout << "\n";
            } else cout << "connection impossible\n";
        }
        
    }


    return 0;
}