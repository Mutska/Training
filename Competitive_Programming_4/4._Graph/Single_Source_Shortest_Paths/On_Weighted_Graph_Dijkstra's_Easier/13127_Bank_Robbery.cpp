#include <iostream>
#include <vector>
#include<queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, B, P;

    while(cin >> N >> M >> B >> P){
        vector<vii> ALS(N+1, vii());
        vector<bool> seen(N, false);
        int u, v, w;
        while(M--){
            cin >> u >> v >> w;
            seen[u] = seen[v] = true;
            ALS[u].emplace_back(v,w);
            ALS[v].emplace_back(u,w);
        }
        vector<int> banks;
        vector<int> stations;
        vector<int> early;
        bool infinite = false;
        int b, p;
        for(int i = 0; i < B; ++i){
            cin >> b;
            if(!seen[b]) infinite = true;
            banks.emplace_back(b);
        }
        sort(banks.begin(), banks.end());
        int isolated = 0;
        for(int i = 0; i < P; ++i){
            cin >> p;
            if(!seen[p]) ++isolated;
            ALS[N].emplace_back(p,0);
            ALS[p].emplace_back(N,0);
            stations.emplace_back(p);
        }
        if(P == 0 || isolated == P){
            int size = banks.size();
            cout << size << " *\n";
            cout << banks.front();
            for(int u = 1; u < size; ++u) cout << " " << banks[u];
            cout << "\n";
        
        } else if(infinite){
                priority_queue<ii, vector<ii>, greater<ii>> pq2;
                vi dist2(N+1, INF);
                dist2[N] = 0;
                pq2.push({0,N});
                while(!pq2.empty()) {
                    int d = pq2.top().first;
                    int u = pq2.top().second;
                    pq2.pop();
                    if(d > dist2[u]) continue;
                    for(auto p: ALS[u]){
                        int v = p.first;
                        int w = p.second;
                        if(dist2[u] + w >= dist2[v]) continue;
                        dist2[v] = dist2[u] + w;
                        pq2.push({dist2[v], v});
                    }
                }
                for(int u = 0; u < B; ++u){
                    if(dist2[banks[u]] == INF) early.emplace_back(banks[u]);
                }
                int size = early.size();
                sort(early.begin(), early.end());
                cout << size << " *\n";
                cout << early.front();
                for(int u = 1; u < size; ++u) cout << " " << early[u];
                cout << "\n";

        } else{
        priority_queue<ii, vector<ii>, greater<ii>> pq2;
        vi dist2(N+1, INF);
        dist2[N] = 0;
        pq2.push({0,N});
        while(!pq2.empty()) {
            int d = pq2.top().first;
            int u = pq2.top().second;
            pq2.pop();
            if(d > dist2[u]) continue;
            for(auto p: ALS[u]){
                int v = p.first;
                int w = p.second;
                if(dist2[u] + w >= dist2[v]) continue;
                dist2[v] = dist2[u] + w;
                pq2.push({dist2[v], v});
            }
        }
        int maximum = INT32_MIN;
        for(int u = 0; u < B; ++u){
            maximum = max(maximum, dist2[banks[u]]);
        }
        vector<int> res;
        for(int u = 0 ; u < B; ++u){
            if(dist2[banks[u]] == maximum){
                res.emplace_back(banks[u]);
            }
        }
        int num_banks = res.size();
        cout << num_banks << " ";
        if(maximum == INF) cout << "*\n";
        else cout << maximum << "\n";
        cout << res.front();
        for(int i = 1; i < num_banks;++i) cout << " " << res[i];
        cout << "\n";
        }


    }



    return 0;
}