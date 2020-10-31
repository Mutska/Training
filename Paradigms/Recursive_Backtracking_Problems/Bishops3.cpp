#include <iostream>
#include <vector>
#include <map>

using namespace std;

int  lineCounter; 
//Lista de posibles posiciones de cada alfil.
vector<pair<int, int>> posiciones;//Espacio de desiciones
//La solucion parcial que estamos explorando
vector<pair<int,int>> solucion; //Soluciones parciales

//Verifico si previamente hay otros alfiles en la misma diagonal
bool canPlace(pair<int, int> &r) {
    for(int prev = 0; prev < (int) solucion.size(); ++prev)
        if((abs(solucion[prev].first - r.first) == abs(solucion[prev].second-r.second)))
            return false;
    return true;
}
//Hace backtrack buscando en las posiciones
//empezando con el indice inicio
void backtrack(int inicio) {
    cout << "current inicio is: " << inicio << "\n";
    if(solucion.size() == 4) { //Si c == 4 ya encontre una solucion y la reporto
        cout << ++lineCounter;
        for(int j = 0; j < (int) solucion.size(); ++j)
            cout << " (" << solucion[j].first << "," << solucion[j].second << ")";
        cout << "\n";
        return;
    }
    //Ya no hay mas posiciones que agregar.
    if(inicio == posiciones.size()) return;
    //Prueba con todas las siguientes posibles posiciones
    for(int r = inicio; r < 16; ++r) { 
        if(canPlace(posiciones[r])) {  //Si puedo agregar este alfil a mi solucion parcial
            //Agrega y haz backtrack empezando mas adelante
            solucion.push_back(posiciones[r]); //la agrego
            backtrack(r + 1); //hago recursion

            //Saca la posicion que acabas de agregar
            //Ya que exploraste todas las posibilidades
            solucion.pop_back();
        }
    }
}

int main() {
    //Lleno mis posiciones aqui
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)  
            posiciones.push_back({i, j});
    for(auto &p: posiciones) cout << "(" <<  p.first << "," << p.second << ")\n";
    lineCounter = 0;
    backtrack(0);
    return 0;
}

