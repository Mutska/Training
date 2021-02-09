#include <iostream>
#include <iomanip>

using namespace std;


const int INF = 1e9;

int countries[20][20];




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int u ,v, n, V, Set = 0, c = 0;
    while(1){
        V = 18;
        if(c > 0){
            cout << "\n";
        }
        ++c;
        cin >> n;
        if(cin.eof())break;
        for(int u = 0; u < 20; ++u){
            for(int v = 0; v < 20; ++v)
                countries[u][v] = INF;
            countries[u][u] = 0;
        }
        for(int i = 0; i < n; ++i) {
            cin >> v;
            --v;
            countries[0][v] = 1;
            countries[v][0] = 1;
        }
        int u = 0;
        while(V--){
            cin >> n;
             ++u;
            for(int i = 0; i < n; ++i) {
                cin >> v;
                --v;
                countries[u][v] = 1;
                countries[v][u] = 1;
            }
        }
        for(int k = 0; k < 20; ++k)
            for(int u = 0; u <20; ++u)
                for(int v = 0; v < 20; ++v)
                    countries[u][v] = min(countries[u][v], countries[u][k]+ countries[k][v]);
        int n;
        cin >> n;
        cout << "Test Set #" << ++Set << "\n";
        while(n--){
            cin >> u >> v;
            cout << setw(2) << right << u;
            cout << " to ";
            cout << setw(2) << right << v << ": ";
            cout << left << countries[u-1][v-1] << "\n";
        }
    }




}