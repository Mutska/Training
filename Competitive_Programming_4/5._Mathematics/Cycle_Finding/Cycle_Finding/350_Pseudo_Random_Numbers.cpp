#include <iostream>

using namespace std;

int Z, I, M;

int f(int x) {return (Z*x + I) % M;}

int floyd_cycle_finding(int x0){
    int t = f(x0), h = f(f(x0));
    while(t != h) {t = f(t); h = f(f(h));}
    int mu = 0; h = x0;
    while(t != h) {t  = f(t); h = f(h); ++mu;}
    int lambda = 1; h = f(t);
    while(t != h){h = f(h); ++lambda;}
    return lambda;
}


int main(){

    int L, Case = 0;
    while(cin >> Z >> I >> M >> L,(Z || I || M || L)){
        int lambda = floyd_cycle_finding(L);
        cout << "Case " << ++Case << ": " << lambda << "\n";
    }


    return 0;
}
