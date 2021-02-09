#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int CaseNo = 0;
    int V;
    string line;
    while(getline(cin, line)){
        if(cin.eof()) break;
        if(line.empty()) continue;
        V = stoi(line);
        vector<vector<int>> AL(V, vector<int>()); 
        unordered_map<string, int> mapper;
        unordered_map<int, string> reverse_mapper;
        string beverage;
        for(int i = 0; i < V;++i){
            cin >> beverage;
            mapper[beverage] = i;
            reverse_mapper[i] = beverage;
        }
        vector<int> in_degree(V, 0);
        int M = 0;
        cin >> M;
        string b1, b2;
        for(int i = 0; i < M; ++i){
            cin >> b1 >> b2;
            int u = mapper[b1];
            int v = mapper[b2];
            AL[u].emplace_back(v);
            ++in_degree[v];
        }
        cout << "Case #" << ++CaseNo << ": Dilbert should drink beverages in this order:";
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int u = 0; u < V; ++u){
            if(in_degree[u] == 0) pq.push(u);
        }
        while(!pq.empty()){
            int u = pq.top(); pq.pop();
            cout << " " <<  reverse_mapper[u];
            for(int v: AL[u]){
                --in_degree[v];
                if(in_degree[v] > 0) continue;
                pq.push(v);
            }
        }
        cout << ".\n\n";

    }




    return 0;
}