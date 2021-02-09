#include <iostream>


using namespace std;


long long C[105][105];
//C[4][3] 

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    C[0][0] = 1;
    for(int n = 1; n <= 100; ++n){
        C[n][0] = C[n][n] = 1;
        for(int k = 1; k < n; ++k){
            C[n][k] = C[n-1][k-1] + C[n-1][k];
        }
    }
    cout << C[80][40] << "\n";


//   int n, m;
//   while(cin >> n >> m, (n || m)){
//       cout << n << " things taken " << m << " at a time is " << C[n][m] << " exactly.\n";
//   }



    return 0;
}