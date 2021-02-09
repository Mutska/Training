#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;
typedef vector<int> vi;

vi match, vis;                                   // global variables
vector<vi> AL;

int Aug(int L) {
  if (vis[L]) return 0;                          // L visited, return 0
  vis[L] = 1;
  for (auto &R : AL[L])
    if ((match[R] == -1) || Aug(match[R])) {
      match[R] = L;                              // flip status
      return 1;                                  // found 1 matching
    }
  return 0;                                      // no matching
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, Case = 0;
    cin >> T;
    while(T--){
        int bolts, nuts;
        cin >> bolts >> nuts;
        int V  = bolts + nuts;
        AL.assign(V, {});
        int edge;
        for(int  u = 0; u < bolts; ++u){
            for(int v = bolts; v < V; ++v ){
                cin >> edge;
                if(edge == 1) AL[u].push_back(v);
            }
        }
        unordered_set<int> free_vertex;
        int left_vertex = bolts;
        for(int L = 0; L < left_vertex; ++L) free_vertex.insert(L);
        match.assign(V, -1);
        int MCBM = 0;
        for(auto &f: free_vertex){
            vis.assign(left_vertex, 0);
            MCBM += Aug(f);
        }
        cout << "Case " << ++Case << ": a maximum of " << MCBM << " nuts and bolts can be fitted together\n";

    }
  return 0;
}