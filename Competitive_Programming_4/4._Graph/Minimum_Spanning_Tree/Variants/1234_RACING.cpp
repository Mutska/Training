#include <vector>
#include <iostream>
#include <tuple>
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



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, c = 0;
    while(cin >> N, N){
        while(N--){
        int V, E;
        cin >> V >> E;
        vector<tuple<int, int, int>> EL;
        UnionFind UF(V);
        int u, v, w, total_cost = 0;
        while(E--){
            cin >> u >> v >> w;
            EL.push_back({w,u,v});
            total_cost += w;
        }
        sort(EL.rbegin(), EL.rend());
        int mst_cost = 0, num_taken = 0, size = EL.size();
        for(int i = 0; i < size; ++i){
            int w = get<0>(EL[i]);
            int u = get<1>(EL[i]);
            int v = get<2>(EL[i]);
            --u, --v;
            if(UF.isSameSet(u, v)) continue;
            mst_cost += w;
            UF.unionSet(u,v);
            ++num_taken;
            if(num_taken == V - 1) break;
        }
        cout << total_cost - mst_cost << "\n";
        }
    }


    return 0;
}