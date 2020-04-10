#include <iostream>
#include <cmath>
using namespace std;

//Check Neckclace second input in Debug because break this code, although uva judge AC.

int  main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Vt, Vo, Discs;
    double length, max_length, D, V,  constant = 0.3;
    while(cin >> Vt >> Vo, (Vt || Vo)) {
       max_length = 0, Discs = 0;
       for(int i = 1; ; i++) {
           V = (double) Vt / i;
           if(V <= Vo) break;
           D = constant*sqrt(V-Vo);
           length = D*i;
           if(length >= max_length) {
               if(fabs(max_length - length)  < 1e-9) {
                    Discs = 0;
                    break;
               }
               max_length = length;
               Discs = i;
           }
       } 
        cout << Discs << "\n";

    }


    return 0;
}