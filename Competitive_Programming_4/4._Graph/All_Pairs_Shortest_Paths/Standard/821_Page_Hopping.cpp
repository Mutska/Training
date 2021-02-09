#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstring>

using namespace std;
 
const int INF = 1e9; 



int AM[110][110];
bool taken[110];


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   string line;
   int Case = 0;
    while(getline(cin, line)){
        stringstream ss(line);
        int u,  v;
        ss >> u >> v;
        if(u == 0 && v == 0) break;
        memset(taken, 0, sizeof taken);
        for(int  i = 0; i < 100; ++i){
            for(int j = 0; j < 100; ++j) AM[i][j] = INF;
            AM[i][i] = 0;
        }
        AM[u-1][v-1]  = 1;
        taken[u-1] = 1; taken[v-1] = 1;
        while(ss >> u >> v){
            if(u == 0 && v == 0) break;
            AM[u-1][v-1]  = 1;
            taken[u-1] = 1; taken[v-1] = 1;
        }
        for(int k = 0; k < 100; ++k){
            for(int u = 0; u < 100; ++u)
                for(int v = 0; v < 100; ++v)
                    AM[u][v] = min(AM[u][v], AM[u][k] + AM[k][v]);
        }
        double average = 0;
        double total_pairs = 0;
        for(int u = 0; u < 100; ++u) {
           for(int v = 0; v < 100; ++v) {
               if(u == v) continue;
               if(taken[u] && taken[v] && AM[u][v] != INF) {
                   average += AM[u][v];
                   ++total_pairs;
               }
            }
        }
        cout << "Case " << ++Case << ": average length between pages = ";
        cout << setprecision(3) << fixed << average / total_pairs << " clicks\n";
    }
    return 0;
}