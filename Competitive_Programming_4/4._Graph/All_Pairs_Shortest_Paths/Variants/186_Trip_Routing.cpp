#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <unordered_map>
#include <string>



using namespace std;


const int INF = 1e9; 
int AM[110][110];
int p[110][110];
     
string path;
void print_path(int i, int j){
    if(i != j) {
        print_path(i, p[i][j]);
    }
    string city = to_string(j);
    city += " ";
    path += city;
}    
     
     
     
     
     
     
     
int main(){

    string line;
    unordered_map<string, int> mapper;
    unordered_map<int, string> rmapper;
    map<pair<string, string>, string> routes;
    for(int  i = 0; i < 100; ++i){
         for(int j = 0; j < 100; ++j) {
            AM[i][j] = INF;
            p[i][j] = i;
        }
        AM[i][i] = 0;
    }
    int index = 0;
    pair<string, string> route1;
    pair<string, string> route2;
    string name;
    while(getline(cin, line)){
        if(line.empty()) break;
        stringstream ss(line);
        string token, city1, city2;
        int t = 1;
        while(getline(ss, token, ',')){
            if(t == 1) {
                city1 = token;
                if(mapper.find(token) == mapper.end()){
                    mapper[token]  = index;
                    rmapper[index] = token;
                    ++index;
                }
                ++t;
            } else if(t == 2) {
                city2 = token;
                if(mapper.find(token) == mapper.end()){
                    mapper[token]  = index;
                    rmapper[index] = token;
                    ++index;
                }
                ++t;
            } else if(t == 3){
                route1.first = city1;
                route1.second = city2;
                route2.first = city2;
                route2.second = city1;
                name = token;
                ++t;
            } else if(t == 4){
               int w = stoi(token);
               int u = mapper[city1];
               int v = mapper[city2];
               if(AM[u][v] > w || AM[v][u] > w){
                    routes[route1] = name;
                    routes[route2] = name;
                    AM[u][v] = w;
                    AM[v][u] = w;
               }
            }
        }
    }

    
    for(int k = 0; k < 100; ++k){
        for(int u = 0; u < 100; ++u)
            for(int v = 0; v < 100; ++v){
                if(AM[u][k] + AM[k][v] < AM[u][v]) {
                    AM[u][v] = AM[u][k] + AM[k][v];
                    p[u][v] = p[k][v];
                }
            }
    }
    while(getline(cin, line)){
        stringstream ss(line);
        string token;
        int u , v, t = 1;
        while(getline(ss, token, ',')){
           if(t == 1) {
               u = mapper[token];
               ++t;
           } else {
               v = mapper[token];
           }
        }
        path = "";
        int min_cost = AM[u][v];
        print_path(u, v);
        cout << "\n\n";
        stringstream cities(path);
        cout << setw(21) << left << "From";
        cout << setw(21) << left << "To";
        cout << setw(11) << left << "Route";
        cout << setw(5) << left << "Miles";
        cout << "\n";
        cout << "-------------------- -------------------- ---------- -----\n";
        string city1, city2;
        cities >> u;
        while(cities >> v){
            city1 = rmapper[u];
            city2 = rmapper[v];
            cout << setw(21) << left << city1;
            cout << setw(21) << left << city2;
            cout << setw(11) << left << routes[{city1, city2}];
            cout << setw(5) << right << AM[u][v];
            cout << "\n";
            u = v;
        }
        cout << setw(59)  << right << "-----\n";
        cout << "                                          ";
        cout << setw(11) << left << "Total";
        cout << setw(5) << right << min_cost << "\n";
    }

    return 0;
}