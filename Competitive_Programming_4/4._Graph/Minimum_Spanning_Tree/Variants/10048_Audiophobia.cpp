#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




class UnionFind {                                // OOP style
private:
  vector<int> p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};


struct edge{
    int u, v, w;
};

bool cmp(edge &a, edge &b){
    return a.w < b.w;
}
enum {UNVISITED = 0, VISITED = 1};
vector<int> dfs_num;
vector<int> dfs_parent;
vector<vector<int>> AL;

void dfs(int u, int target){
    dfs_num[u] = VISITED;
    for(int v: AL[u]){
        if(dfs_num[v] == UNVISITED){
            dfs_parent[v] = u;
            if(v == target) return;
            dfs(v, target);
        }
    }
}
int weight[110][110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, Case = 0, c = 0;
    int C, S, Q;
    while(cin >> C >> S >> Q, (C || S || Q)){
        if(c > 0) cout << "\n";
        else ++c;
        cout << "Case #" << ++Case << "\n";
        UnionFind UF(C);
        int c1, c2, d;
        vector<edge> edges;
        AL.assign(C, vector<int>());
        for(int i = 0; i < S;++i){
            cin >> c1 >> c2 >> d;
            edges.push_back({c1,c2,d});
        }
        sort(edges.begin(), edges.end(), cmp);
        int num_taken = 0, size = edges.size();
        for(int i = 0; i < size; ++i){
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;
            --u, --v;
            if(UF.isSameSet(u, v)) continue;
            UF.unionSet(u,v);
            weight[u][v] = w;
            weight[v][u] = w;
            AL[u].push_back(v);
            AL[v].push_back(u);
            ++num_taken;
            if(num_taken == C - 1) break;
        }
        int u, v;

        while(Q--){
            cin >> u >> v;
            --u, --v;
            if(!UF.isSameSet(u, v)) cout << "no path\n";
            else{
                dfs_num.assign(C, UNVISITED);
                dfs_parent.assign(C, -1);
                dfs(u, v);
                if(dfs_parent[v] == u) {
                   cout << weight[u][v] << "\n";
                } else {
                    int w = INT32_MIN;
                    while(dfs_parent[v] != u){
                        w = max(weight[dfs_parent[v]][v], w);
                        v = dfs_parent[v];
                    }
                    w = max(weight[dfs_parent[v]][v], w);
                    cout << w << "\n";
                }
            }
        }
    }
    return 0;
}