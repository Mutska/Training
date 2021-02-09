#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

struct edge{
    int x, y, w;
};
int Vx[755], Vy[755];
int distance(int u, int v) {
    int xDiff = Vx[u] - Vx[v];
    int yDiff = Vy[u] - Vy[v];
    return (xDiff * xDiff) + (yDiff * yDiff);
}
bool cmp(edge & a, edge & b){
    return a.w < b.w;
}
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



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, c = 0;
        cin >> N;
        while(N--){
        int V;
        cin >> V;
        UnionFind UF(V);
        for(int i = 1; i <= V; ++i){
            cin >>  Vx[i] >> Vy[i];
        }
        int u, v, M;
        cin >> M;
        int ed = 0;
        for(int i = 0; i < M;++i){
            cin >> u >> v;
            if(!UF.isSameSet(u-1, v-1)) {
                UF.unionSet(u - 1,v - 1);
                ++ed;
            }
        }
        vector<edge> edges;
        int mst_cost = 0, num_taken = 0;
        if(ed == V-1) cout << "No new highways need\n";
        else {
            for(int u = 1; u <= V; ++u) {
                for(int v = u + 1; v <= V; ++v){
                    int w = distance(u, v);
                    edges.push_back({u, v, w});
                }
            }
            int size = edges.size();
            sort(edges.begin(), edges.end(), cmp);
            for(int i = 0; i < size; ++i){
                int u = edges[i].x;
                int v = edges[i].y;
                --u, --v;
                if(UF.isSameSet(u, v)) continue;
                UF.unionSet(u,v);
                cout << u + 1 << " " << v + 1 << "\n";
                ++num_taken;
                if(num_taken == V - 1) break;
            }
        }
        if(N) cout << "\n";
    }


    return 0;
}