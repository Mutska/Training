#include <iostream>
#include <vector>
using namespace std;
int N, Case = 0;
/* vector que guarda la solucion parcial encontrada en un momento dado
   y extendiendo la solucion parcial hasta encontrar  una solucion completa*/
vector<int> solutions; 

int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

bool is_prime(int posibble_prime){
    for(int &p: primes)
        if(posibble_prime == p) return true;
    return false;
}
/*Funcion auxiliar que nos indica si el elemento actual
  puede ser considerado como parte de la solucion */
bool canAdd(int n) { 
    for(auto &s: solutions)
        if(s == n) return false;
    int possible_prime = n + solutions.back();
    if(is_prime(possible_prime)) return true;
    return false;
}

void backtrack() {
    if(solutions.size() == N) { //Verificamos si ya encontramos una solucion
        int check = solutions.back() + 1;
        if(!(is_prime(check))) return;
        cout << solutions[0];
        for(int i = 1; i < N; ++i) cout << " " << solutions[i];
        cout << "\n";
    }
    for(int i = 2; i <= N; ++i) { // Recorremos el espacio de desiciones
        if(canAdd(i)){ 
            solutions.push_back(i); // Metemos el elemento actual
            backtrack();           // Hacemos recursion
            solutions.pop_back(); // Sacamos el elemento 
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 0;
    while(cin >> N) {
        if (n > 0) cout << "\n";
        ++n;
        solutions.push_back(1);
        cout << "Case " << ++Case << ":\n";
        backtrack();
        solutions.clear();
    }

    return 0;
}