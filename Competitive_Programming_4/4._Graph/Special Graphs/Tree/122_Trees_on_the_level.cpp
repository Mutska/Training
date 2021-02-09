#include<iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

bool cmp_size(pair<int, string> &a, pair<int, string>& b){
    return a.second.size() < b.second.size();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string node;
    while(cin >> node){
        vector<pair<int, string>> nodes;
        unordered_map<string, bool> flag;
        unordered_map<string, int> mapper;
        unordered_map<int, int> mapping;
        int index = 0;
        bool complete = true;
        int root;
        size_t pos = node.find(',');
        string v = node.substr(1, pos - 1);
        string info = node.substr(pos + 1);
        if(info == ")") {
            root = stoi(v);
            pair<int, string> n = {root, ""};
            nodes.emplace_back(n);
            flag[""]  = true;
            mapper[""] = index;
            mapping[index] = root;
            index++;
        } else{
            info.pop_back();
            pair<int, string> n = {stoi(v), info};
            nodes.emplace_back(n);
            flag[info] = true;
            mapper[info] = index;
            mapping[index] = stoi(v);
            index++;
        }
        while(cin >> node){
            if(node == "()") break;
            if(!complete)  continue;
            size_t pos = node.find(',');
            string v = node.substr(1, pos - 1);
            string info = node.substr(pos + 1);
            if(info == ")") {
                root = stoi(v);
                pair<int, string> n = {root, ""};
                nodes.emplace_back(n);
                if(flag[""] == true) {
                    complete = false;
                    continue;
                } else flag[info] = true;
                mapper[""] = index;
                mapping[index] = root;
                index++;
            } else{
                info.pop_back();
                pair<int, string> n = {stoi(v), info};
                nodes.emplace_back(n);
                if(flag[info] == true) {
                    complete = false;
                    continue;
                } else flag[info] = true;
                mapper[info] = index;
                mapping[index] = stoi(v);
                index++;
            }
        }
        if(mapper.find("") == mapper.end()) complete = false;
        if(!complete)  cout << "not complete\n";
        else{
        sort(nodes.begin(), nodes.end(), cmp_size);
        int n = mapper.size();
        vector<vector<int>> AL(n, vector<int>());
        for(int i = 0; i < n; ++i){
            string u = nodes[i].second;
            int p = mapper[u];
            string left  = u;
            left += 'L';
            string right = u;
            right += 'R';
            int l = -1, r = -1;
            for(int j = i + 1; j < n; ++j){
                string v = nodes[j].second;
                if(v == left) {
                    l = mapper[v];
                }
                if(v == right) {
                    r = mapper[v];
                }
            }
            if(l != -1) AL[p].emplace_back(l);
            if(r != -1) AL[p].emplace_back(r);
        }
        vector<bool> check(n, false); 
        vector<int> res;
        int s = mapper[""];
        check[s] = 1;
        res.emplace_back(mapping[s]);
        queue<int> q; q.push(s);
        while (!q.empty()) {
          int u = q.front(); q.pop();
          for (int v : AL[u]) {                
            if (check[v] == false) {
              check[v] = true;
              res.emplace_back(mapping[v]);
              q.push(v);                            
            }
          }
        }
        if(any_of(check.begin(), check.end(), [] (bool b){return b == false;}))
            cout << "not complete\n";
        else{
            cout << res.front();
            for(int i = 1; i < n; ++i) cout << " " << res[i];
            cout << "\n";
        }
        }
    }
    return 0;
}
