#include <iostream>
#include <cstring>


using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, K, N, m = 0;
    while(cin >> n ){
        long long C = 1;
        if(m > 0) cout << "\n";
        ++m;
        K = n;
        N = 2*n;
        for(int i = 0; i < K;++i){
            C *= (N - i);
            C /= (1 + i);
        }
        long long Cat = C / ((long long ) n + 1);
        cout << Cat << "\n";
    }



    return 0;
}