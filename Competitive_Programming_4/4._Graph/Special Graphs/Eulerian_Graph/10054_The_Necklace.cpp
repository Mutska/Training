#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

//Por mejorar en vez de map usar arreglo de dos dimensione

vi vertex;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
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

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};


int N;
map<pair<int, int>, int> used;
vector<vi> AL;                                   

vi hierholzer(int s) {
  vi ans, idx(50, 0), st;
  st.push_back(s);
  while (!st.empty()) {
    int u = st.back();
    if (idx[u] < (int)AL[u].size()) {            
      int v = AL[u][idx[u]];
      int forward  = used[{u,v}];
      int backward = used[{v,u}];
      if(forward == 0 || backward == 0) {
          ++idx[u];
          continue;
      }
      if(u != v) used[{u,v}]--;
      used[{v,u}]--;
      st.push_back(v);
      ++idx[u];
    }
    else {
      ans.push_back(u);
      st.pop_back();
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

bool check_component(UnionFind &forest){
  int n = vertex.size();
  for(int i = 0; i < n; ++i)
    for(int j = i + 1; j < n; ++j)
      if(!forest.isSameSet(vertex[i], vertex[j])) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, Case = 0;
  cin >> T;
  while(T--){
    cout << "Case #" << ++Case <<"\n";
    int  u, v;
    vi degree(50, 0);
    UnionFind forest(50);
    used.clear();
    vertex.clear();
    cin >> N;
    AL.assign(50,{});
    int s = INT32_MAX;
    for(int i = 0; i < N; ++i){
        cin >> u >> v;
        --u, --v;
        forest.unionSet(u,v);
        vertex.emplace_back(u);
        vertex.emplace_back(v);
        s = min(s, min(u,v));
        ++degree[u];
        ++degree[v];
        if(u != v) AL[u].emplace_back(v);
        AL[v].emplace_back(u);
        if(u != v) used[{u,v}]++;
        used[{v,u}]++;
    }
    bool one_component = check_component(forest);
    if(any_of(degree.begin(), degree.end(), [](int i ){return i % 2;}) || one_component){
      cout << "some beads may be lost\n";
    } else {
      vi ans = hierholzer(s);
      int s = ans.size();
      for(int i = 0; i < s - 1; ++i)
        cout << ans[i] + 1 << " "  << ans[i + 1] + 1 << "\n";
    }
    if(T) cout << "\n";
    
  }
  return 0;  
}