#include <iostream>
#include <vector>
#include <map>

using namespace std;

int  lineCounter; 
vector<pair<int, int>> pos;//Espacio de desiciones
vector<pair<int,int>> sol; //Soluciones parciales
map<pair<int, int>, int> M;
pair<int, int> last = {-1, -1};
pair<int, int> neutro = last;
//Verifico si previamente hay otros alfiles en la misma diagonal
bool canPlace(pair<int, int> r) {
    for(int prev = 0; prev < (int) sol.size(); ++prev)
        if((abs(sol[prev].first - r.first) == abs(sol[prev].second-r.second)))
            return false;
    return true;
}

void backtrack(int c, int R) {
    cout << "current c is: " << c << "\n";
    if(!sol.empty()) cout << "with: " << sol.back().first << "," << sol.back().second << "\n";
    if(c == 4) { //Si c == 4 ya encontre una solucion
        cout << ++lineCounter;
        for(int j = 0; j < (int) sol.size(); ++j)
            cout << " (" << sol[j].first << "," << sol[j].second << ")";
        cout << "\n";
        cout << "pop: " << sol.back().first << "," << sol.back().second << "\n";
        last = sol.back();
        sol.pop_back();
        cout << "remains: " << sol.back().first << "," << sol.back().second << "\n";
        return;
    }
   
    for(int r = R; r < 16; ++r) { 
        if(canPlace(pos[r])) {  //Si puedo agregar r a mi solucion parcial
            sol.push_back(pos[r]); //la agrego
            cout << "r is: " << r << "\n";
            cout << "pushing: " << pos[r].first << "," << pos[r].second << "\n";
            cout << "with c == " << c << "\n";
            backtrack(c + 1, r + 1); //hago recursion
        }
    }
}

int main() {
    int A  = -1;
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j) { 
            pos.push_back({i, j});
            pair<int, int> m = {i, j};
             M[m] = ++A;
        }
    for(auto &p: pos) cout << "(" <<  p.first << "," << p.second << ")\n";
    lineCounter = 0;
    backtrack(0, 0);
    return 0;
}

