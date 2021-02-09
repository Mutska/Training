#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>


using namespace std;
const int INF = 1e9;
int AM[60][60];




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int P, R, Net = 0;
    while(cin >> P >> R, (P || R)){
        for(int i = 0; i < 50; ++i){
            for(int j = 0; j < 50; ++j) AM[i][j] = INF;
            AM[i][i] = 0;
        }
        string line;
        string A, B;
        int index = 0;
        unordered_map<string, int> mapper;
        while(R--){
                cin >> A >> B;
                if(mapper.find(A) == mapper.end()){
                    mapper[A] = index;
                    ++index;
                }
                if(mapper.find(B) == mapper.end()){
                    mapper[B] = index;
                    ++index;
                }
                int u = mapper[A];
                int v = mapper[B];
                AM[u][v] = 1;
                AM[v][u] = 1;
        }
        for(int k = 0; k < P; ++k)
            for(int u = 0; u < P; ++u)
                for(int  v = 0; v < P; ++v)
                    AM[u][v] = min(AM[u][v], AM[u][k] + AM[k][v]);
        int maximum = INT32_MIN;
        for(int i = 0; i < P; ++i)
            for(int j = i + 1; j < P; ++j)
                maximum = max(maximum, AM[i][j]);
        if(maximum != INF) cout << "Network " << ++Net << ": "  << maximum << "\n\n";
        else cout << "Network " << ++Net << ": DISCONNECTED\n\n";


    }


    return 0;
}