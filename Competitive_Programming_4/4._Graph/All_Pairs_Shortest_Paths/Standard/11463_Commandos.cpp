#include <iostream>
#include <vector>

using namespace std;
 
const int INF = 1e9; 
const int MAX_V = 110;



int AM[MAX_V][MAX_V];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N, R, s, d, Case = 0;
    cin >> T;
    while(T--){
        cin >> N >> R;
        for(int u = 0; u < N; ++u){
            for(int v = 0; v < N; ++v)
                AM[u][v] = INF;
        AM[u][u] = 0;
        }
        int u, v;
        for(int i = 0; i < R; ++i){
            cin >> u >> v;
            AM[u][v] = 1;
            AM[v][u] = 1;
        }
        for(int k = 0; k < N; ++k)
            for(int u = 0; u < N; ++u)
                for(int v = 0; v < N; ++v)
                    AM[u][v] = min(AM[u][v], AM[u][k] + AM[k][v]);

        cin >> s >> d;
        int minimum = 0;
        for(int i = 0; i < N; ++i){
            if(AM[s][i] != INF && AM[i][d] != INF)
                minimum = max(minimum, AM[s][i] + AM[i][d]);
        }

        cout << "Case " << ++Case << ": " << minimum << "\n";



    }






    return 0;
}