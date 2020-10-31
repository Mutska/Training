#include <iostream>
#include <vector>
#include <map>

using namespace std;
int N = 4;
struct bishop{
    int x, y, ahead;
};

int  lineCounter; 
//Lista de posibles posiciones de cada alfil.
vector<bishop> posiciones;//Espacio de desiciones
//La solucion parcial que estamos explorando
vector<bishop> solucion; //Soluciones parciales

//Verifico si previamente hay otros alfiles en la misma diagonal
bool canPlace(bishop r) {
    int x = r.x;
    int y = r.y;
    for(int prev = 0; prev < (int) solucion.size(); ++prev) {
        int px = solucion[prev].x;
        int py = solucion[prev].y;
        if(abs(px - x) == abs(py - y)) return false;
    }
    return true;
}
//Hace backtrack buscando en las posiciones
//empezando con el indice inicio
void backtrack(int inicio, int diagonal) {
    if(solucion.size() == 4) { //Si c == 4 ya encontre una solucion y la reporto
        cout << ++lineCounter;
        for(int j = 0; j < (int) solucion.size(); ++j)
            cout << " (" << solucion[j].x << "," << solucion[j].y << ")";
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
            int R;
            if(diagonal > N) R = r - posiciones[r].ahead + (2*N - diagonal);
            else R = r - posiciones[r].ahead + diagonal;
            backtrack(R, diagonal + 1); //hago recursion
            //Saca la posicion que acabas de agregar
            //Ya que exploraste todas las posibilidades
            solucion.pop_back();
        }
    }
}

int main() {
    //Lleno mis posiciones aqui
    for(int k = 0; k <= 6; ++k){
        bishop B;
        int ahead = -1;
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                if(i + j == k) B.x = i, B.y = j, B.ahead = ++ahead, posiciones.push_back(B);
    }
    for(auto &p: posiciones) cout << "(" <<  p.x << "," << p.y << "," << p.ahead <<  ")\n";
    cout << posiciones.size() << "\n";
    lineCounter = 0;
    backtrack(0, 1);
    return 0;
}

