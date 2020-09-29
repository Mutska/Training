#include <iostream>
#include <string>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m){
        if(n == 1 && m == 1) break;
        string a = "";
        int L1 = 0, L2 = 1;
        int R1 = 1, R2 = 0;
        int C1 = 1, C2 = 1;
        while(1) {
            if(C1 == n && C2 == m) break;
            if(C1*m < C2*n){
                a.append("R");
                L1 = C1; 
                L2 = C2;
            } else {
                a.append("L");
                R1 = C1;
                R2 = C2;
            }
            C1 = L1 + R1;
            C2 = L2 + R2;
        }
        cout << a << "\n";
    }




    return 0;
}