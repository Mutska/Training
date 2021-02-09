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

    int N, c = 0;
    while(cin >> N){
        if(cin.eof()) break;
        else if(c > 0) cout << "\n";
        ++c;
        vector<tuple<int, int, int>> EL;
        UnionFind UF(N);
        int u, v, w;
        int minimum_cost_1 = 0;
        for(int i = 0; i < N - 1; ++i){
            cin >> u >> v >> w;
            minimum_cost_1 += w;
        }
        int k;
        cin >> k;
        while(k--){
            cin >> u >> v >> w;
            EL.push_back({w,u,v});
        }
        int m;
        cin >> m;
        while(m--){
            cin >> u >> v >> w;
            EL.push_back({w,u,v});
        }
        sort(EL.begin(), EL.end());
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
            if(num_taken == N - 1) break;
        }
        cout << minimum_cost_1 << "\n";
        cout << mst_cost << "\n";
    }


    return 0;
}